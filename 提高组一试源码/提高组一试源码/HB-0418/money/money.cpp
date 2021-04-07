#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;

#define N 101
#define re register
#define FOR(i,a,b) for(re int i(a);i<=(b);++i)
#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,100000,stdin),pa==pb)?EOF:*pa++
static char buf[100000],*pa(buf),*pb(buf);
inline int read()
{
	re int x(0);re char c(gc);
	while(c<'0'||c>'9')c=gc;
	while(c>='0'&&c<='9')x=10*x+c-48,c=gc;
	return x;
}

ofstream fout;
int T,n,a[N],ans,tmp,b;

void dfs(int goal,int now)
{
	int ts=a[goal]/a[now];
	FOR(i,0,ts)if(!b)
	{
		tmp+=a[now]*i;
		if(now==n){if(tmp==a[goal])b=1;}
		else dfs(goal,now+1);
		tmp-=a[now]*i;
	}
}

inline void work()
{
	ans=n;
	sort(a+1,a+n+1,greater<int>());
	FOR(i,1,n-1)
	{
		b=0;
		dfs(i,i+1);
		if(b)--ans;
	}
}

int main()
{
	freopen("money.in","r",stdin);
	T=read();
	fout.open("money.out");
	while(T--)
	{
		n=read();
		FOR(i,1,n)*(a+i)=read();
		work();
		fout<<ans<<'\n';
	}
	fclose(stdin);
	fout.close();
	return 0;
}
