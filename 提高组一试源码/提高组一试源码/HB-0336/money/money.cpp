#include <cstdio>
#include <algorithm>

using namespace std;

int T,n,a[120];
bool cmp(int a,int b){return a>b;}
namespace point1
{
	void work()
	{
		sort(a+1,a+n+1,cmp);
		if(a[2]%a[1]==0 || a[1]%a[2]==0)
			printf("1\n");
		else
			printf("2\n");
	}
}

namespace point4
{
	void work()
	{
		sort(a+1,a+n+1,cmp);
		if(a[2]%a[1]==0)
		{
			if(a[3]%a[1]==0)
				printf("1\n");
			else
				printf("2\n");
		}
		else
		{
			if(a[3]%a[1]==0)
				printf("2\n");
			else 
			{
				if(a[3]%a[2]==0)
					printf("2\n");
				else
					printf("3\n");
			}
		}
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n==2)
			point1::work();//point_1,2,3
		else if(n==3)
			point4::work();//point_4,5,6
	}
	return 0;
}