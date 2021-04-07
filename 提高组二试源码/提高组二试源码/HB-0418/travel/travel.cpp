#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#define N 5010
#define re register
#define FOR(i,a,b) for(re int i(a);i<=(b);++i)
#define REP(i,a) for(re vector<int>::iterator i=edge[a].begin();i!=edge[a].end();++i)
#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,100000,stdin),pa==pb)?EOF:*pa++
static char buf[100000],*pa(buf),*pb(buf);
inline int read()
{
	re int x(0);re char c(gc);
	while(c<'0'||c>'9')c=gc;
	while(c>='0'&&c<='9')x=x*10+c-48,c=gc;
	return x;
}

ofstream fout;
int n,m,u,v,ans[N],b[N],tot,ShiinaMashiro;

vector<int>edge[N];
inline void link(int u,int v){edge[u].push_back(v);}

inline void init()
{
	freopen("travel.in","r",stdin);
	n=read(),m=read();
	FOR(i,1,m)u=read(),v=read(),link(u,v),link(v,u);
	fclose(stdin);
}

inline void out()
{
	fout.open("travel.out");
	FOR(i,1,n)fout<<ans[i]<<' ';
	fout.close();
}

void dfs(int k)
{
	REP(i,k)if(!b[*i]&&!ShiinaMashiro)
	{
		b[*i]=1,ans[++tot]=*i;
		if(tot==n)ShiinaMashiro=1;
		else dfs(*i);
	}
}

inline void work()
{
	for(int i=1;i<=n;++i)sort(edge[i].begin(),edge[i].end());
	b[1]=1,ans[++tot]=1,dfs(1);
}

int main()
{
	init();
	
	work();
	
	out();
	return 0;
}
