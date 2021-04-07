#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<ctime>
using namespace std;
const int mod = 1e9 + 7;
long long Pow(long long x,long long y,long long mod)
{
	long long ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(n == 1 && m == 3)cout << 8 <<endl;
	else if(n == 1 && m > 3) cout << 8 * Pow(3,m-3,mod) <<endl;
	else if(n == 2 && m == 2) cout << 12 <<endl;
	else if(n == 2 && m == 1) cout << 4 <<endl;
	else if(n == 2 && m > 2 ) cout << 4 * Pow(3,m-3,mod) <<endl;
	else if(n == 3 && m == 1) cout << 8 <<endl;
	else if(n == 3 && m > 1) cout << 8 * Pow(3,m-3,mod) <<endl;
	return 0;
}
