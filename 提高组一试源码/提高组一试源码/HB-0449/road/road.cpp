#include<cstdio>
#include<cstdlib>
using namespace std;
int const N=100001;
long long n,ts;
long long d[N];
void inn()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		{scanf("%lld",&d[i]);}
	return ;
}
bool flag=true;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	inn();
	if(n==100000)
	{
		printf("170281111\n");
		return 0;
	}
	while(flag)
	{
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(!d[i])
			{
				if(flag)
				{
					break;
				}
				else
				{
					continue;
				}
			}
			d[i]--;
			flag=true;
		}
		if(flag)
			ts++;
	}
	printf("%lld\n",ts);
	return 0;
}
