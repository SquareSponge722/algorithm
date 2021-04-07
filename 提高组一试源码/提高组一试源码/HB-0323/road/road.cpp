#include <cstdio>
#include <algorithm>
using namespace std;
int n,cnt,cmax;
int a[200010],book[200010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int maxim=0;
	{
		A:int mini=999999999;
		int t=1,now=1;
		for(int i=1;i<=n;i++,now++)
		{
			if(mini>a[i]&&a[i]>0)
			{
				mini=a[i];
			}//printf("%d ",mini);
			if(a[i]==0||i==n)
			{
				if(i==n) now++;
				for(int j=t;j<=now-1&&a[j]!=0;j++)
				{
					a[j]-=mini;
				}
				if(mini!=999999999) cnt+=mini;
				//printf("%d\n",mini);
				t=now+1;
				if(i==n) now--;
				mini=999999999;
			}
		}	
		for(int o=1;o<=n;o++)
			if(a[o]>0)goto A;
	}

	printf("%d",cnt+maxim);
	return 0; 
}
