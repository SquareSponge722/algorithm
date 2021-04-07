#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,d[100100]={0},mymin=999999999,ans=0;
bool flag=false;
bool check_num(long long l,long long r)
{
	long long mymin2=999999999;
	for(long long i=l;i<=r;i++)
	{
		mymin2=min(mymin2,d[i]);
	}
	if(mymin2==0)
	{
		return false;
	}
	ans=ans+mymin2;
	for(long long i=l;i<=r;i++)
	{
		d[i]=d[i]-mymin2;
	}
	return true;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		mymin=min(mymin,d[i]);
	}
	ans=ans+mymin;
	for(long long i=1;i<=n;i++)
	{
		d[i]=d[i]-mymin;
	}
	long long l=1,r=n;
	while(l!=n || r!=n)
	{
		while(!check_num(l,r))
		{
			if(r==n && l==n)
			{
				break;
			} 
			if(r!=n)
			{
				l++;
				r++;
			}
			else if(r==n)
			{
				r=r-l;
				l=1;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
