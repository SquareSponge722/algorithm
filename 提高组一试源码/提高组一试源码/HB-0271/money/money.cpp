#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int mn = 105;
const int maxn = 25005;
const int inf = 2147483647;

int n,T;
int a[mn],top,st[mn];
int vis[maxn];
bool check(int x)
{
	if(vis[x]==1) return true;
	if(vis[x]==-1)
		return false;
	for(int i=1;i<=top;i++)
	{
		if(x>=st[i] && check(x-st[i]))
		{
			vis[x]=1;
			return true;
		}
	}
	vis[x]=-1;
	return false;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		vis[0]=1;
		top=0;
		scanf("%d",&n);
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)
				flag=true;
		}
		if(flag)
		{
			printf("1\n");
			continue;
		}
		sort(a+1,a+1+n);
		int tmp1=0,ans=0,ret=inf;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=ret && !check(a[i]))
			{
				ans++;
				if(ret==inf)
				{
					for(int j=1;j<=top;j++)
						if(a[i]%a[j]!=0)
						{
							ret = a[i]*a[j]-a[i]-a[j];
							break;
						}
				}
				st[++top]=a[i];
				vis[a[i]]=1;
				//cout<<a[i]<<endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}



