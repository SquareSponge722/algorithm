#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
int a[101];
using namespace std;
int main()
{	
	freopen("money.in","r",stdin);
	freopen("mopney.out","w",stdout);
	int t,n,fl=0,ffl=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=t;i++)
	{
		if(n==2)cout<<"2"<<" ";
		if(n==3)
		{	
			if(a[2]%a[i]==0)fl=1;
			for(int i=0;i<=a[3]*1.0/a[1];i++)
			{
				for(int j=0;j<=a[3]*1.0/a[2];j++)
				{
					if(a[1]*i+a[2]*j==a[3])
					fl=1;
					break;
				}
			}
			if(fl==1)cout<<"2"<<" ";
			else
				cout<<"3"<<"";
			}
		if(n==4)
		{   
			if(a[2]%a[1]==0)fl=1;
			for(int i=0;i<=a[3]*1.0/a[1];i++)
			{
				for(int j=0;j<=a[3]*1.0/a[2];j++)
				{
					if(a[1]*i+a[2]*j==a[3])
					fl=1;
					break;
				}
			}
			for(int i=0;i<=a[4]*1.0/a[1];i++)
			{
				for(int j=0;j<=a[4]*1.0/a[2];j++)
				{
					if(a[1]*i+a[2]*j==a[4])
					ffl=1;
					break;
				}
			}
			for(int i=0;i<=a[4]*1.0/a[1];i++)
			{
				for(int j=0;j<=a[4]*1.0/a[3];j++)
				{
					if(a[1]*i+a[3]*j==a[3])
					fl=1;
					break;
				}
			}
			for(int i=0;i<=a[4]*1.0/a[2];i++)
			{
				for(int j=0;j<=a[4]*1.0/a[2];j++)
				{
					if(a[1]*i+a[2]*j==a[3])
					ffl=1;
					break;
				}
			}
			if(fl==0&&ffl==0)cout<<"4";
			if(fl==0&&ffl==1)cout<<"3";
			if(fl==1&&ffl==0)cout<<"3";
			if(fl==1&&ffl==1)cout<<"2";
			if(n>=5)cout<<"n"<<" ";
		}
	}
	
	return 0; 
}
