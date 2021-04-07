#include <bits/stdc++.h>

using namespace std;
const int N=5e3+110;
int n,m,head[N],cnt,dfn[N],fa[N],tim,low[N],sta[N],top,ans[N];
int maxx=0,idx=0,idy=0;
bool vis[N],f=0;
vector<int >ve[N];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node
{
	int nt,to;
}edge[N*2];

void add(int x,int y)
{
	edge[++cnt]=(node){head[x],y};head[x]=cnt;
	edge[++cnt]=(node){head[y],x};head[y]=cnt;
}
struct ask
{
	int u,v;
	bool operator < (const ask &a)const 
	{
		return u==a.u?v<a.v:u<a.u;
	}
}q[N];
void dfs(int x)
{	
	ans[++tim]=x;
	vis[x]=1;
	for(int i=0;i<ve[x].size();i++)
	{
		if(ve[x][i]==fa[x]||vis[ve[x][i]])continue;
		fa[ve[x][i]]=x;
		dfs(ve[x][i]);
	}
}
void dfs2(int x,int fa1)
{
	ans[++tim]=x;
	vis[x]=1;
	for(int i=0;i<ve[x].size();i++)
	{
		if(ve[x][i]==fa1)continue;
		if(ve[x][i]<ve[1][1])
		  dfs2(ve[x][i],x);
		else return;
	}
}
void dfs3(int x,int fa1)
{
   if(vis[x])return;
	ans[++tim]=x;
	for(int i=0;i<ve[x].size();i++)
	{
		if(ve[x][i]==fa1)continue;
		 dfs3(ve[x][i],x);
	
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	if(m==n-1)
	{
		for(int i=1;i<=m;i++)
		{
			int x,y;
			x=read();y=read();
			ve[x].push_back(y);
			ve[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
		sort(ve[i].begin(),ve[i].end());
		fa[1]=0;
		dfs(1);
		for(int i=1;i<=tim;i++)
		printf("%d ",ans[i]);
	}
	else 
    {
	    for(int i=1;i<=m;i++)
		{
			int x,y;
			x=read();y=read();
			ve[x].push_back(y);
			ve[y].push_back(x);
		}
		ans[++tim]=1;
		int xx=min(ve[1][0],ve[1][1]);
		int yy=max(ve[1][0],ve[1][1]);
	   dfs2(xx,1);
	   dfs3(yy,1);
	   for(int i=1;i<=tim;i++)
		printf("%d ",ans[i]);
	}
	
	return 0;
}
