#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,min,MIN=100000,A=0,z=1,n;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		A=0;z=1;
		int a[n+1],b[n+1];
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			if(j==1)min=a[j];
			else if(a[j]<min)min=a[j];
		}
		for(int x=1;x<=n;x++)
		{
			if(a[x]%min!=0&&a[x]!=min)
			{
			b[z]=a[x];
			if(b[z]<MIN)MIN=b[z];
			z++;
		    }
		}
		for(int j=1;j<=z;j++)
		{
			if(b[j]<(min*MIN-min-MIN))A++;
		}
		cout<<A<<endl;
	}
	return 0;
}
