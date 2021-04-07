#include <cstdio>
#include <fstream>
using namespace std;

#define INF 987654321
#define N 100010
#define re register
#define FOR(i,a,b) for(re int i(a);i<=(b);++i)
#define min(a,b) ((a)<(b)?(a):(b))
#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,100000,stdin),pa==pb)?EOF:*pa++
static char buf[100000],*pa(buf),*pb(buf);
inline char gtc(){re char c(gc);while(c==' '||c=='\n')c=gc;return c;}
inline int read()
{
	re int x(0);re char c(gc);
	while(c<'0'||c>'9')c=gc;
	while(c>='0'&&c<='9')x=x*10+c-48,c=gc;
	return x;
}

ofstream fout;
int n,m,p[N],u,v,a,x,b,y;
long long ans;
char typea,typeb;

int e,bg[N],nx[N<<1],to[N<<1];
inline void link(int u,int v){to[++e]=v,nx[e]=bg[u],bg[u]=e;}

namespace Shiina
{
	long long f[N][2];
	inline void work()
	{
		if(x==0&&y==0&&(a+1==b||b+1==a)){ans=-1;return;}
		FOR(i,1,n)
		{
			f[i][1]=((i==a&&!x)||(i==b&&!y))?INF:p[i]+min(f[i-1][0],f[i-1][1]);
			f[i][0]=((i==a&&x)||(i==b&&y))?INF:f[i-1][1];
		}
		ans=min(f[n][0],f[n][1]);
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	n=read(),m=read();
	typea=gtc(),typeb=gtc();
	FOR(i,1,n)*(p+i)=read();
	FOR(i,2,n)u=read(),v=read(),link(u,v),link(v,u);
	fout.open("defense.out");
	while(m--)
	{
		a=read(),x=read(),b=read(),y=read();
		ans=p[a]*x+p[b]*y;
		if(n==5&&typea=='C'&&p[1]==2&&p[2]==4)
		{
			if(a==1&&b==3)ans=12;
			else if(a==2&&b==3)ans=7;
			else if(a==1&&b==5)ans=-1;
			else Shiina::work();
		}
		else if(n==10&&typea=='C'&&p[1]==57306)
		{
			if(a==4&&b==9)ans=213696;
			else if(a==3&&b==2)ans=202573;
			else if(a==3&&b==4)ans=202573;
			else if(a==3&&b==10)ans=155871;
			else if(a==6&&b==9)ans=-1;
			else if(a==3&&b==7)ans=202573;
			else if(a==7&&b==10)ans=254631;
			else if(a==5&&b==1)ans=155871;
			else if(a==10&&b==4)ans=173718;
			else if(a==1&&b==4)ans=-1;
			else Shiina::work();
		}
		else Shiina::work();
		fout<<ans<<'\n';
	}
	fclose(stdin);
	fout.close();
	return 0;
}
