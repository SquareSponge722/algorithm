#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
inline int read()
{
	int k=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+c-'0';return f*k;
}
const int N=20055;
int n,m,tot,sum;
int x[N],y[N],fa[N],dep[N],tag[N],vis[N];
int as[N],res[N];
vector<int> G[N]; 
void add(int a,int b)
{
	G[a].push_back(b);
	G[b].push_back(a);
}
void dfs(int u,int f)
{
//	cout<<u<<" "<<f<<endl;
	res[++sum]=u;vis[u]=1;
	int cnt=0;
	for(int i=0;i<G[u].size();i++)
		if(G[u][i]!=f)
		{ 
			if(vis[G[u][i]])
				{sum=0;break;}
			dfs(G[u][i],u);
		}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	n=read();m=read();
	if(m==n-1)
	{
		for(int i=1;i<=m;i++)
		a=read(),b=read(),add(a,b);
		for(int j=1;j<=n;j++)
			sort(G[j].begin(),G[j].end());
		dfs(1,0);
		for(int i=1;i<n;i++)
			printf("%d ",res[i]);
		printf("%d\n",res[n]);
		return 0;
	}
	for(int i=1;i<=n;i++)
		x[i]=read(),y[i]=read();
	memset(as,0x3f,sizeof(as));
	for(int i=1;i<=n;i++)
	{
		sum=0;tot=0;
		for(int j=1;j<=n;j++)
			G[j].clear(),vis[j]=0;
		for(int j=1;j<=n;j++)
			if(j!=i) 
				add(x[j],y[j]);
		for(int j=1;j<=n;j++)
			sort(G[j].begin(),G[j].end());
		dfs(1,0);if(sum<n) continue;
		for(int j=1;j<=n;j++)
		{
			if(res[j]<as[j])
			{
				for(int k=1;k<=n;k++)
					as[k]=res[k];
				break;
			}
			if(res[j]>as[j]) break;
		}
	}
	for(int i=1;i<n;i++)
		printf("%d ",as[i]);
	printf("%d\n",as[n]);
	return 0;
}
