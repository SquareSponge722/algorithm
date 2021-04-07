#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
void work()
{
	if(ch[0]=='A')
	{
		if(ch[1]=='1')
		{
			for(int i=2;i<=n;i++)
			{
				dp[i]
			}		
		}
		if(ch[1]=='2')
		{
			
		}
		if(ch[0]==='3')
		{
			
		}
	}
	if(ch[0]=='B')
	{
		
	}
	if(ch[0]=='C')
	{
		
	}
}
int main()
{
	//freopen("defense.in","r",stdin);
	//freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,ch);
	for(int i=1; i<=n; i++)
		scanf("%d",&d[i]);
	for(int i=1; i<n; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=m;i++)
	{
		int x,a,y,b;
		scanf("%d %d %d %d",&x,&a,&y,&b);
		c[x]=a,c[y]=b;
		work();
	}
	printf("0\n");
	return 0;
}
