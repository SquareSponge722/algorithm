#include<bits/stdc++.h>
using namespace std;
const int N=50005;
const int inf=0x3f3f3f3f; 
int n,m,dis[N];
int f[5005][5005];
int vis[N]={0};
long long maxn=-1;//-1±ÜÃâ³ö¹ø
struct Node{
	int v;
	int w;
};
vector<Node>G[N];
void addedge(int u,int v,int w)//ok~
{
	G[u].push_back( (Node){	v,w } );
}
void work(int x)
{
	memset(dis,inf,sizeof(dis));
	long long ans=0;
	
	for(int i=1;i<=n;i++)	dis[i]=inf;
	dis[x]=0;
	vis[x]=1;
	int minn=inf;
	int u;
	
	for(int i=1;i<=n;i++)
	{
		if(dis[i]<minn && vis[i]==0)
		{
			minn=dis[i];
			u=i;
		}
	}
	vis[u]=1;
	int len=G[u].size();
	for(int i=0;i<len;i++)
	{
		Node t=G[u][i];
		int v=t.v,w=t.w;
		if(dis[v]>dis[u]+w && vis[v]!=true)
		{
			dis[v]=dis[u]+w;
			ans+=w;
		}
	}
	maxn=max(maxn,ans);
}

void dfs(int x)
{
	if(road==m)
	{
		minn=min(ans,minn);
		cout<<minn;
		return;
	}
	
	for(int i=0;i<G[x].size();i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			ans+=G[x][i].w;
		}
		dfs(i);
		vis[i]=0;
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j)	f[i][j]=0;
			else	f[i][j]=inf;
		}
		
	for(int i=1;i<n;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		addedge(a,b,w);
		f[a][b]=w;
	}
	if(m==1)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=m;i++)
		work(i);
	cout<<maxn<<endl;
	return 0;
}
