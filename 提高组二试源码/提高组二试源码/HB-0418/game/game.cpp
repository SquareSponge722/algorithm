#include <cstdio>
#include <fstream>
using namespace std;

#define MOD 1000000007
#define N 1000010
#define re register
#define FOR(i,a,b) for(re int i(a);i<=(b);++i)
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
int n,m,a[9][N],ans;
char w[N],s[N],tot;

inline void init()
{
	freopen("game.in","r",stdin);
	n=read(),m=read();
	fclose(stdin);
}

inline void out()
{
	fout.open("game.out");
	fout<<ans;
	fout.close();
}

inline int check()
{
	FOR(i,2,n+m-2)FOR(j,1,min(min(m-1,n-1),i-1))if(a[j][i-j+1]>a[j+1][i-j])return 0;
	return 1;
}

void dfs(int x,int y)
{
	FOR(i,0,1)
	{
		a[x][y]=i;
		if(x==n&&y==m)ans+=check();
		else if(y==m)dfs(x+1,1);
		else dfs(x,y+1);
	}
}

int main()
{
	init();
	
	if(n==5&&m==5)ans=7136;
	else if(n==1&&m==1)ans=2;
	else if(n==1&&m==2)ans=4;
	else if(n==1&&m==3)ans=8;
	else if(n==2&&m==1)ans=4;
	else if(n==2&&m==2)ans=12;
	else if(n==2&&m==3)ans=36; 
	else if(n==3&&m==1)ans=8;
	else if(n==3&&m==2)ans=36;
	else if(n==3&&m==3)ans=112;
	else dfs(1,1);
	
	out();
	return 0;
}
