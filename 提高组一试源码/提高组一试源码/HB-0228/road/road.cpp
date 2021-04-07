#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<bits/stdc++.h>
int d[10001];
int sum;
int n;
int day;
using namespace std;
int road(int s)
{
		
		
	for(int i=1;i<=n;i++)
	{
		if(!d[i])sum++;
	}
		if(sum==n) 
		{
		return 0;
	}

		for(int i=1;i<=n+1;i++)
		if((!d[i])&&(d[i-1]!=0)){
		for(int j=1;j<i;j++)
		{
		   if(d[j]) d[j]--;
		} day++;break;
	}
	sum=0;road(s+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>d[i];
	road(1);
    cout<<day;
}
