#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
struct EDGE
{
	int s;
	int e;
	int w;
	int fan;
	int done;
	int next;
}edge[50001*2];
int head[50001];
int n;
int cnt;
int flagline;
int maxdepth;
int dest;
int de[50001];
int m;
int f[50001];
int w[50001];
int pre[50001];
int flagone;
int ans;
int _min;
void add(int s,int e,int w)
{
	cnt++;
	edge[cnt].s=s;
	edge[cnt].e=e;
	edge[cnt].w=w;
	edge[cnt].fan=cnt+1;
	edge[cnt].next=head[s];
	head[s]=cnt;
	cnt++;
	edge[cnt].s=e;
	edge[cnt].e=s;
	edge[cnt].w=w;
	edge[cnt].fan=cnt-1;
	edge[cnt].next=head[e];
	head[e]=cnt;
}
void dfsm(int u,int fa,int maxn)
{
	if(maxn>maxdepth)
	{
		maxdepth=maxn;
		dest=u;
	}
	for(int t=head[u];t;t=edge[t].next)
	{
		int v=edge[t].e;
		if(v==fa)
		{
			continue;
		}
		dfsm(v,u,maxn+edge[t].w);
	}
}
signed main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	flagline=1;
	flagone=1;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		w[x]=z;
		if(y!=x+1)
		{
			flagline=0;
		}
		if(x!=1)
		{
			flagone=0;
		}
		add(x,y,z);
	}
	if(m==1)
	{
		maxdepth=0;
		dfsm(1,0,0);
		maxdepth=0;
		dfsm(dest,0,0);
		printf("%lld",maxdepth);
		return 0;
	}
	if(flagline==1)
	{
		for(int i=1;i<=n;i++)
		{
			_min=min(_min,w[i]);
		}
		int l=0;
		int r=(int)1e9;
		while(l<r)
		{
			
			int mid=(l+r)/2;//printf("%lld:\n",mid);
			int nowans=0;
			int sum=0;
			int pointer=1;
			while(pointer<n)
			{
				//printf("%lld ",pointer);
				sum+=w[pointer];
				if(sum<=mid)
				{
					pointer++;
				}
				else
				{
					nowans++;
					pointer++;
					sum=0;
				}
			}
			//printf("%lld\n",nowans);
			if(nowans<m)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		printf("%lld",l);
		return 0;
	}
	return 0;
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
/*
5 3
1 2 1
2 3 3
3 4 2
4 5 4
*/