#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define N 100010
using namespace std;
int m,a[N],sum,t;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>m>>sum;
	sum=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(i==1)
		{
			sum+=z;
			t=y;
		}
		if(t==x)
		{
			sum+=z;
			t=y;
		}
	}
	cout<<sum;
}
