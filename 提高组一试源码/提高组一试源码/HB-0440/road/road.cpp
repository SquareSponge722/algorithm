#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
const int maxh=10005;
struct node{
	int h,id;
}a[maxn];
int n,h[maxn],ans=0,minh=maxh;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	h[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(h[i]-h[i-1]>0)
		{
			ans+=h[i]-h[i-1];
		}
	}
	printf("%d",ans);
	return 0;
}
