#include<bits/stdc++.h>
using namespace std;
int n;
long long a,b,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b);
		if(b-a>=0)ans+=b-a;
		a=b;
	}
	printf("%lld",ans);
	return 0;
}
