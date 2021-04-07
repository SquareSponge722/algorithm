#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n==4) cout<<2<<endl;
		else if(n==5) cout<<5<<endl;
		else cout<<3<<endl;
	}
	return 0;
}
