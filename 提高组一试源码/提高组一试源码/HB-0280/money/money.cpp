#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T; const int S=110;
int a[S]; int n;
int b[S]; int m;
bool x[500500];
int max_val;
void work()
{
	for(int i=1;i<=n;i++)
	{
		if(!x[a[i]])
		{
			m++;
			for(int j=0;j<=max_val;j++)
			{
				if(!x[j]) continue ;
				for(int k=1;j+k*a[i]<=max_val;k++)
					x[j+k*a[i]]=true;
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
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1); max_val=a[n];
		
		memset(x,0,sizeof(x));
		x[0]=true;
		m=0;
		work();
		printf("%d\n",m);
	}
	return 0;
}
