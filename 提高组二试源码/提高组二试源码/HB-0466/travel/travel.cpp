#include<cstdio>
#include<queue>
#define N 5010
using namespace std;
struct Edge{int to,next;}e[N<<1];
int first[N],times[N];
bool book[N<<1],flag=false,cut=false;
priority_queue<int>q[N];
int n,m;
void findc(int u,int fa)
{
	int k=first[u];
	while(k)
	{
		int v=e[k].to;k=e[k].next;
		if(v==fa)continue;
		if(times[v]==2){flag=true;return;}
		times[v]++;findc(v,u);
		if(flag)return;
	}
}
void cutEdge(int u,int fa,int qwq)
{
	int k=first[u];
	while(k)
	{
		int v=e[k].to;
		if(v==fa||times[v]!=2){k=e[k].next;continue;}
		if(v>qwq)
		{
			book[k]=true;
			if(k>m)book[k-m]=true;
			if(k<=m)book[k+m]=true;
			flag=true;
			return;
		}
		cutEdge(v,u,qwq);
		if(flag)return;
		k=e[k].next;
	}
}
void solve(int u,int fa)
{
	printf("%d ",u);
	int k=first[u];
	while(k)
	{
		int v=e[k].to;
		if(v!=fa&&!book[k])q[u].push(-v);
		k=e[k].next;
	}
	while(!q[u].empty())
	{
		int v=-q[u].top();q[u].pop();
		if(!cut&&times[v]==2)
		{
			int kk=first[v];
			int go=999999999,qwq=1000000000;
			while(kk)
			{
				int vv=e[kk].to;kk=e[kk].next;
				if(times[vv]==2&&vv<go){qwq=go;go=vv;}
				else if(times[vv]==2&&vv<qwq)qwq=vv;
			}
			cutEdge(go,v,qwq);
			cut=true;
		}
		solve(v,u);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	int u,v;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		e[i]=(Edge){v,first[u]};first[u]=i;
		e[i+m]=(Edge){u,first[v]};first[v]=i+m;
	}
	times[1]++;
	findc(1,0);flag=false;
	solve(1,0);
	return 0;
}
