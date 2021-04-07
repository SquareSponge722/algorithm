#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int n,m,a[100001],b[100001],c[100001],sumz=1,d[100001],e[100001],mina=10000,zzz,f[1000001],q,cc,sumaaa=0,must[100];
void ddd(int x)
{
	
	for(int j=x;j>=1;j--)
	{
		q=e[j];
		for(int i=1;i<=m;i++)
		{
			if(a[i]==q&&c[b[i]]!=1)
			{
				zzz=b[i];
				
				if(mina>zzz)
					mina=zzz;
			}
			if(b[i]==q&&c[a[i]]!=1)
			{
				zzz=a[i];
				
				if(mina>zzz)
					mina=zzz;
			}
		
		}
			if(mina==10000)
			{
				ddd(e[x-1]);
			}
	}
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	}
	c[1]=1;
	e[sumz]=1;
	for(int i=1;i<=n-1;i++)
	{
		sumz++;
		ddd(sumz-1);
		if(sumaaa>0)
		{
			if(must[2]>0)
				e[sumz]=min(must[1],must[2]);
			else
				e[sumz]=must[1];
			c[e[sumz]]=1;
			sumaaa=0;
			must[1]=0;
			must[2]=0;
		}
		else
		{
			e[sumz]=mina;
			c[mina]=1;
		}
		
		
		
		mina=10000;
	}
	for(int i=1;i<=n;i++)cout<<e[i]<<" ";
	return 0;
}
