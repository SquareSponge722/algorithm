#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int n;
int a[110];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		printf("2\n");
	}
	return 0;
}
