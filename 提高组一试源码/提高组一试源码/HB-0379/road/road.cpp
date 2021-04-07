#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define N 100000
using namespace std;
int n,sum=1<<30,summ=1,x,maxn,mmax;
int l,r;
int a[N];//ÏÂÏÝÉî¶È 
int b[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=min(sum,a[i]);
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==maxn)
		{
			mmax=i;
		}
		a[i]-=sum;
	}
	while(a[mmax]!=0)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1&&a[1]!=0)
			{
				l=1;
			}
			if(a[i-1]==0&&a[i]!=0)
			{
				l=i;
			}
			if((a[i-1]!=0&&a[i]==0)||(i==n&&a[i]!=0))
			{
				if(i!=n)
				{
					r=i-1;
				}
				else
				{
					r=i;
				}
				for(int j=l;j<=r;j++)
				{
					b[++x]=a[j];
				}
				sort(b+1,b+1+x);
				sum+=b[1];
				for(int i=l;i<=r;i++)
				{
					a[i]-=b[1];
				}
				
				
				memset(b,0,sizeof(b));
				x=0;
				l=0;
				r=0;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}

