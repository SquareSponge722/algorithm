#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

const long long INF=1e15;
long long n,m,f[110000],k[110000],minn;
string st;

inline long long getnum()
{
	long long s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') { s=s*10+ch-'0'; ch=getchar();}
	return s;
}

void dfs(long long pos,long long sigma)
{
	if (sigma>minn) return;
	if (pos==n+1) { minn=min(minn,sigma); return;}
	if (k[pos]==-1)
	    {	
		    k[pos]=0; if (k[pos-1]!=0||pos==1) dfs(pos+1,sigma);
	    	k[pos]=1; dfs(pos+1,sigma+f[pos]);
	    	k[pos]=-1;
		}
	else if (k[pos]==1)
	    {
	    	dfs(pos+1,sigma+f[pos]);
		}
	else if (k[pos]==0)
	    {
	    	if(k[pos-1]==0) return;
	    	else dfs(pos+1,sigma);
		}
}

void work()
{
	long long t,u,v,a,b,s1=0,s2=0;
	for (long long i=1; i<=n-1; ++i) u=getnum(),v=getnum();
	while (m--)
	    {
	    	a=getnum(); u=getnum(); b=getnum(); v=getnum();
			if (a>b) {t=a,a=b,b=t; t=u,u=v,v=t;}
			if (b-a==1&&u==0&&v==0) printf("-1\n");
			else
			    {
			    	minn=INF;
			        fill(k+1,k+n+1,-1);
			    	k[a]=u; k[b]=v;
			    	dfs(1,0);
			    	printf("%lld\n",minn);
				}
		}
}

void get_work()
{
	n=getnum(); m=getnum(); cin>>st;
	for (long long i=1; i<=n; ++i) f[i]=getnum();
	work();
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	get_work();

	return 0;
}
