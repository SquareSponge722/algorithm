#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int mn=110;
int T;
int n,m;
int a[mn];
bool exist[mn];
int fir,sec;
int cal(int a,int b)
{
	int c;
	c=a*b-a-b;
	return c;
}
bool cal2(int pos,int x)
{
	if(x==fir || x==sec)
	{
		return 0;
	}
	for(int i=1;i*fir<x;i++)
		for(int j=1;j*sec<x;j++)
			if(i*fir+j*sec==x)
				return 1;
}
void init()
{
	memset(a,0,sizeof(a));
	memset(exist,1,sizeof(exist));
	cin>>n;
	m=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	  sort(a+1,a+n+1);
}
void work()
{
	if(a[1]==1)
	{
		m=1;
	}
	else{
		int sec=25100;
		for(int i=2;i<=n;i++)
			if(a[i]&a[1]==0)
				exist[i]=0;
				else sec=min(a[i],sec);
					int fir=a[1];
					//cout<<"__________________"<<endl;
					//cout<<"m="<<m<<endl;
					//cout<<"first"<<fir<<endl;
					//cout<<"second"<<sec,,endl;
					int maxa=cal(fir,sec);
					for(int i=1;i<=n;i++)
						if(a[i]>maxa&&exist [i])
						{
							exist[i]=0;
							m--;
						}
						else if(a[i]<=maxa && exist[i])
						{
							if(cal2(i,a[i]))
							{
								exist[i]=0;
								m--;
							exist[i]=cal2(i,a[i])
						}
					}
							
		cout<<m<<endl;
	}
}
int main()
{
	//freopen("money.in","r",stdin);
   //freopen("money.out","w",stdout);
	cin>>T;
	while(T--)
	{
	init();
	work();
	}
return 0;
}
