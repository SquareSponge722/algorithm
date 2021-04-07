#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;
short a[101000];
int top=1;
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=top;i<=n;i++)
	{
		a[i]--;
		while(a[top]<=0) top++;
		if(a[i+1]<=0)
		{
			i=top-1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
