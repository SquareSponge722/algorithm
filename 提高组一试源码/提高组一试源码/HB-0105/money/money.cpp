#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 25000 + 10;
const int maxm = 2000;
int a[maxn],primes[maxm],T,n;
inline int gcd(int x,int y)
{
	if(y == 0) return x;
	return gcd(y,x%y);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	memset(primes,0,sizeof(primes));
	primes[1] = 2;
	primes[2] = 3;
	primes[3] = 5;
	primes[4] = 7;
	primes[5] = 11;
	primes[6] = 13;
	primes[7] = 17;
	primes[8] = 19;
	primes[9] = 23;
	primes[10] = 29;
	primes[11] = 31;
	primes[12] = 37;
	primes[13] = 41;
	cin >> T;
	for(int i = 1;i <= T;i ++)
	{
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
		cout << n << endl;
	}
	return 0;
}
