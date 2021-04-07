#include<cstdio>
#include<cstdlib>
#include<cstring>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int n,m;
int read(){
	char ch=getchar();int f=1,x=0;
	while(ch<'0' || ch>'9'){ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int pow(int a,int b){
	int ans=1;
	for(int i=1;i<=b;i++)ans*=a;
	return a;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	if(m>n){
		int t=n;
		n=m;m=t;
	}
	if(m==1){
		printf("%d",pow(2,n));
		return 0;
	}
	if(m==2){
		int ans=12;
		for(int i=3;i<=n;i++){
			ans*=3;
		}
		printf("%d",ans);
		return 0;
	}
}
