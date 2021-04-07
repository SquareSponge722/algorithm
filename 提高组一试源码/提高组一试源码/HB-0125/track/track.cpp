#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,s;
long long dis[5010][5010];
long long p[5010];
int b[10010];
int c[10010];
long long maxn=0;
long long minn=10000000;
long long minm=0;

void dfs(int x,long long curr)
{
	if( curr > maxn ) maxn=curr;

	for(int i=1;i<=n;i++)
	{
		if( dis[x][i] != 0 && b[i] == 0 )
		{
			b[i]=1;
			dfs(i,curr+dis[x][i]);
			b[i]=0;
		}
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;

	for(int i=1;i<=n-1;i++)
	{
		long long aa,bb,cc;
		cin>>aa>>bb>>cc;

		if( cc < minn )
        {
            minn=cc;
            minm=minn;
        }
		dis[aa][bb]=dis[bb][aa]=cc;
		c[aa]++;
		c[bb]++;
	}

	if( m >= 2 )
    {
        cout<<minm<<endl;
    }
    else if( m == 1 )
    {
        for(int i=1;i<=n;i++)
	    {
	     	memset(b,0,sizeof(b));

	    	if( c[i] > 1 ) continue;
	    	b[i]=1;
	    	dfs(i,0);
	    }
	    cout<<maxn<<endl;
    }
	return 0;
}
