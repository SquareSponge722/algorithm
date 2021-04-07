#include<bits/stdc++.h>
using namespace std;
long long a[10000][9999];
long long b[9999];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	long long x,n,i,j;
	cin>>x;
	for(i=1;i<=x;i++)
	{
		cin>>n;
		b[i]=n;
		for(j=1;j<=n;j++)
		cin>>a[i][j];
	}
	
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=n;j++);
		{
			for(int k=1;k<j;k++)
			{
				for(int l=1;l<k;l++)
		{
		if(a[i][j]%a[i][k]==0||a[i][j]%a[i][k]%a[i][l]==0)
		b[i]=b[i]-1;
		}
		    }
		}
	}
	for(i=1;i<=x;i++)
	cout<<-b[i];
	return 0;
}

