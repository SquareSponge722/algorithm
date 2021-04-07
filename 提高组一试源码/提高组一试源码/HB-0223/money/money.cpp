#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 110
using namespace std;
int t,n;
int a[N];
int minn=999999;
void init()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<minn)
			minn=a[i];
	}
}
bool check(int x)
{

	for(int i=1; i<=n; i++)
		if(!x%a[i])
			return true;
	return false;
}
int main ()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		minn=0x3f;
		memset(a,0,sizeof(a));
		init();
		if(minn>=n)
			printf("%d\n",n);
		else
		{
			int x=2;
			for(int i=x; i<=n; i++)
			{
				if(check(x))
					x++;
				else
				{
					printf("%d\n",x);
					break;
				}
			}
		}
	}
	return 0;
}
