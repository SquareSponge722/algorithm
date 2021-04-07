#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int t,n,a[1000];
int main()
{	
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n==2)
		{
			for(int i=1;i<=n;i++)
			cin>>a[i];
			if(a[2]%a[1]==0||a[1]%a[2]==0)
			cout<<1<<endl;
			else
			cout<<2;
			
		}
			else
			{	
				for(int i=1;i<=n;i++)
					cin>>a[i];
				if(n%2==0)
				cout<<n/2<<endl;
				else
				cout<<n;
			}
		
	}
	return 0;
}
