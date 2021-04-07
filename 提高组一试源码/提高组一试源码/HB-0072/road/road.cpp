#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const long long INF=9999999999;
long long n,d[110000],ans=0;

inline long long getnum()
{
	long long s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') { s=s*10+ch-'0'; ch=getchar();}
	return s;
}

void dfs(long long l,long long r,long long flag)
{
	if (l>r) return;
	if (l==r) { ans+=d[l]-flag; return;}
	long long minn=INF,q=l;
	for (long long i=l; i<=r; ++i)
	    {
	    	if (d[i]<minn) minn=d[i];
		}
	for (long long i=l; i<=r; ++i)
	    {
	    	if (d[i]-minn==0) { dfs(q,i-1,minn); q=i+1;}
		}
	dfs(q,r,minn); ans+=minn-flag;
	return;
}

void work(long long l,long long r)
{
	if (l>r) return;
	if (l==r) { ans+=d[l]; return;}
	long long minn=INF,q=l; 
	for (long long i=l; i<=r; ++i)
	    {
	    	if (d[i]<minn) minn=d[i];
		}
	for (long long i=l; i<=r; ++i)
	    {
	    	d[i]=d[i]-minn;
	    	if (d[i]==0) { work(q,i-1); q=i+1;}
		}
	work(q,r); ans+=minn;
	return;
}

void get_work()
{
	n=getnum();
	for (long long i=1; i<=n; ++i) d[i]=getnum();
	if (n<=1000) work(1,n);
	else dfs(1,n,0);
	printf("%lld",ans);
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	get_work();

	return 0;
}
