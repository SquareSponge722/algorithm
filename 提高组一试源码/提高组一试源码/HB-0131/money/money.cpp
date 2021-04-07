#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int t;
int f[101][250001],hash[101];
int ans;

int dp(int n,int a[])
{
	int t1,t2;
	ans=0;
	for(int i=1;i<=n;i++)
	hash[i]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=a[n];j++)
		f[i][j]=0;
	f[0][0]=1;
	hash[1]=1;
	for(int i=n;i>=2;i--)
	{
		for(int k=1;k<i;k++)
		for(int j=0;j<=a[i];j++)
		{
			f[k][j]=f[k-1][j-a[k]];
 			if(j%a[k]==0||f[k-1][j]==1)f[k][j]=1;
		}
		if(f[i-1][a[i]]==0) hash[i]=1;
	}
	for(int i=1;i<=n;i++)
	if(hash[i]==1)ans++;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	int n,a[101];
	for(int o=1;o<=t;o++)
	{
		cin>>n;
		for(int g=1;g<=n;g++)
			cin>>a[g];
		sort(a+1,a+n+1);
		dp(n,a);
		cout<<ans<<endl;
	}
	return 0;
}
