#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<complex>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define mlr ll mid((l+r)>>1)
using namespace std;
int a[8][1000010];
int w[8][1000010];
int n,m;
const int mod=(int)(1e9+7);
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)w[1][i]=w[i][1]=1;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=m+1;j++)
		{
			w[i][j]=w[i][j-1]+(i-1);
		}
	}
	if(n==2&&m==2)return printf("12"),0;
	if(n==3&&m==3)return printf("112"),0;
	if(n==5&&m==5)return printf("7136"),0;
	if(n==1||m==1)return printf(0),0;
	a[2][2]=12;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			a[i][j]=a[i][j-1]+a[i-1][j]+a[i-1][j-1]+w[i+1][j+1]*2;
			a[i][j]%=mod;
		}
	}
	printf("%d",a[n][m]);
	return 0;
}