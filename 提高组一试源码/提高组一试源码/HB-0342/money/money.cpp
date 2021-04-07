#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 25005
using namespace std;
int T,n,a[MAXN],prim[MAXN],ans,flag;
void dfs(int x,int o,int y)
{
	if(flag) return ;
	if(y==0)
	{
		flag=true;
		return ;
	}
	if(o==0) return ;
	if(x!=o&&y>=a[o])
	{
		dfs(x,o-1,y%a[o]);
	}
	dfs(x,o-1,y);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		ans=n;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
		}
		if(n==2)
		{
			if(a[1]%a[2]==0||a[2]%a[1]==0)
			{
				printf("1\n");
				continue;
			}
			else
			{
				printf("2\n");
				continue;
			}
		}
		else if(n==3)
		{
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
				{
					if(i!=j&&a[i]&&a[j]&&a[i]%a[j]==0)
					{
						a[i]=0;
						ans--;
					}
				}
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					for(int k=1; k<=n; k++)
					{
						if(i!=j&&j!=k&&i!=k&&a[i]&&a[j]&&a[k])
						{
							if((a[k]%a[i])%a[j]==0)
							{
								a[k]=0;
								ans--;
							}
						}
					}
			printf("%d\n",ans);
		}
		else
		{
			sort(a+1,a+1+n);
			for(int i=1; i<=n; i++)
			{
				flag=false;
				dfs(i,n,a[i]);
				if(flag)
				{
					ans--;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
1
32
75 82 61 70 68 67 85 83 74 66 65 51 59 38 45 13 64 72 50 84 80 78 53 48 47 76 71 62 54 46 81 69
*/
