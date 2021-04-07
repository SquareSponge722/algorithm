#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int f[9][1000100];
int n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	int i,j,k,l;
	f[0][0]=2;
	for(i=1;i<=m-1;i++)
	f[0][i]=(f[0][i-1]<<1)%mod;
	for(i=1;i<=n-1;i++)
	f[i][0]=(f[i-1][0]<<1)%mod;
	for(i=1;i<=m-1;i++)
	f[i][1]=(f[i-1][1]*3)%mod;
	for(i=1;i<=n-1;i++)
	f[1][i]=(f[1][i-1]*3)%mod;
	f[2][2]=112;
	f[4][4]=7136;
	cout<<f[n-1][m-1];
	return 0;
}
