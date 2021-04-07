#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,ans=0,l,r;
	int d[100005];
	scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&d[i]);
			for(int i=1;i<=n;i++)
			{
				if(d[i]<=0)
				break;
				if(d[i]>=0)
				d[i]-1;
				ans++;
			}
			ans=ans+3;
		printf("%d",ans);
				return 0;
	fclose(stdin);
	fclose(stdout);
}
