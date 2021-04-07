#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int mod=1e9+7;
int n,m,dp[10][1000005];
int main()
{
	//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i-1>=1)
			{
				dp[i][j]=(dp[i-1][j]+1)%mod;
			}
			if(j-1>=1)
			{
				dp[i][j]=(dp[i][j-1]+1)%mod;
			}
		}
	printf("%d\n",dp[n][m]%mod);
	return 0;
}
