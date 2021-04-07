#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int t,n,rec;
int a[25];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--)
	{
		rec=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		if(n==2)
		{
			if(a[2]%a[1]==0)cout<<1<<endl;
			else cout<<2<<endl;
		}
		else if(n==3)
		{
			if(a[2]%a[1]==0&&a[3]%a[1]==0)cout<<1<<endl;
			else if(a[2]%a[1]==0||a[3]%a[1]==0)cout<<2<<endl;
			else 
			{
				for(int i=1;i<=a[3]/a[1];i++)
				for(int j=1;j<=a[3]/a[2];j++)
				if(a[1]*i+a[2]*j==a[3])rec=1;
				if(rec==1)cout<<2<<endl;
				else cout<<3<<endl;
				
			}
		}
		else cout<<n<<endl;
	}
	return 0;
}
