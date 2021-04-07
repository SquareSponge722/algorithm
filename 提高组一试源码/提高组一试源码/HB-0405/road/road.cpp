#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,ans=0,min=1000005;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
	if(a[i]<a[i-1]) ans+=a[i-1]-a[i];
	cout<<ans+a[n]<<endl;
	return 0;
}
