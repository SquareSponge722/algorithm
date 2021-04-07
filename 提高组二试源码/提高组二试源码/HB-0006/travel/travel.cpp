#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
const int INF=0x3f3f3f3f;
vector<int>e[maxn];
vector<int>e2[maxn];
int ans[maxn],tot2=1,temp[maxn][maxn];
int n,m;
stack<int>s;
int dfn[maxn],low[maxn],tot=0,cnt=0,in_s[maxn],bl[maxn],vis[maxn];
void tarjan(int x,int fa)
{
	low[x]=dfn[x]=++tot;
	s.push(x);
	in_s[x]=1;
	int siz=e[x].size();
	for(int i=0;i<siz;++i)
	{
		int u=e[x][i];
		if(u==fa)
			continue;
		if(!dfn[u])
		{
			tarjan(u,x);
			low[x]=min(low[x],low[u]);
		}
		else if(in_s[u])
			low[x]=min(low[x],dfn[u]);
	}
	if(dfn[x]==low[x])
	{
		++cnt;
		while(!s.empty())
		{
			int now=s.top();
			s.pop();
			in_s[now]=0;
			bl[now]=cnt;
			if(now==x)
				return ;
		}
	}
}
void dfs(int x,int fa)
{
	int siz=e[x].size(),cnt2=0;
	for(int i=0;i<siz;++i)
	{
		int u=e[x][i];
		if(u==fa)
			continue;
		temp[x][++cnt2]=u;
	}
	sort(temp[x]+1,temp[x]+cnt2+1);
	for(int i=1;i<=cnt2;++i)
	{
		ans[++tot2]=temp[x][i];
		dfs(temp[x][i],x);
	}
}
void dfs2(int x,int fa)
{
	int siz=e2[x].size(),cnt2=0;
	for(int i=0;i<siz;++i)
	{
		int u=e2[x][i];
		if(u==fa)
			continue;
		temp[x][++cnt2]=u;
	}
	sort(temp[x]+1,temp[x]+cnt2+1);
	for(int i=1;i<=cnt2;++i)
	{
		if(vis[temp[x][i]])
			continue;
		ans[++tot2]=temp[x][i];
		vis[temp[x][i]]=1;
		dfs2(temp[x][i],x);
	}
}
inline void rbuild()
{
	for(int i=1;i<=n;++i)
	{
		int siz=e[i].size();
		for(int j=0;j<siz;++j)
		{
			int u=e[i][j];
			if(bl[i]!=bl[u])
			{
				e2[bl[i]].push_back(bl[u]);
				e2[bl[u]].push_back(bl[i]);
			}
		}
	}
}
int main()
{
	//printf("%lld\n",sizeof(temp)/(1024*1024));
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	//vis[1]=1;
	if(m==n-1)
	{
		ans[1]=1;
		dfs(1,0);
		for(int i=1;i<=tot2;++i)
			printf("%d ",ans[i]);
	}
	else
	{
		tarjan(1,0);
		/*for(int i=1;i<=n;++i)
			printf("%d\n",bl[i]);*/
		ans[1]=1;
		rbuild();	
		vis[1]=1;
		dfs2(1,0);
		for(int i=tot2;i>0;--i)
		{
			for(int j=1;j<=n;++j)
				if(bl[j]==ans[i])
					printf("%d ",j);
		}
	}
	return 0;
}
