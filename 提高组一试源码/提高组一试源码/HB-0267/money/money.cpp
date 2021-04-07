#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std; //register
bool vis[25000*3];
int a[105];
bool check(int n)
{
	for(int i=1;i<=n;i++) if(!vis[a[i]]) return false;
	return true;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--)
	{
		memset(vis,0,sizeof vis);
		int n; scanf("%d",&n);
		for(register int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		int maxn=a[n];
		for(register int i=0;i*a[1]<=maxn;i++)
		{
			vis[i*a[1]]=1; //选最小的一个 
		}
		if(check(n))
		{
			printf("1\n");
			continue;
		}
		int ans=1;
		for(register int i=2;i<=n;i++)
		{
			if(vis[a[i]]) continue; //当前已经被筛掉了 
			for(register int j=0;j<=maxn;j++) //用当前的来筛 
			{
				if(vis[j])
				for(register int k=j;k<=maxn;k+=a[i])
				{
					vis[k]=1;
				}
			}
			ans++;
			if(check(n))
			{
				printf("%d\n",ans);
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
