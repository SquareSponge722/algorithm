#include <cstdio>
using namespace std;
int n,a[100003],ans,mina;
void clear(int i,int j,int p)
{
	for(int k=i;k<=j;k++)
		a[k]-=p;
	ans+=p;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		while(a[i]!=0)
		{
			mina=2147483646;
			for(j=i;j<=n;j++)
			{
				if(a[j]<mina)
					mina=a[j];
				if(a[j+1]==0)
				{
					clear(i,j,mina);
					break;
				}
			}
		}
	printf("%d",ans);
	/*for(i=1;i<=n;i++)
		printf("%d ",a[i]);*/
	return 0;
}
