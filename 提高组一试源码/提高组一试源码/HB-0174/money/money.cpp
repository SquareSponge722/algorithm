//money.cpp
#include<cmath>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#define MAXN 105
#define MAXM 25005
using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");

bool c[MAXM];
int a[MAXN],b[MAXM<<2];
int t,n,m,mm,ans,cost,head;

inline void init()
{
	head=1;
	cost=n=m=mm=ans=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	c[0]=1;
	fin>>n;
	for(int i=1; i<=n; ++i)
		fin>>a[i];
	sort(a+1,a+n+1);
}

inline void dfs(int x)
{
	if(x>m)
	{
		c[cost]=1;
		return;
	}
	else
	{
		for(int p=0; p<=a[n]/b[x]+1; ++p)
		{
			cost+=p*b[x];
			dfs(x+1);
			cost-=p*b[x];
		}
	}
	return;
}

inline void tc(int x)
{
	mm=m;
	for(int p=1; p<=m; ++p)
		for(int j=0; j<=a[n]/b[p]; ++j)
			for(int k=0; k<=(a[n]-j*b[p])/x; ++k)
				if(!c[b[p]*j+x*k])
				{
					b[++mm]=b[p]*j+x*k;
					c[b[p]*j+x*k]=1;
				}
	m=mm;
	return;
}

inline void work1()
{
	b[++m]=a[head++];
	for(; head<=n; ++head)
		if(a[head]%b[1])
		{
			b[++m]=a[head];
			head++;
			break;
		}
	while(head<=n)
	{
		dfs(1);
		for(; head<=n; ++head)
			if(!c[a[head]])
			{
				b[++m]=a[head];
				head++;
				break;
			}
	}
	fout<<m<<endl;
}

inline void work2()
{
	b[++m]=a[head++];
	ans++;
	for(int i=1; i<=a[n]/b[1]; ++i)
		c[b[1]*i]=1;
	while(head<=n)
	{
		for(; head<=n; ++head)
			if(!c[a[head]])
			{
				tc(a[head]);
				sort(b+1,b+m+1);
				ans++;
				head++;
				break;
			}
	}
	fout<<ans<<endl;
}

inline void work()
{
	while(t--)
	{
		init();
		if(n<6)
			work1();
		else
			work2();
	}
}

int main()
{
	fin>>t;
	work();
	return 0;
}
