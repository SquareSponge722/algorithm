#include <iostream>
using namespace std;
int main() 
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n,a[10005],minn=10005;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		if (n==2)
		{
			for (int j=1;j<=2;j++)
			{
				cin>>a[i];
				if (a[i]<=minn) 
				{
					minn=a[i];
				}
			}
			if (minn==1) cout<<"1"<<endl;
			if (minn!=1) cout<<"2"<<endl;
		}
		minn=10005;
	}
	return 0;
}
