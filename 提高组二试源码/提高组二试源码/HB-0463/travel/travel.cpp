#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int a[5005],ans[5005];
int n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int  cnt=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int c,d;
		cin>>c>>d;
		if(a[c]==0)
		{
			ans[++cnt]=c;
			a[c]=1;
		}
		if(a[d]==0)
		{
			ans[++cnt]=d;
			a[d]=1;
		}
	}
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<" ";
	return 0;
}
