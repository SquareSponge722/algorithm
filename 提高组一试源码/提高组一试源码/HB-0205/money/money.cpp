#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N=1e2+5;
int a[N];
int n,t;

int gcd(int a,int b)
{
	for (int i=max(a,b);i>=1;i--)
		if (a%i==0&&b%i==0)
			return i;
}

bool solve(int a,int b,int c)
{
	for (int i=1;i<=50;i++)
		for (int j=1;j<=50;j++)
			if ((a*i+b*j)==c)
				return true;
	return false;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t)	;
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		if (n==1)
		{
			printf("1\n");
			continue;
		}
		if (n==2)
		{
			if (gcd(a[1],a[2])!=1)
			{
				printf("1\n");
				continue;
			}
			else
			{
				printf("2\n");
				continue;
			}
		}
		if (n==3)
		{
			int ans=3;
			if ((gcd(a[1],a[2])%gcd(a[2],a[3])==0
		      ||(gcd(a[2],a[3])%gcd(a[1],a[2])==0))
			  && gcd(a[1],a[2])!=1)
			{//有一个数能代替3个 
				printf("1\n");
				continue;
			}
			if ((gcd(a[1],a[2])!=1)||gcd(a[2],a[3])!=1||gcd(a[1],a[3])!=1)
				ans--;//有一个数能代替二个 
			if (solve(a[1],a[2],a[3]))
				ans--;
			printf("%d\n",ans);
			continue;
		}
		printf("%d\n",n);
	}
	return 0;
}
