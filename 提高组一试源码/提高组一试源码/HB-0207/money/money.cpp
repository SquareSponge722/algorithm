#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int t;
int n;
int a[100005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	srand(time(NULL));
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
		    scanf("%d",&a[i]);	
		}	
		printf("%d\n",rand()%100000);
	}
	return 0;
}
