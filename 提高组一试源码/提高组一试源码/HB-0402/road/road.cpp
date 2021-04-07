#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define N 100005
using namespace std;

int n,minv=10000,a[N],ans,loc,y;
int f[N][21];
struct node
{
	int l,r;
	node(int ll,int rr)
	{
		l=ll;
		r=rr;
	}
};
queue<node>q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(minv>a[i])
		{
			minv=a[i];
			loc=i;
		}
	}
	ans+=minv;
	for(int i=1;i<=n;i++)
	a[i]-=minv;
	if(loc-1>0)
	q.push(node(1,loc-1));
	if(loc+1<=n)
	q.push(node(loc+1,n));
	while(!q.empty())
	{
		node k=q.front();
		q.pop();
		int t=10000;
		int wa[100],s=1;
		for(int i=k.l;i<=k.r;i++)
		{
			if(t>a[i])
			{
				t=a[i];
				wa[s]=i;
			}
		}
		for(int i=k.l;i<=k.r;i++)
			a[i]-=t;
		ans+=t;
		if(wa[s]>k.l)
			q.push(node(k.l,wa[s]-1));
		for(int i=wa[1]+1;i<=k.r;i++)
		if(!a[i])
		{
			wa[++s]=i;
			if(wa[s]>wa[s-1]+1)
			q.push(node(wa[s-1]+1,wa[s]-1));
		}
		if(wa[s]<k.r)
		q.push(node(wa[s]+1,k.r));
	}
	printf("%d",ans);
}
