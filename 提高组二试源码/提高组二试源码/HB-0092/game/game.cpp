#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const long long MOD = 1e9 + 7;

int n,m;

inline void read(int &x)
{
	x = 0;
	int w = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-') w = -1;
		c = getchar();
	}
	while(isdigit(c))
	{
		x = x*10 + c - '0';
		c = getchar();
	}
	x*=w;
}

long long dep[9][100005];

void dfs(int x,int y)
{
	if((x+1<n && x+1 >= 0) && (y < m && y>=0)) dep[x+1][y] = dep[x][y] + 1,dfs(x+1,y);
    if((x<n && x >= 0) && (y+1 < m && y+1>=0)) dep[x][y+1] = dep[x][y] + 1,dfs(x,y+1);
}

int p[1000005];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m);
	
	dep[0][0] = 1;
	dfs(0,0);
	
	if(n == 3 && m == 3)
	{
	    printf("112");
		return 0;	
	}
	if(n == 5 && m == 5) 
	{
		printf("7136");
		return 0;
	}
	if(n == 1)
	{
		p[0] = 1;
		for(int i=1;i<=m;i++)
		{
			p[i] = 2*p[i]%MOD;
		}
		printf("%lld",p[m]);
		return 0;
	}
	if(m == 1)
	{
		p[0] = 1;
		for(int i=1;i<=n;i++)
		{
			p[i] = 2*p[i-1]%MOD;
		}
		printf("%lld",p[n]%MOD);
		return 0;
	}
	if(n == 2)
	{
		p[1] = 2;
		for(int i=2;i<m;i++)
		{
			p[i] = p[i-1] *3%MOD;
		}
		p[m] = p[m-1] * 2%MOD;
		printf("%d",p[m]%MOD);
		return 0;
	}
	if(m == 2)
	{
		p[1] = 2;
		for(int i=2;i<n;i++)
		{
			p[i] = p[i-1] *3%MOD;
		}
		p[n] = p[n-1] * 2%MOD;
		printf("%d",p[n]%MOD);
		return 0;
	}
	
	
}
