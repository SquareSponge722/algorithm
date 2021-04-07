#include <cstdio>

using namespace std;

const long long  base = 1000000000 + 7;

int book[1000000]={0};

void decode(int x)
{
	int min=2;
	while(x>1)
	{
		if(x%min==0)
		{
			min[book]++;
			x/=min;
		} 
		else min++;
	}
	for(int i=1;i<=1000000;i++)
	{
		if(book[i]!=0)
		{
			printf(" %3d^%-2d ",i,book[i]);
		}
	}
}

int main()
{
	printf("%lld\n",((long long)112)*4*4*4);
	//freopen("game.out","w",stdout);
	int target;
	scanf("%d",&target);
	decode(target);
	int n;
	scanf("%d",&n);
	long long sum = 1;
	for(int i=2;i<=n;i++)
	{
		sum *= (i*3-2);
	}
	sum *= (n+1);
	sum = (sum)%base;
	printf("%lld\n",sum);
	return 0;
}

int map[15][15]={0};

int tmain()
{
	

	
	return 0;
}
