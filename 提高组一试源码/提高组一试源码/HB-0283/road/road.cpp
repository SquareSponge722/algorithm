#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=999999999;
int n;
int a[100001];
int maxn;
int minn=INF;
int ans;
int done[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	ans+=minn;
	for(int i=1;i<=n;i++)
	{
		a[i]-=minn;
		if(a[i]==0)
		{
			done[i]=1;
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");*/
	while(1)
	{
		int flag=0;
		int st=0;
		int ed=0;
		for(int i=1;i<=n;i++)
		{
			if(done[i]==0)
			{
				st=i;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			break;
		}
		for(int i=st;i<=n;i++)
		{
			if(done[i]==1)
			{
				ed=i;
				break;
			}
		}
		if(!ed)
		{
			ed=n;
		}
		else
		{
			ed--;
		}
		minn=INF;
		for(int i=st;i<=ed;i++)
		{
			minn=min(minn,a[i]);
		}
		ans+=minn;
		for(int i=st;i<=ed;i++)
		{
			a[i]-=minn;
			if(a[i]==0)
			{
				done[i]=1;
			}
		}
		/*for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");*/
	}
	printf("%d",ans);	
	return 0;
}
/*
6
4 3 2 5 3 5
*/
/*
6
2 2 2 2 2 2
*/
/*
6
2 0 10 1 2 3
*/