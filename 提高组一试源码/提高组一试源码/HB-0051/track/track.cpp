#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=999999999;
struct line
{
	int from;
	int to;
	int v;
	int next;
};
line que[200005];
int headers[100005],cnt,n,dis[100005],book[100005],used[100005];
struct node
{
	int id;
	int dis;
	bool operator<(const node &b)const
	{
		return dis>b.dis;
	}
};
void add(int from,int to,int v)
{
	cnt++;
	que[cnt].from=from;
	que[cnt].to=to;
	que[cnt].v=v;
	que[cnt].next=headers[from];
	headers[from]=cnt;
}
int dijkstra(int s)
{
	int ans=0,maxdis=0;
	priority_queue<node>q;
	q.push((node){s,0});
	for(int i=1;i<=n;i++)
	{
		dis[i]=maxn;
		book[i]=0;
	}
	dis[s]=0;
	while(!q.empty())
	{
		node u=q.top();
		q.pop();
		if(book[u.id])
			continue;
		book[u.id]=1;
		for(int i=headers[u.id];i;i=que[i].next)
			if(dis[que[i].to]>dis[u.id]+que[i].v)
			{
				dis[que[i].to]=dis[u.id]+que[i].v;
				if(dis[que[i].to]>maxdis)
				{
					maxdis=dis[que[i].to];
					ans=que[i].to;
				}
				q.push((node){que[i].to,dis[que[i].to]});
			}
	}
	return ans;
}
bool cmp(line a,line b)
{
	return a.v>b.v;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int m,a,b,c,flag=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a!=1)
			flag=1;
		add(a,b,c);
		add(b,a,c);
	}
	if(m==1)
	{
		int u=dijkstra(1);
		int ans=dis[dijkstra(u)];
		printf("%d",ans);
	}
	else
	{
		if(flag==0)
		{
			sort(que+1,que+cnt,cmp);
			if(2*m<=n-1)
			{
				int ans=999999999;
				for(int i=1;i<=4*m;i+=2)
					ans=min(que[i].v+que[4*m-i].v,ans);
				printf("%d",ans);
			}
			else
			{
				int ans=999999999;
				for(int i=1;i<=(n-m-2)*2;i+=2)
					ans=min(ans,que[i].v);
				int mid=((n-m-2)*2+1+cnt-1)/2;
				for(int i=(n-m-2)*2+1;i<=mid;i+=2)
					ans=min(ans,que[i].v+que[2*mid-i].v);
				printf("%d",ans);
			}
		}
		else
		{
			int left=999999999,right=0;
			for(int i=1;i<=cnt;i+=2)
			{
				used[i/2+1]=-que[i].v;
				left=min(left,que[i].v);
				right+=que[i].v;
			}
			while(right-left>1)
			{
				int ans=0,div=0,mid=-(left+right)>>1;
				for(int i=1;i<=cnt/2;i++)
				{
					ans+=used[i];
					if(ans<mid)
					{
						ans=used[i];
						div++;
					}
				}
				if(div>=m)
					left=-mid;
				else
					right=-mid;
			}
			printf("%d",left);
		}
	}
	return 0;
}