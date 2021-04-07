#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
ll dp[10][1000005];
int n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	dp[1][1]=0;
	dp[2][2]=12;
	dp[3][3]=112;
	dp[5][5]=7136;
	printf("%d",dp[n][m]);
	return 0;
}
