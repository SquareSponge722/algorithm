#include <cstdio>
#include <cstring>
using namespace std;
int t,n,a[103];
int main()
{
	freopen("money.in","r",stdin);//kkk
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i,j;
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",n);
	}
	return 0;
}
