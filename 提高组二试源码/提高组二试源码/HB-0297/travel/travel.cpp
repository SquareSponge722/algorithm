#include<fstream>
#include<queue>
#include<algorithm>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
#define TU(x) for(register int k=head[x],v=e[k].to;k;k=e[k].nex,v=e[k].to)
using namespace std;
const int N=5010;
int n,m,cn1;
int head[N],ans[N],du[N];
struct Edge
{
	int nex,to;
} e[N<<1];
ifstream cin("travel.in");
ofstream cout("travel.out");
namespace solve1
{
	int from[N],num[N],cot;
	bool vis[N],fg;
	bool cp()
	{
		FOR(i,1,n)
		if(num[i]!=ans[i])
			return num[i]<ans[i];
		return false;
	}
	void dfs(int pos,int cnt)
	{
		if(cnt>=n)
		{
			if(cp())FOR(i,1,n)ans[i]=num[i];
//			FOR(i,1,n)cout<<num[i]<<" ";cout<<'\n';
			return;
		}
		TU(pos)
		{
			if(vis[v])continue;
			bool flag=0;
			vis[v]=1;
			if(!from[v])flag=1,from[v]=pos;
			num[cnt+1]=v;
			dfs(v,cnt+1);
			vis[v]=0;
			if(flag)from[v]=0;
		}
		if(pos!=1)
			dfs(from[pos],cnt);
	}
	void dfs2(int pos)
	{
		if(cot>n)return;
//			FOR(i,1,n)cout<<num[i]<<" ";cout<<'\n';
		priority_queue<int,vector<int>,greater<int> >q;
		while(!q.empty())q.pop();
		ans[cot]=pos;
		TU(pos)if(!vis[v])q.push(v);
		while(!q.empty())
		{
			int v=q.top();
			cot++;vis[v]=1;
			dfs2(v);
			q.pop();
		}
	}
	void work()
	{
		FOR(i,1,n)ans[i]=0x7fffff;
		from[1]=1;
		vis[1]=1;
		num[1]=1;
		dfs(1,1);
		vis[1]=0;
		FOR(i,1,n)cout<<ans[i]<<' ';
		return;
	}
	void work2()
	{
		FOR(i,1,n)ans[i]=0x7fffff;
		vis[1]=1;cot=1;
		from[1]=1;fg=0;
		dfs2(1);
		FOR(i,1,n)cout<<ans[i]<<' ';
		return;
	}
}
inline void add(int x,int y)
{
	e[++cn1].nex=head[x];
	e[cn1].to=y;
	head[x]=cn1;
	return;
}
int main()
{
	cin>>n>>m;
	FOR(i,1,m)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);du[a]++;
		add(b,a);du[b]++;
	}
	if(m==n-1)solve1::work2();
	else solve1::work();
	return 0;
}
/*
6 6
1 3
3 2
2 5
4 5
6 4
1 6
*/
