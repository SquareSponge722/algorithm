#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		ans+=c;
	}
	cout<<ans/n;
	return 0;
}
