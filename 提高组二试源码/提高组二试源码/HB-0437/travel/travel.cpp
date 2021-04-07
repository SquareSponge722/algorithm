#include<bits/stdc++.h>
#define Side(x) for(int i=p[x];i;i=nt[i])
using namespace std;
const int N=5020,M=10020;
int tot,e[M],nt[M],p[N],in[N],cnt,ans[N],n,m;
void _add(int x,int y){e[++tot]=y,nt[tot]=p[x],p[x]=tot;}
inline void add(int x,int y){_add(x,y),_add(y,x);}
typedef set<int>::iterator sit;
void dfs(int x,int fr)
{
	ans[++cnt]=x;
	priority_queue<int>hp;
	Side(x)
	{
		if(e[i]==fr)continue;
		hp.push(-e[i]);
	}
	while(!hp.empty())
	{
		int fr=-hp.top();hp.pop();
		dfs(fr,x);
	}
}
void solve1()
{
	dfs(1,0);
	printf("%d",ans[1]);
	for(int i=2;i<=cnt;i++)printf(" %d",ans[i]);
}
void solve2()
{
	/*findCircle();
	for(int i=1;i<=pointsOnCircle;i++)
	{
		if(!dfs1(i,0))
		{
			
		}
	}*/
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,ui,vi;i<=m;i++)
		scanf("%d%d",&ui,&vi),add(ui,vi);
	if(m==n-1)solve1();
	else solve2();
}
