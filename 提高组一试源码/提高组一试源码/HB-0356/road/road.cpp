#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;
#define N 100005
int a[N];
int flag1=0;
long long sum;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	int flag2=n;
	for(register int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(register int k=1;;k++)
	{
		for(register int i=1;i<=n;i++)
	    {
		    if(a[i]!=0)
		    {
			   if(flag1==0)
			  {
			     flag1=i;
			  }
		    }
		    if(a[i]==0&&flag1!=0&&flag2==n)
		    {
		    	flag2=i-1;
			}
	    }
	    for(register int i=flag1;i<=flag2;i++)
	    {
	    	a[i]--;
		}
		sum++;
		flag1=0;
		flag2=n;
		int he=0;
		for(register int i=1;i<=n;i++)
		{
			if(a[i]==0)
			he++;
		}
		if(he==n)
		break;
	}
	cout<<sum;
	return 0;
}
