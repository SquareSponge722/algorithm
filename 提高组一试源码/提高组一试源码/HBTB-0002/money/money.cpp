#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000001],fm=2147483640;
int main()
{
	freopen("monry.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int iu=1;iu<=t;iu++)
	{
		scanf("%d",&n);
		fm=2147483640;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			fm=min(fm,a[i]);
		}
		cout<<(fm-1)/2<<endl;
	}
}
