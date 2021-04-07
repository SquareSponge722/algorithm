#include<cstdio>
#include<cstdlib>
using namespace std;
int n,d[100002];
int min=999999999;
int rest;
long long ans;
void clear(int l,int r)
{
	if(l>r) return ;
	int min=d[l];
	for(int i=l;i<=r;i++)
	{
		if(d[i]<min)
		{
			min=d[i];
		}
	}
	for(int i=l;i<=r;i++)
	{
		d[i]-=min;
		if(d[i]==0)
			rest--;
	}
	ans+=min;
}
void chaz(int l,int r)
{
	int x=l;
	for(int i=l;i<=r;i++)
	{
		if(d[i]==0)
		{
			clear(x,i-1);
			x=i+1;
		}
		else
			if(i==r)
			{
				clear(x,r);
				if(rest!=0)
					chaz(x,r);
			}
	}
}
int main()
{
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	scanf("%d",&n);
	rest=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]<min)
		{
			min=d[i];
		}
	}
	ans+=min;
	for(int i=1;i<=n;i++)
	{
		d[i]-=min;
		if(d[i]==0)
			rest--;
	}
	while(rest)
	{
		chaz(1,n+1);
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i])
			ans+=d[i];
	}
	printf("%d\n",ans);
	return 0;
}
