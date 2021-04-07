#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int S=5050;
struct edge{
	int to,next;
}e[S<<1]; int head[S]; int c=0;
int cnt[S];
void ad(int u,int v)
{
	e[++c].to=v;
	e[c].next=head[u]; head[u]=c;
}
int n,m; bool vis[S];
int sx[S];
inline bool cmp(int a,int b)
{
	return a>b;
}
void walawala(int u)
{
	vis[u]=true;  int num=0;
	for(int j=head[u];j;j=e[j].next)
		sx[++num]=e[j].to;
	sort(sx+1,sx+num+1,cmp);
	for(int j=head[u];j;j=e[j].next)
		e[j].to=sx[num--];
	for(int j=head[u];j;j=e[j].next)
		if(!vis[e[j].to]) walawala(e[j].to);
}
void dfs(int u)
{
	printf("%d ",u); vis[u]=true;
	for(int j=head[u];j;j=e[j].next)
	{
		if(vis[e[j].to]) continue ;
		dfs(e[j].to);
	}
}
inline void kill(int u,int v)
{
	int pre;
	for(int j=head[u];j;j=e[j].next)
	{
		if(e[j].to==v)
		{
			if(j==head[u])
				head[u]=e[j].next;
			else	
				e[pre].next=e[j].next;
			return ;
		}
		pre=j;
	}
}
int fa[S]; int mem[S]; int pos[S]; int t=0; int hf;
bool findhuan(int u,int from)
{
//	printf("%d\n",u);
	vis[u]=true; fa[u]=from; mem[++t]=u; pos[u]=t;
	for(int j=head[u];j;j=e[j].next)
	{
		if(e[j].to==from) continue ;
		if(vis[e[j].to]){
			hf=e[j].to;
			return true;
		}
		if(findhuan(e[j].to,u))
			return true;
	}
	t--;
	vis[u]=false;
	return false;
}
void del()
{
	findhuan(1,-1);
	int dd; int mn=-1;
	for(int j=pos[hf];j<=t;j++)
		mem[j-pos[hf]]=mem[j];
	t-=pos[hf];
	
	int i1=1; int i2=t;
	if(mem[i1]<mem[i2])
	{
		while(mem[i1+1]<mem[i2] && i1+1<i2) i1++;
		kill(mem[i1],mem[i1+1]); kill(mem[i1+1],mem[i1]);
	}
	else
	{
		while(mem[i1]>mem[i2-1] && i1<i2-1) i2--;
		kill(mem[i2],mem[i2-1]); kill(mem[i2-1],mem[i2]);
	}

}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v; scanf("%d %d",&u,&v);
		ad(u,v); ad(v,u);
	}

	memset(vis,0,sizeof(vis));	walawala(1);
	if(n==m) { memset(vis,0,sizeof(vis));  del(); }
	memset(vis,0,sizeof(vis));  dfs(1);
	printf("\n");
	return 0;
}
