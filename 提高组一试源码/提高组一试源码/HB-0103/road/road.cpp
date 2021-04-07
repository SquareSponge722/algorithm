#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int n;
const int N=100001;
int d[N];
int ans;
int count=0;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]==0)
		count++;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	int min=999999;
	for(int i=1;i<=n;i++)
	{
		if(d[i]<min)
		min=d[i];
	}
	ans=ans+min;
	for(int i=1;i<=n;i++)
	{
		d[i]=d[i]-min;
		if(d[i]==0)
		count++;
	}
	bool first=true;
	while(count!=n)
	{
		int begin=1;
		if(first)
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i]==0 || i==n)
				{
					for(int j=begin;j<i;j++)
					d[i]--;
					ans++;
					begin=i+1;
				}
			}
			first=false;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i]==0 || i==n)
				{
					for(int j=begin;j<=i;j++)
					d[i]--;
					ans++;
					begin=i+1;
					count++;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
