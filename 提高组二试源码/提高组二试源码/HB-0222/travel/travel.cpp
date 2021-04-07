#include<bits/stdc++.h>
using namespace std;
//#define DEBUG
const int maxn=5000+10;
int n,m;
int cptr=1,cptr2=1;
queue<int>ans;
struct Node
{
	int son,son2,father;
	bool tag;
} Nodes[maxn];
inline void getin(int a,int b)
{
	while(Nodes[a].father!=a)a=Nodes[a].father;
	Nodes[a].father=b;
}
inline bool Query(int a,int b)
{
	while(Nodes[a].father!=a)
		a=Nodes[a].father;
	while(Nodes[b].father!=b)
		b=Nodes[b].father;
	return a==b;

}
struct Edge
{
	int from,to,next;
	int Value;
} Edges[maxn*2],Edges2[maxn];
bool operator < (const Edge &a,const Edge &b)
{
	return abs(a.from-a.to)>abs(b.from-b.to);
}
priority_queue<Edge>tool;
inline void Build_Edge(int u,int v)
{
	Edges[cptr].from=u;
	Edges[cptr].to=v;
	Edges[cptr].next=Nodes[u].son;
	Edges[cptr].Value=v;
	Nodes[u].son=cptr++;
}
inline void Build_Edge2(int u,int v)
{
	Edges2[cptr2].from=u;
	Edges2[cptr2].to=v;
	Edges2[cptr2].next=Nodes[u].son2;
	Nodes[u].son2=cptr2++;
}
void DFS(int pos)
{
	ans.push(pos);
	Nodes[pos].tag=true;
	for(;;)
	{
		int to=0x3f3f3f3f;
		for(int i=Nodes[pos].son2; i; i=Edges2[i].next)
			if(Nodes[Edges2[i].to].tag==false)to=min(to,Edges2[i].to);
		if(to==0x3f3f3f3f)break;
		DFS(to);
	}
}
int main()
{
#ifndef DEBUG
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
#endif // DEBUG
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)Nodes[i].father=i;
	for(int i=0; i<m; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		Build_Edge(u,v);
		tool.push(Edges[cptr-1]);
		Build_Edge(v,u);
		tool.push(Edges[cptr-1]);
	}
	while(!tool.empty())
	{
		Edge a=tool.top();
		tool.pop();
		if(!Query(a.from,a.to))
		{
			Build_Edge2(a.from,a.to);
			Build_Edge2(a.to,a.from);
			getin(a.from,a.to);
		}
	}DFS(1);
	while(!ans.empty())
	{
		printf("%d ",ans.front());
		ans.pop();
	}
	//puts("");
}
