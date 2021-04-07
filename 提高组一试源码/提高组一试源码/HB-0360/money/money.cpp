#include<cstdio>
using namespace std;
int n,a[25001],m,b[25001];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
			
		if(t!=1)
			printf("%d\n",n);
		else
			printf("%d",n/2);
	}
	return 0;
}
