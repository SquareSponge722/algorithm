#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<pair<int,int> > e[50010];
queue<int> q;
bool v[50010];
int n,ans,d[50010],pa[50010],o;
int bfs1()
{
	memset(v,false,sizeof(v));
	memset(d,0,sizeof(d));
	d[1]=0,v[1]=true;
	q.push(1);
	for(int i=0;i<=n;i++)pa[i]=i;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(unsigned int i=0;i<e[x].size();i++)
		{
			int y=e[x][i].first,z=e[x][i].second;
			if(!v[y])
			{
				d[y]=d[x]+z;
				pa[y]=x;
				v[y]=true;
				q.push(y);
			}
		}
	}
	int rt=0;
	for(int i=1;i<=n;i++)if(rt<d[i])rt=d[i],o=i;
	return rt;
}
void book(int x)
{
	v[x]=true;
	if(pa[x]!=x)book(pa[x]);
}
int bfs2()
{
	memset(d,0,sizeof(d));
	memset(v,false,sizeof(v));
	book(o);
	d[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(unsigned int i=0;i<e[x].size();i++)
		{
			int y=e[x][i].first,z=e[x][i].second;
			if(!v[y])
			{
				d[y]=d[x]+z;
				v[y]=true;
				q.push(y);
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++)maxn=max(maxn,d[i]);
	return maxn;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		e[a].push_back(make_pair(b,l));
		e[b].push_back(make_pair(a,l));
	}
	int an=bfs1();
	an+=bfs2();
	printf("%d",an);
	return 0;
}