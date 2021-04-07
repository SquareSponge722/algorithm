#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mn = 100005;
int n,ans;
int a[mn];
int main()
{
	int tmp=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=tmp=a[1];
	for(int i=2;i<=n;i++)
	{
		if(tmp>a[i])
			tmp=a[i];
		else {
			if(a[i]>tmp)
			{
				ans += a[i]-tmp;
				tmp=a[i];
			}
		}
	}
	printf("%d",ans);
	return 0;
}


