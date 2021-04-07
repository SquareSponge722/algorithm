#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;
const int N=105;
int T,n,d[N],a[N],flag[N],ans;
void init()
{
	memset(d,0,sizeof(d));
	memset(a,0,sizeof(a));
	memset(flag,1,sizeof(flag));
}
bool f=false;
bool dfs(int x,int sum,int pos,int i,int s)
{
	if(sum==d[i])
	{
		f=true;
		return true;
	}
	if(f==true)
		return true;
	for(int k=s;k<=d[i]/x;k++)
	{
		if(sum+k*x<d[i])
		{
			sum+=k*x;
			dfs(x,sum,pos,i,k);
			sum-=k*x;
			dfs(d[pos+1],sum,pos+1,i,1);
		}
		else if(sum+k*x==d[i])
		{
			f=true;
			break;
		}
	}
	if(f==true)
		return true;
	else
		return false;
}
void work()
{
	if(d[0]==1)
	{
		printf("1\n");
		return ;
	}
	if(d[0]==2)
	{
		printf("2\n");
		return ;
	}
	else
	{
		sort(d+1,d+d[0]+1);
		ans=d[0];
		for(int i=3;i<=d[0];i++)
		{
			f=false;
			int temp=dfs(d[1],d[1],1,i,1);
			ans-=temp;
		}
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		memset(flag,1,sizeof(flag));
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
			{
				if(flag[i])
				{
					if(a[j]%a[i]==0)
					{
						flag[j]=false;
					}
				}

			}
		for(int i=1; i<=n; i++)
			if(flag[i])
				d[++d[0]]=a[i];
		work();
	}
}
