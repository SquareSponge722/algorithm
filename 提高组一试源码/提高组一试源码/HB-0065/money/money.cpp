#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,n,tot=0;
int a[105];
int f[25010],prime[25010];
bool v[25010];
bool qur(){
	for(int i=1;i<=n;i++)
		if(f[i]!=0)
			return false;
	return true;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	memset(f,0,sizeof(f));
	for(int i=2;i<=200;i++){
		if(f[i]==0){
			prime[++tot]=i;
			for(int j=1;j<=tot;j++){
				f[i*prime[j]]=prime[j];
			}
		}
	}
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(qur()){
			printf("%d\n",n);
			continue;
		}
		else{
			memset(v,false,sizeof(v));
			for(int i=1;i<=n;i++)
				v[a[i]]=true;
			for(int i=n;i>=1;i--){
				v[a[i]]=false;
				for(int j=1;j<=n;j++)
					for(int k=a[n];k>=1;k--)
						v[k] |= v[k-a[j]];
			}
			int ans=0;
			for(int i=1;i<=n;i++)
				if(!v[a[i]])
					ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
