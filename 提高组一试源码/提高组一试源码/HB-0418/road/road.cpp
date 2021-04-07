#include <cstdio>
#include <fstream>
using namespace std;

#define INF 987654321
#define N 100010
#define re register
#define FOR(i,a,b) for(re int i(a);i<=(b);++i)
#define _FOR(i,a,b) for(re int i(a);i>=(b);--i)
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
int n,a[N],ans;

inline void init()
{
	freopen("road.in","r",stdin);
	n=read();
	FOR(i,1,n)*(a+i)=read();
	fclose(stdin);
}

inline void out()
{
	fout.open("road.out");
	fout<<ans;
	fout.close();
}

int minv[N<<2],m=1,fxj;
inline void build(int n)
{
	while(m<=n)m<<=1;
	FOR(i,1,n)minv[i+m]=a[i];
	_FOR(i,m-1,1)minv[i]=min(minv[i<<1],minv[i<<1|1]);
}
inline int getmin(int l,int r)
{
	int _min=INF;
	for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1)
	{
		if((l&1)^1)
		{
			if(minv[l^1]<_min)_min=minv[l^1],fxj=l^1;
		}
		if(r&1)
		{
			if(minv[r^1]<_min)_min=minv[r^1],fxj=r^1;
		}
	}
	return _min;
}
int gtid(int d)
{
	if(m<d&&d<=m+n)return d-m;
	if(minv[d<<1]<minv[d<<1|1])
	return gtid(d<<1);
	else return gtid(d<<1|1);
}

void del(int l,int r,int k)
{
	if(l>r)return;
	int tmp=getmin(l,r),fn=gtid(fxj);
	ans+=tmp-k;
	del(l,fn-1,tmp);
	del(fn+1,r,tmp);
}

int main()
{
	init();
	
	build(n);
	del(1,n,0);
	
	out();
	return 0;
}
