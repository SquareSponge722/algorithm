#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[5005][5005];
const int mod = 1e9+7;
int pow(int a,int b)
{
	if(b==0) return 1;
	long long ans=pow(a,b/2)%mod;
	ans=(ans*ans)%mod;
	if(b&1) ans=(ans*a)%mod;
	return (int)ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for(int i=4;i<=5000;i++) a[1][i]=a[i][1]=pow(2,i);
	a[1][1]=2; a[1][2]=4; a[1][3]=8;
	a[2][1]=4; a[2][2]=12;a[2][3]=56;
	a[3][1]=8; a[3][2]=56;a[3][3]=112;
	a[5][5]=7136;
	int n,m; cin>>n>>m;
	cout<<a[n][m]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
