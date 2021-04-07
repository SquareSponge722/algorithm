#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int a[100001];
bool b[100001]={0};
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		m=n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	for(int i=n;i>=1;i--)
	for(int j=1;j<=i;j++)
	if(a[j]>a[j+1]) 
	swap(a[j],a[j+1]);
	for(int i=2;i<=n;i++)
	{
		if(a[i]%a[1]==0) m--;
		b[i]=1;	
	}
	int i;
	while(!b[i])
	{
		if(a[i]%a[1]!=0) i=k;
		k=a[i];break;
	}
	for(i=k;i<=n;i++)
		if(a[i]%a[k]%a[1]==0) m--;
		else cout<<m<<endl;
	return 0;
}
