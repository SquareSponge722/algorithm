#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int t,a[10000];

void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n == 1) cout<<1<<endl;
	else if(n == 2)
	{
		if(a[2] <= a[1])swap(a[1],a[2]);
		if(a[2]%a[1] == 0) cout<<1<<endl;
		else cout<<2<<endl;
	}
	return;
}


int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		solve();
	}
	return 0;
}
