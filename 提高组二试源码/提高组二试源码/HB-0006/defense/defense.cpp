#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=2e3+10;
typedef long long ll;
vector<int>e2[maxn];
int e[maxn][maxn],vis[maxn],dep[maxn],maxdep=0,vis2[maxn];
ll p[maxn];
/*struct node
{
	int a,x,b,y;
	bool operator<(const node &ot)const
	{

	}
}q[maxn];*/
queue<int>q;
void work()
{
	q.push(1);
	dep[1]=1;
	vis2[1]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		int siz=e2[now].size();
		for(int i=0;i<siz;++i)
		{
			int u=e2[now][i];
			if(vis2[u])
				continue;
			vis2[u]=1;
			dep[u]=dep[now]+1;
			maxdep=max(dep[u],maxdep);
			q.push(u);
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(e,0x3f,sizeof(e));
	char s[3];
	int n,m,u,v;
	scanf("%d%d%s",&n,&m,s);
	for(int i=1; i<=n; ++i)
		scanf("%lld",&p[i]);
	for(int i=1; i<n; ++i)
	{
		scanf("%d%d",&u,&v);
		e[u][v]=e[v][u]=1;
		e2[u].push_back(v);
		e2[v].push_back(u);
	}
	int a,x,b,y;
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(e[a][b]==1 && x==0 && y==0)
		{
			printf("-1\n");
			continue;
		}
		ll ans=0;
		memset(vis,0,sizeof(vis));
		//memset(vis2,0,sizeof(vis2));
		maxdep=0;
		if(x==1)
			vis[a]=1,ans+=p[a];
		if(y==1)
			vis[b]=1,ans+=p[b];
		if(a>b)
			swap(a,b);
		if(s[1]=='1')
		{
			memset(vis2,0,sizeof(vis2));
			work();
			for(int j=3;j<=maxdep;j+=2)
			{
				for(int k=1;k<=n;++k)
				{
					if(dep[k]==j)
					{
						if(k==b)
							continue;
						ans+=p[k];					
					}
				}
			}
			//printf("%lld\n",ans);
		}
		else
		{
			if(x==1)
			{
				if((a-1)%2==0)
				{
					for(int j=a-2; j>0; j-=2)
						ans+=p[j];
				}
				else if(a!=2)
				{
					for(int j=a-1; j>0; j-=2)
						ans+=p[j];
				}
			}
			else
			{
				for(int j=a-1; j>0; j-=2)
					ans+=p[j];
			}
			if(y==1)
			{
				if((n-b)%2==0)
				{
					for(int j=b+2; j<=n; j+=2)
						ans+=p[j];
				}
				else
				{
					for(int j=b+1; j<=n; j+=2)
						ans+=p[j];
				}
			}
			else
			{
				for(int j=b+1; j<=n; j+=2)
					ans+=p[j];
			}
			if(x==0 && y==0)
			{
				for(int j=a+1; j<=b-1; ++j)
					ans+=p[j];
			}
			else
			{
				for(int j=a+2; j<b; ++j)
					ans+=p[j];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
