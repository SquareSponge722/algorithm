#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n,a[101],sum,minx,ans;
bool f[25002];
int read()
{
	int s=0;bool f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=0;ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		s=s*10+ch-'0';ch=getchar();
	}
	return f?s:-s;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++){
		n=read();ans=n;
		for(int j=1;j<=n;j++){
			a[j]=read();if(a[j]==1)f[0]=1;
		}
		if(f[0]){cout<<1<<endl;continue;}
		sort(a+1,a+n+1);f[a[1]]=1;
		for(int k=2;k<=n;k++){
			if(a[k]%a[1]!=0){
				minx=k;break;
			}
			ans--;
		}
		if(ans==1){
			cout<<ans<<endl;continue;
		}
		sum=a[minx]*a[1]-a[1]-a[minx];
		for(int k=minx+1;k<=n;k++){
			if(a[k]>sum)ans--;
			else{
				for(int l=0;l*a[minx]<a[k];l++)
				{
					if((a[k]-l*a[minx])%a[1]==0){
						ans--;break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
