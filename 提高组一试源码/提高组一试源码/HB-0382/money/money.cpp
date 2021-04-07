#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int t,n,a[110],ans;
bool f[25010];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int i,j;
	
	cin>>t;
	
	while (t--)
	{
		cin>>n;
		ans=n;
		
		for (i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		
		sort(a+1,a+n+1);
		
		memset(f,false,sizeof(f));
		
		f[0]=true;
		
		for (i=1;i<=n;++i)
		{
			if (f[a[i]])
			{
				--ans;
			}
			for (j=0;a[i]+j<=25000;++j)
			{
				if (f[j])
				{
					f[a[i]+j]=true;
				}
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
