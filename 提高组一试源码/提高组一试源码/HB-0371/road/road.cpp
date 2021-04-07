#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,i;
int ans=0;
int a[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1;
	while(l<=n)
	{
		int t=0;
		for(i=1;i<=n;i++)
		{
			if(a[l+i-1]!=0) t++;
			else break;
		}
		if(t!=0) ans++;
		for(i=0;i<t;i++) a[l+i]--;
		if(a[l]==0) l++;
	}
	printf("%d",ans);
	return 0;
}
