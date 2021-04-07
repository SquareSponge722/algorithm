#include<bits/stdc++.h>
using namespace std;
int t,ans;
int a[101],b[101];
int f[25001];
void check(int s[],int n)
{
			for(int i=n;i>1;i--)
			{
			memset(f,0,sizeof(f));
			for(int j=1;j<i;j++)
			{
				for(int l=1;l<=s[i]/s[j];l++)
				f[s[j]*l]=1;
			}
			for(int j=1;j<=i;j++)
			{
				for(int l=s[i];l>=s[1];l--)
				{
					if(f[l-s[j]]==1)
					f[l]=1;
				}
			}
			if(f[s[i]])
			ans--;
			}
		return;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		ans=0;
		cin>>n;
		memset(b,0,sizeof(b));
		for(int j=1;j<=n;j++)
		cin>>a[j];
		sort(a+1,a+n+1);
		for(int j=2;j<=n;j++)
		for(int k=j-1;k>=1;k--)
		{
			if(a[k])
			if(a[j]%a[k]==0)
			a[j]=0;
		}
		for(int j=1;j<=n;j++)
		if(a[j])
		b[++ans]=a[j];
		check(b,ans);
		cout<<ans<<endl;
	}
	return 0;
}
