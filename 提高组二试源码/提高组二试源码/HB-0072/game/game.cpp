#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;

const long long mo=1e9+7;
long long f,s,t=0,n,m,a[10][110000];

void work1()
{
    s=1,t=3;
	f=m-1;
	while (f)
	    {
	    	if (f%2==1) s=s*t%mo;
			f=f/2;
			t=t*t%mo;
		}
	s=s*4%mo;
	printf("%lld",s);
}

void dfs(long long r,long long c)
{
	if (r==n&&c==m+1)
	    {
	    	t++;
	    	return;
		}
	if (c==m+1)
	    {
	    	dfs(r+1,1);
	    	return;
		}
	if (r-1>0&&c+1<=m)
	    {
	    	if (a[r-1][c+1]==1)
	    	    {
	    	    	a[r][c]=1;
	    	    	dfs(r,c+1);
				}
			else
			    {
			    	a[r][c]=0;
			    	dfs(r,c+1);
			    	a[r][c]=1;
			    	dfs(r,c+1);
				}
		}
	else
	    {
	    	a[r][c]=1;
	    	dfs(r,c+1);
	    	a[r][c]=0;
	    	dfs(r,c+1);
		}
}

void get_work()
{
	scanf("%lld %lld",&n,&m);
	if (n==2)
	    work1();
	else
	    {
	    	dfs(1,1);
	    	printf("%lld",t);
		}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	get_work();

	return 0;
}
