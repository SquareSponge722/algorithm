#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int ans,n,a[maxn];
void work(int l,int r)
{
	if(l==r)
	{
		ans+=a[l];
		a[l]=0;
		int mi=INF_MAX;
		for(int i=l;i<=r;i++)
		mi=min(mi,a[i]);
		ans+=mi;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	while(ans!=0)
	{
		for(int i=1;i<=r;i++)
		mi=min(mi,a[i]);
		ans+=mi;
		n++;
	}
	else
	printf("%d",n);
}
