#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q[5001];
queue<int>qans;
int n,m;
struct EDGE
{
	int s;
	int e;
	int next;
}edge[5001*2];
int head[5001];
int cnt;
int cur;
int done[5001];
int vis[5001];
int hehe[5001];
int fr[5001];
//int la[5001];
int ge;
int pointer;
void add(int s,int e)
{
	cnt++;
	edge[cnt].s=s;
	edge[cnt].e=e;
	edge[cnt].next=head[s];
	head[s]=cnt;
	cnt++;
	edge[cnt].e=s;
	edge[cnt].s=e;
	edge[cnt].next=head[e];
	head[e]=cnt;
}
void dfs(int u,int step,int fa)
{
	qans.push(u);
	//printf("%d %d\n",u,step);
	for(int t=head[u];t;t=edge[t].next)
	{
		int v=edge[t].e;
		if(vis[v])
		{
			continue;
		}
		q[u].push(v);
	}
	while(!q[u].empty())
	{
		int v=q[u].top();
		q[u].pop();
		vis[v]=1;
		dfs(v,step+1,u);
		vis[v]=0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	if(m==n-1)
	{
		vis[1]=1;
		dfs(1,1,0);
		while(!qans.empty())
		{
			printf("%d ",qans.front());
			qans.pop();
		}
	}
	if(m==n)
	{
		vis[1]=1;
		dfs(1,1,0);
		while(!qans.empty())
		{
			ge++;
			hehe[ge]=qans.front();
			qans.pop();
		}
		pointer=1;
		for(int i=1;i<=ge;i++)
		{
			if(!fr[hehe[i]])
			{
				fr[hehe[i]]=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(done[i])
			{
				continue;
			}
			for(int j=1;j<fr[i];j++)
			{
				if(hehe[j]>i)
				{
					int flag=1;
					for(int k=fr[i]+1;k<=ge;k++)
					{
						if(hehe[k]==hehe[j])
						{
							flag=0;
							break;
						}
					}
					if(flag==1)
					{
						qans.push(hehe[j]);
						done[hehe[j]]=1;
					}
				}
			}
			qans.push(i);
			done[i]=1;
		}
		/*
		for(int i=ge;i>=1;i--)
		{
			if(!la[hehe[i]])
			{
				la[hehe[i]]=i;
			}	
		}*/
		while(!qans.empty())
		{
			printf("%d ",qans.front());
			qans.pop();
		}
	}
	return 0;
}
/*
6 5
1 3
2 3
2 5
3 4
4 6
*/
/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/