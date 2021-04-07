#include<cstdio>
#include<cmath>
#define ll long long
#define FOR(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
int p[100005];
int fa[5005][105],num[5005];
int ans;

int read()
{
	int p=1,q=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0'&&c<='9'){q=q*10+c-'0';c=getchar();}
	return p*q;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();
	int u,v,a,b,x,y;
	char c=getchar();
	int _type=read();
	FOR(i,1,n)p[i]=read();
	FOR(i,1,n-1){
		u=read();v=read();
		fa[u][++num[u]]=v;
		fa[v][++num[v]]=u;
	}
	FOR(i,1,m){
		ans=0;
		a=read();x=read();
		b=read();y=read();
		if(abs(a-b)==1&&x==y==0){printf("-1\n");continue;}
	}
	return 0;
}
