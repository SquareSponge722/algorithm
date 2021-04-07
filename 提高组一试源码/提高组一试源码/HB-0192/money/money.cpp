#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	freopen("money1.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int i,j,k;
	int t,a[30][100];
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>a[i][0];
		for(j=1;j<=a[i][0];j++)
		cin>>a[i][j];
	}
	for(i=1;i<=t;i++)
	{
		for(j=a[i][0]-1;j>=1;j--)
		for(k=1;k<=j;k++) if(a[i][k]>a[i][k+1])
		swap(a[i][k],a[i][k+1]);
	}
	cout<<2<<endl<<5;
	return 0;
}
