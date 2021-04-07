#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

long long p,fa=0,maxn=-1,n,m,fw[55000],head[55000],st[55000],tong[55000];
struct tnode
{
	long long v,next,w;
}vec[110000];

inline long long getnum()
{
	long long s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') { s=s*10+ch-'0'; ch=getchar();}
	return s;
}

void add(long long u,long long v,long long w)
{
	vec[++fa].v=v; vec[fa].w=w; vec[fa].next=head[u]; head[u]=fa;
}

void dfs(long long rt,long long s)
{
	if (s>maxn) { p=rt; maxn=s;}
	for (long long i=head[rt]; i; i=vec[i].next)
	    {
	    	if (!fw[vec[i].v])
	    	    {
	    	    	fw[vec[i].v]=1;
	    	    	dfs(vec[i].v,s+vec[i].w);
				}
		}
}

void work1()
{
	fw[1]=1; dfs(1,0);
	memset(fw,0,sizeof(fw)); maxn=-1;
	fw[p]=1; dfs(p,0);
	printf("%lld",maxn);
}

void work2()
{
	sort(st+1,st+n);
	for (long long i=1; i<=n/2; ++i)
	    {
	    	tong[i]=st[i]+st[n-i];
		}
	sort(tong+1,tong+n/2+1);
	if (m<=n/2) printf("%lld",tong[n/2-m+1]);
	else printf("%lld",vec[fa/2-m+1].w);
}

void get_work()
{
	long long u,v,w;
	n=getnum(); m=getnum();
	for (long long i=1; i<=n-1; ++i)
	    {
	    	u=getnum(); v=getnum(); w=getnum();
	    	add(u,v,w); add(v,u,w); st[i]=w;
		}
	if (m==1) work1();
	else work2();
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	get_work();
	
	return 0;
}
