#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define N 10
#define M 100010
#define P 1000000007
using namespace std;
long long m,n,c[M],sum=1,maxv;
string r;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<m+n;i++)
	{
		if(i<n)c[i]=i+1;
		else
		{
			if(i>=n&&i<=m)c[i]=n+1;
			else c[i]=i-m+1;
		}
	}
	for(int i=1;i<m+n;i++)sum=(sum*c[i])%P;
	cout<<sum;
	return 0;
}
