#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<complex>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define mlr ll mid((l+r)>>1)
using namespace std;
struct edge
{
	int to,next,weight;
}a[2000020];
struct node
{
	int dist,id;
	node(){}
	node(int dist,int id):dist(dist),id(id){}
};
struct mod
{
	char ed;
	int val;
}mode;
bool operator <(node xi,node yi)
{
	return xi.dist>yi.dist;
}
int vis[1000010];
int dist[1000010];
int head[1000010];
int val[1000010];
int pre[1000010];
int last[1000010];
int n,m;
int x,y,w;
int cnt(0);
struct qel
{
	int val;
	qel(){}
	qel(int val):val(val){}
};
int f(qel k)
{
	return k.val;
}
bool operator <(qel xi,qel yi)
{
	return val[f(xi)]>val[f(yi)];
}
priority_queue<qel> q;
void addedge(int xi,int yi,int wi)
{
	a[cnt].to=yi;
	a[cnt].next=head[xi];
	a[cnt].weight=wi;
	head[xi]=cnt++;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	cin>>mode.ed>>mode.val;
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y,1);
		addedge(y,x,1);
	}
	while(m--)printf("%d\n",-1);
	return 0;
}