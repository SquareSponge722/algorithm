#include <cstdio>
#include <algorithm>
#include <algorithm>
using namespace std;
int n,m,mod=1000000007;
long long f[10][1000001][2];
int main()
{
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i][0][0]=1;
	for(int i=1;i<=m;i++)
		f[0][i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			f[i][j][0]=f[i][j][1]=(f[i-1][j][0]*(f[i][j-1][0]+f[i][j-1][1])%mod+f[i-1][j][1]*f[i][j-1][1]%mod)%mod;
		}
	printf("%lld",f[n][m][1]+f[n][m][0]);
	return 0;
}
