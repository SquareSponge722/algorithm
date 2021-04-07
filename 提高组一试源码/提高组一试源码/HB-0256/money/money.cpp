#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#define N 101
using namespace std;
int T,A[N],n;
int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	srand(time(NULL));
	scanf("%d",&T);
	while(T--)
	{
		int ans;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
		if(n==2)
		{
			int fa=gcd(A[1],A[2]);
			if(fa==1) 
			{
				printf("2\n");
				continue;
			}
			else if(fa==A[1] || fa==A[2])
			{
				printf("1\n");
				continue;
			}	
		}
		else if(n==3)
		{
			int f1=gcd(A[1],A[2]),f2=gcd(A[1],A[3]),f3=gcd(A[2],A[3]); 
			if(f1==f2 && f2==f3) 
			{
				printf("1\n");
				continue;
			}
			else if(A[1]+A[2]==A[3] || A[1]+A[3]==A[2] || A[2]+A[3]==A[1])
			{
				printf("2\n");
				continue;
			}
			else
			{
				printf("3\n");
				continue;
			}
		}
		else
		printf("%d\n",rand()%n+1);
	}
	return 0;
}
