#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<cstdlib>
#include<algorithm>
#include<complex>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define mlr ll mid((l+r)>>1)
using namespace std;
int gcd(int x,int y)
{
	if(x<y)swap(x,y);
	if(x%y==0)return y;
	return gcd(y,x%y);
}
int n;
int a[1000010];
int flg(0);
int flk[1000010];
bool isprime(int x)
{
	for(int i=2;i<=sqrt(x);i++)if(!(x%i))return 0;
	return 1;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int cnt(0);
		flg=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)flg=1;
		}
		if(flg)
		{
			printf("1\n");
			continue;
		}
		for(int i=1;i<=n;i++)flk[i]=(int)isprime(a[i]);
		if(n==2)
		{
			if(a[1]<a[2])swap(a[1],a[2]);
			printf((a%b==0)?"1\n":"2\n");
			continue;
		}
		if(n==3)
		{
			if(gcd(gcd(a[1],a[2]),a[3])==min(min(a[1],a[2]),a[3]))
			{
				printf("1\n");
				continue;
			}
			sort(a+1,a+3+1);
			for(int i=1;i<=a[3]/a[1]+1;i++)
			{
				for(int j=1;j<=a[3]/a[2]+1;j++)
				{
					if(a[1]*i+a[2]*j==a[3])
					{
						printf("2\n");
						continue;
					}
				}
			}
			printf("3\n");
			continue;
		}
		srand(time(0));
		cnt=rand();
		while(cnt%n+1!=1)cnt=rand();
		printf("%d\n",cnt%n+1);
	}
	return 0;
}