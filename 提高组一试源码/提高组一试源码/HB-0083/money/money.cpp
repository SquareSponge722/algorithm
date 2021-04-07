#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define N 10000
using namespace std;
int n,a[N],T;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i];
	}
	return 0;
}
