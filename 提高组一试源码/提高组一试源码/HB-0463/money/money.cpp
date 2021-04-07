#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int a[1010];
int s[25005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=a[1];i++)
		{
			s[i]=0;
		}
		if(a[1]==1)
		{
			cout<<1<<endl;
			continue;
		}
		for(int i=2;i<=n;i++)
		{
			int mmp=a[i]%a[1];
			if(s[mmp]==0)
			{
				ans++;
				s[mmp]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
