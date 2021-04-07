#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
inline int read()
{
	int k=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+c-'0';return f*k;
}
const ll inf=1ll<<60;
const int N=200055;
int n,m,val[N];
int x[N],y[N],z[N],w[N];
int tot,to[N],nextt[N],head[N];
ll f[N][2],g[N][2];
char s[5];
void add(int a,int b)
{
	to[++tot]=b;
	nextt[tot]=head[a];
	head[a]=tot;
}
void dfs(int u,int fa,int opt)
{
	f[u][0]=0;f[u][1]=val[u];
	for(int i=head[u];i;i=nextt[i])
		if(to[i]!=fa)
		{
			dfs(to[i],u,opt);
			f[u][0]+=f[to[i]][1];
			f[u][1]+=min(f[to[i]][1],f[to[i]][0]);
		}
	if(x[opt]==u) f[u][y[opt]^1]=inf;
	if(z[opt]==u) f[u][w[opt]^1]=inf;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int a,b;
	n=read();m=read();scanf("%s",s);
	for(int i=1;i<=n;i++)
		val[i]=read();
	for(int i=1;i<n;i++)
		a=read(),b=read(),add(a,b),add(b,a);
	for(int i=1;i<=m;i++)
	{
		x[i]=read(),y[i]=read(),z[i]=read(),w[i]=read();
		if(x[i]>z[i]) swap(x[i],z[i]),swap(y[i],w[i]);
	}
	if(n<=2000&&m<=2000)
	{
		for(int i=1;i<=m;i++)
		{
			dfs(1,0,i);
			if(min(f[1][0],f[1][1])<inf)
				printf("%lld\n",min(f[1][0],f[1][1]));
			else puts("-1");
		}	
		return 0;
	}
	if(s[1]=='2')
	{
		for(int i=1;i<=n;i++)
		{
			f[i][0]=f[i-1][1];
			f[i][1]=min(f[i-1][1],f[i-1][0])+val[i];
		}
		for(int i=n;i;i--)
		{
			g[i][0]=g[i+1][1];
			g[i][1]=min(g[i+1][1],g[i+1][0])+val[i];
		}
		for(int i=1;i<=m;i++)
		{
			if(y[i]==0&&w[i]==0) 
				puts("-1");
			else printf("%lld\n",f[x[i]][y[i]]+g[z[i]][w[i]]);
		}
		return 0;
	}
	else 
	{
		f[1][1]=val[1];f[1][0]=inf;
		for(int i=2;i<=n;i++)
		{
			f[i][0]=f[i-1][1];
			f[i][1]=min(f[i-1][1],f[i-1][0])+val[i];
		}
		for(int i=n;i>1;i--)
		{
			g[i][0]=g[i+1][1];
			g[i][1]=min(g[i+1][1],g[i+1][0])+val[i];
		}
		g[1][0]=inf;g[1][1]=min(g[2][1],g[2][0])+val[i];
		for(int i=1;i<=m;i++)
		{
			ll res;
			if(w[i]==1)
				res=min(f[z[i]-1][0],f[z[i]-1][1])+g[z[i]][w[i]];
			else res=f[z[i]-1][1]+g[z[i]][w[i]];
			if(res>inf) puts("-1");
			else printf("%lld\n",res);
		}
	}
	return 0;
}
