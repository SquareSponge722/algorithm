#include<bits/stdc++.h>
using namespace std;
int a[100002];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
	int sum=0;
		for(int i=1;i<n;i++)
		{
			sum=abs(a[i]-a[i+1])+sum;
		}
    cout<<sum;
		return 0;
}
