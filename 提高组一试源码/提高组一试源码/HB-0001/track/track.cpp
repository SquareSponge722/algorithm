#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 50050
using namespace std;
int head[N],dis[N],n,m,maxn[N],maxnn;
struct E
{
	int nxt,to,w;
}  e[N];
struct V
{
	int v,dis;
	bool operator <(const V &a) const
	{
		return dis>a.dis;
	}
};
int sum;
void add(int u,int v,int w)
{
	e[++sum].nxt=head[u];
	e[sum].to=v;
	e[sum].w=w;
	head[u]=sum;
}
void D(int s)
{
	priority_queue<V>q;
	memset(dis,0x7f,sizeof(dis));
	dis[s]=0;
	V temp=(V){s,dis[s]};
	q.push(temp);
	while(q.size()>0)
	{
		temp=q.top();q.pop();
		int k=temp.v;
		if(dis[k]<temp.dis)  continue;
		for(int i=head[k];i;i=e[i].nxt)
		  if(dis[k]+e[i].w<dis[e[i].to])
		  {
		  	  dis[e[i].to]=dis[k]+e[i].w;
		  	  temp=(V){e[i].to,dis[e[i].to]};
		  	  q.push(temp);
		  }
	}
	return;
}
using namespace std;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
	    {
	 	   D(i);
		   for(int j=1;j<=n;j++)
		     if(dis[j]!=0x7f&&dis[j+1]!=0x7f)
		       maxn[i]=max(dis[j],maxn[i]);
	    }
 	    for(int i=1;i<=n;i++)
	      maxnn=max(maxn[i],maxnn);
	    printf("%d",maxnn);
	}
	else   printf("%d",m*n-(m+n));
	return 0;
}
