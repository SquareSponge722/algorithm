#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+100;
const int inf=1e8;
int a[maxn];
int n,ans;

void work(int l,int r)
{
	if(l>r) return;
	for(int i=l;i<=r;i++)
	{
		if(a[i]==0) { work(l,i-1);work(i+1,r);return; }
	}
	int minn=inf;
	for(int i=l;i<=r;i++)
	{
		if(a[i]<minn)
			minn=a[i];
	}
	ans+=minn;
	for(int i=l;i<=r;i++)
	{
		a[i]-=minn;
	}
	for(int i=l;i<=r;i++)
	{
		if(a[i]==0) { work(l,i-1);work(i+1,r);return; }
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	work(1,n);
	printf("%d\n",ans);
	return 0;	
}
