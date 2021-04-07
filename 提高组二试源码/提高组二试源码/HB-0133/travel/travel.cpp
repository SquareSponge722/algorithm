#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
int a[5001],b[5001],c[5001],d[5001],p[5001],e;
using namespace std;
int main()
{
	int n,m,fl=0,ffl=0,num=0,t=2,fffl=0,ffffl=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i];
	c[1]=a[1],c[2]=b[1];
	for(int i=3;i<=m;i++)
	{	
		num++;
		for(int j=1;j<=m;j++)
		{
			if(b[j]==c[t]&&a[j]!=c[t-1])
			{
				d[num]=a[j];
				fl=1;
			}
		}
		if(fl==0)d[num]=6000;
		for(int l=1;l<=m;l++)
		{
			if(a[l]==c[t]&&b[l]!=c[t-1])
			{
				p[num]=b[l];
				ffl=1;
			}
		}
		if(ffl==0)p[num]=6000;
		if(p[num]>=d[num]&&fl>0||ffl>0)c[i]=d[num];
		if(p[num]<d[num]&&fl>0||ffl>0)c[i]=p[num];
		t++;
		fl=0;
		ffl=0;
		if(fl==0&&ffl==0)
		{	
			t=t-2;
			for(int k=1;k<=m;k++)
		{
			if(b[k]==c[t]&&a[k]!=c[t-1])
			{
				d[num]=a[k];
				fffl=1;
			}
		}
		if(ffffl==0)d[num]=6000;
		for(int l=1;l<=m;l++)
		{
			if(a[l]==c[t]&&b[l]!=c[t-1])
			{
				p[num]=b[l];
				ffffl=1;
			}
		}
		if(ffffl=0)p[num]=6000;
		if(p[num]>=d[num])c[i]=d[num];
		if(p[num]<d[num])c[i]=p[num];
		}
	}	
	for(int i=1;i<=n;i++)cout<<c[i]<<" ";
	return 0;
}
