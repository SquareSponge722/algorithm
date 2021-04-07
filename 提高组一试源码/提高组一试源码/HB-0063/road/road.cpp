#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,ans;
void dfs(int l,int r)
{
	if(l>r) return ;
	if(a[l]==0) return ;
	int mid=1000005;
	for(int i=l;i<=r;i++)
	{
		if(mid>a[i])
			mid=a[i];
	}
	int left=l;
	ans+=mid;
	for(int i=l;i<=r;i++)
	{
		a[i]-=mid;
		if(a[i]==0)
		{
			dfs(left,i-1);
			left=i+1;
		}
	}
	if(left<=r) dfs(left,r);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(1,n);
	printf("%d",ans);
	return 0;
}
