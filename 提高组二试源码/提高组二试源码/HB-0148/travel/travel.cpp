//chf sj ycy -||-
#include<bits/stdc++.h>

using namespace std;

#define rep(i,x,y) for(register int i=x;i<=y;i++)
#define rrep(i,x,y) for(register int i=x;i>=y;i--)

typedef long long ll;
typedef double db;

const int maxn=1e4;

int n,m,u,v;
int top=0;
int sx[5010][5010],St[maxn+10];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int tot;
int ver[maxn+10];
int nxt[maxn+10];
int head[maxn+10];
bool vis[maxn+10];

void insert(int x,int y)
{
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}

void dfs(int x,int dep)
{
//	printf("%d\n",x);
	St[++top]=x;
	vis[x]=1;
	int now=0;
	for(int i=head[x];i;i=nxt[i]) sx[dep][++now]=ver[i];
//	printf("%d\n",now);
	sort(sx[dep]+1,sx[dep]+now+1);
	rep(i,1,now) if(!vis[sx[dep][i]]) dfs(sx[dep][i],dep+1);
}

void work()
{
	n=read();m=read();
	rep(i,1,m)
	{
		u=read();v=read();
		insert(u,v);
		insert(v,u);
	}
	memset(vis,0,sizeof(vis));
	dfs(1,1);
//	printf("%d\n",top);
	rep(i,1,n)
	{
		if(i==n) printf("%d\n",St[i]);
		else printf("%d ",St[i]);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	work();
	return 0;
}
