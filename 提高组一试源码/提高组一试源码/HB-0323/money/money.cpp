#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,mi;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		mi=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			int a;
			scanf("%d",&a);
			for(int q=1;q<j;q++)
			if(a%q==0)
				mi++:
		}
		printf("%d\n",n-mi);
	}
	return 0;
}
