#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
int a[10001];
using namespace std;
int main()
{	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,t,sum=0,fl=0,ffl=0,fffl=0,ffffl=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(a)
	{
		for(int i=1;i<=n;i++)
		{	
			if(a[i]!=0)a[i]--;
			if(a[i]==0&&fl==0)
			{
				t=i;
				fl=1;
				sum++;
				break;
			}
		}
		sum++;
		if(a[1]==0)break;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)ffffl=1;
	}
	if(ffffl==0)cout<<sum-1;
	if(ffffl!=0)
	{
	while(a)
	{
	while(a)
	{
		for(int i=t+1;i<=n;i++)
		{
			if(a[i]!=0)a[i]--;
			if(a[i]==0&&ffl==0)
			{
				t=i;
				ffl=1;
				sum++;
				break;
			}
		} 
		sum++;
		if(a[t+1]==0)break;
	}
	for(int i=i;i<=n;i++)
	{
		if(a[i]!=0)fffl==1;
	}
	if(fffl==0)break;
	}	
	cout<<sum;
	}
	return 0; 
}
