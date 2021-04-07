#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,n,m;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])
		ans+=a[i]-a[i-1];
	}
	cout<<ans;
	return 0;
}
