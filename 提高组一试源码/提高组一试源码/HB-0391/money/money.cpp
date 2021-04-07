#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		bool flag=false;
		scanf("%d",&d[i]);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&d[i]);
			if(d[i]==1)
				flag=true;
		}
		if(flag)
			printf("1\n");
		else
		{
			if(n==2)
			{
				if(d[1]%d[2]==0 || d[2]%d[1]==0)
				{
					printf("1\n");
				}
				else
					printf("2\n");
			}
			else
				printf("%d\n",n);
		}
	}
	return 0;
}
