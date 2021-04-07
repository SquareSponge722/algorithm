#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int N=10000050;
int n;
int d[N],dis[N];
int num;
int sum,tim,ans;
int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	int maxv=0;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		if(maxv<d[i])
		{
			maxv=d[i];
			num=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==maxv)ans++;
	}
	for(int i=1;i<=n;i++)
		{
			if(d[i]<maxv)sum=max(sum,maxv-d[i]);
			if(d[i]==maxv)
			{
				tim+=sum;
				sum=0;
				continue;
			}
		}
	if(n==1)
	{
		cout<<d[1];
		return 0;
	}
	if(num>1&&num<n)
	{
		if(ans==1)cout<<tim+maxv-1;
		else cout<<tim+maxv-1;
		return 0;
	}
	if(num==n)
	{
		cout<<tim+maxv-1;
		return 0;
	}
	if(num==1)
	{
		if(ans==1)
		cout<<tim+maxv+2;
		else
		cout<<tim+maxv;
		return 0;
	}
}
