#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105,A=25005;
int n,t,a[N],f[A],ans;

int read(){
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while(t--){
		memset(f,0,sizeof(f));
		f[0]=1;
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(f[a[i]]==0) ans++;
			for(int j=0;j<=25000-a[i];j++){
				if(j+a[i]<=25000&&f[j]==1){
					f[j+a[i]]=1;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
