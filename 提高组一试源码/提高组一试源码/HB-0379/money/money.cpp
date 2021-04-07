#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define N 50000
using namespace std;
int n,T,sums,sum,maxn;
int a[N],f[N],flag[N];
int yinshu(int x)
{
	for(int i=2;i<x;i++)
	{
		if(x%i==0&&flag[i]==1)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("money.in","r",stdin);
	freoprn("money.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(flag,0,sizeof(flag));
        maxn=0;
		sum=0;
		sums=0;
		n=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			maxn=max(maxn,a[j]);
			sums+=a[j];
			flag[a[j]]=1;
		}
		for(int j=1;j<=n;j++)
		{
			sum-=yinshu(a[j]);
		}
		f[0]=1;
		sort(a+1,a+1+n);
		sum+=n;
		for(int k=1;k<=n;k++)
		{
			for(int j=sums;j>0;j--)
			{
				if(f[j-a[k]]==1)
				{
					f[j]=1;
					if(flag[j]==1&&a[k]<j)
					{
						sum--;
					}
				}
			}
		}
		cout<<sum;
	}
	return 0;
}
