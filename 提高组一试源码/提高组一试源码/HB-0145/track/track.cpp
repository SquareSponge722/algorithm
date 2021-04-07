#include <bits/stdc++.h>
#define N 100000+1000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct edge
{
	int to,w,nxt;
}q[N];
int head[N],num=0,n,m,fa[N],dis[N],l,r,cnt=0;
void add(int x,int y,int z)
{
	q[num]=(edge){y,z,head[x]};
	head[x]=num++;
	q[num]=(edge){x,z,head[y]};
	head[y]=num++;
}
void dfs(int x)
{
	for(int i=head[x];i!=-1;i=q[i].nxt)
	{
		int v=q[i].to;
		if(v!=fa[x])
		{
			fa[v]=x;
			dis[v]=dis[x]+q[i].w;
			dfs(v);
		}
	}
}
int main() 
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	n=read(),m=read();
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read(),z=read();
		if(y==x+1)cnt++;
		add(x,y,z);
	}
	if(m==1)
	{
		dfs(1);
		l=1;
		for(int i=1;i<=n;i++)
		{
			if(dis[i]>dis[l])
			{
				l=i;
			}
		}
		memset(fa,0,sizeof(fa));
		memset(dis,0,sizeof(dis));
		dfs(l);
		r=1;
		for(int i=1;i<=n;i++)
		{
			if(dis[i]>dis[r])
			{
				r=i;
			}
		}
		printf("%d",dis[r]);
	}
	return 0;
}