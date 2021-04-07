#include<bits/stdc++.h>
#define re register
using namespace std;
struct Edge
{
	int v,w,next;
} e[50050];
int head[100010],cnt=0,maxn=0,r[1000][1000],g[100000],me,num[1000];
bool p[10000];
void addedge(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int n,m,s;
int dis[100010];
struct node
{
	int u,d;
	bool operator<(const node &rhs)
	const
	{
		return d>rhs.d;
	}
};
inline void clear()
{
	memset(dis,0,sizeof(dis));
}
inline void dj()
{
	for(int i=1; i<=n; i++)
		dis[i]=9999999;
	dis[s]=0;
	priority_queue<node>Q;
	Q.push((node)
	{
		s,0
	});
	while(!Q.empty())
	{
		node fr=Q.top();
		Q.pop();
		int u=fr.u,d=fr.d;
		if(d!=dis[u]) continue;
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				Q.push((node)
				{
					v,dis[v]
				});
			}
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m!=1&&m<=n-1&&n<=10)
	{
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)
		 if(i==j) r[i][j]=0;
		 else r[i][j]=9999999;
	}
	for(re int i=1; i<=n-1; ++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
		if(x==1||y==1) g[1]++;
		r[x][y]=z;
		r[y][x]=z;
		addedge(y,x,z);
	}
	if(m==1)
	{
		for(s=1; s<=n; ++s)
		{
			clear();
			dj();
			for(re int i=1; i<=n; ++i)
				if(maxn<dis[i]) maxn=dis[i];
		}
		cout<<maxn<<endl;
		return 0;
	}
	if(m!=1&&m<=n-1&&n<=15&&g[1]!=n-1)
	{
		for(int k=1;k<=n;k++)
		 for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		  if(r[i][j]>r[i][k]+r[k][j])
		  r[i][j]=r[i][k]+r[k][j];
		  for(int i=1;i<=n;i++)
		   for(int j=1;j<=n;j++)
		   r[i][j]=num[++me];
		sort(num+1,num+1+me);
		cout<<num[me-m]<<endl;
		return 0;
	}
}
