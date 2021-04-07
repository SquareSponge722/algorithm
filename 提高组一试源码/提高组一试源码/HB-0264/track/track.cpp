#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=50000+1000;
int head[maxn],in[maxn],dis[maxn],vis[maxn],stac[maxn];
struct node{
	int next,to,v;
}edge[maxn];
int n,m,a,b,c,top,ans,cnt,flag=0;
int max(int a,int b){if(a>b) return a; else return b;}
void add(int a,int b,int c)
{
	edge[++cnt].next=head[a];
	edge[cnt].to=b;
	edge[cnt].v=c;
	head[a]=cnt;
}
queue<int>q1;
queue<int >q;
void spfa(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dis,99,sizeof(dis));
	q.push(s); vis[s]=1; dis[s]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].v)
			{
				dis[y]=dis[x]+edge[i].v;
				if(vis[y]==0)
				{
					q.push(y);
					vis[y]=1;
				}
			}
		}
	}
	for(int i=1;i<=top;i++)
	{
		ans=max(ans,dis[stac[i]]);
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		in[a]++; in[b]++;
		if(b!=a+1) flag=1;
		add(a,b,c);
		add(b,a,c);
	}

		for(int i=1;i<=n;i++) 
			if(in[i]==1)
				stac[++top]=i;
		for(int i=1;i<=top;i++) spfa(i);
		printf("%d",ans);

	return 0;
}
	