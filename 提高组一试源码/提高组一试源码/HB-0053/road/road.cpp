#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 10001
#define M 101
using namespace std;
long long n,u,r;
long long minn=9999999999,ans;
int d[N];
long long f[N][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	u=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		f[i][1]=d[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				minn=min(minn,f[k][j-1]);
				if(k==n && minn==0)
				{
					ans=j+u-1;
				}
			}
			if(d[i]==0)
			{
				f[i][j]=0;
				u--; 
			}
			else
			{
				f[i][j]=f[i][j-1]-minn;
				u-=minn;                                                                                              
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
