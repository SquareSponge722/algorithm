#include<bits/stdc++.h>
using namespace std;
int a[10000],n[100];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n,m,k;
	cin>>t;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
    }
	m=a[1];
	for(int i=1;i<=n;i++)
	{
		if(m>a[i])
		m=a[i];
	}
	if(n>m-1)
	cout<<m-1<<endl;
	if(n<m)
	cout<<n<<endl;
}
