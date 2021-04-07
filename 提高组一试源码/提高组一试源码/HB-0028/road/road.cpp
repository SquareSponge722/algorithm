#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#define M 1010001
using namespace std;
int n,a[M],b[M];
int road (int l,int r)
{
	int ans=1;
	if (l==r)
	{
		return a[l];
	}
	for (int i=l;i<=r;i++)
	{
		b[i]=a[i];
	}
	sort(b+l,b+r+1);
	for (int i=l;i<=r;i++)
	{
		a[i]=a[i]-b[l];
	}
	int i=l,j=l;
	while (j<=r)
	{
		j++;
		if (a[j]==0)
		{
			ans=ans+road(i,j-1);
			i=j+1;
		}
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int f=road(1,n);
	printf("%d",f);
	return 0;
}

