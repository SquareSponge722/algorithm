#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
int a[100005],b[100005],ans1,ans2,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		b[i]=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[j]==0) break;
			a[j]--;
			ans1=i;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=n;j>=1;j--)
		{
			if (b[j]==0) break;
			b[j]--;
			ans2=i;
		}
	}
	ans=ans1+ans2;
	cout<<ans;	
	return 0;
}
