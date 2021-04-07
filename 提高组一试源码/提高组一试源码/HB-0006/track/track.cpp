#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=5e4+10;
const int INF=0x3f3f3f3f;
struct node
{
	ll l;
	int u;
	node (ll len,int uu)
	{
		l=len,u=uu;
	}
	/*bool operator<(const node &ot)const
	{
		return l<ot.l;
	}*/
};
/*struct node2
{
	int st;
	ll v;
	node2(int st1,ll v1)
	{
		st=st1,v=v1;
	}
	bool operator < (const node2 & ot)const
	{
		return v<ot.v;		
	}
};*/
vector<node>e[maxn];
int temp=1;
ll dis[maxn],ans=INF;
priority_queue<ll>q_max;
priority_queue<ll,vector<ll>,greater<ll> >q_min;
priority_queue<ll,vector<ll>,greater<ll> >q2_min;
/*priority_queue<node>q;
void dijk()
{
	
}*/
void dfs(int x,int fa)
{
	int siz=e[x].size();
	for(int i=0;i<siz;++i)
	{
		node u=e[x][i];
		if(u.u==fa)
			continue ;
		if(dis[u.u]<dis[x]+u.l)
			dis[u.u]=dis[x]+u.l;
		if(dis[temp]<dis[u.u])
			temp=u.u;
		dfs(u.u,x);
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,u,v;
	ll len,ans2=INF;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i)
	{
		scanf("%d%d%lld",&u,&v,&len);
		e[u].push_back((node){len,v});
		e[v].push_back((node){len,u});
		ans2=min(ans2,len);
		q_min.push(len);
		q_max.push(len);
	}
	//dijk();
	//int siz=e[1].size();
	if(m==1)
	{
		memset(dis,-1,sizeof(dis));
		dis[1]=0;
		dfs(1,0);
		memset(dis,-1,sizeof(dis));
		dis[temp]=0;
		dfs(temp,0);
		printf("%lld\n",dis[temp]);
	}
	else
	{
		int cnt=0;
		while(q_max.size()-cnt>m || cnt<m)
		{
			q2_min.push(q_max.top()+q_min.top());
			q_max.pop();
			q_min.pop();
			++cnt;
		}
		if(cnt==m && q_max.size()-cnt>0)
		{
			q2_min.push(q_max.top());
			q_max.pop();	
		}
		printf("%lld\n",q2_min.top());
	}
	return 0;
}
