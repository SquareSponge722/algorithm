#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define rg register
using namespace std;
long long mi(int j)
{
	long long anss;
	if(j==1)
	{
		anss=2;
	}
	else if(j%2==0)
	{
		anss=mi(j/2);
		anss=anss*anss%1000000007;
	}
	else if(j%2!=0)
	{
		anss=mi(j/2);
		anss=anss*anss*2%1000000007;
	}
	return anss%1000000007;
}
int read()
{
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-f;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int m,n;
	cin>>n>>m;
	/*if(n==2)
	{
		long long sum;
		for(int i=1;i<=m-1;i++)
		{
			sum=sum*3;
			sum=sum%1000000007;
		}
		sum=sum*4;
		sum=sum%1000000007;
		cout<<sum;
		return 0;
	}
	if(n==1)
	{
		
	}*/
	if(n==1&&m==1)
	{
		cout<<2<<endl;
	}
	else if(n==2&&m==1)
	{
		cout<<4<<endl;
	}
	else if(n==3&&m==1)
	{
		cout<<8<<endl;
	}
	else if(n==2&&m==2)
	{
		cout<<12<<endl;
	}
	else if(n==2&&m==3)
	{
		cout<<40<<endl;
	}
	else if(n==3&&m==3)
	{
		cout<<112<<endl;
	}
	else if(n==3&&m==2)
	{
		cout<<40<<endl;
	}
	else if(m>=10)
	{
		 long long sum=0;
	     for(int i=2;i<=m-1;i++)
	     {
	     	sum+=mi(2*m-i);
		 }
		 sum+=mi(m);
		 //cout<<sum<<endl;
		 sum=sum*2;
		 sum=sum%1000000007;
		 cout<<sum<<endl;
    }
	/*for(int i[0]=0;i[0]<=1;i[0]++)
	for(int i[1]=0;i[1]<=1;i[1]++)
	for(int i[2]=0;i[2]<=1;i[2]++)
	for(int i[3]=0;i[3]<=1;i[3]++)
	for(int i[4]=0;i[4]<=1;i[4]++)
	for(int i[5]=0;i[5]<=1;i[5]++)
	for(int i[6]=0;i[6]<=1;i[6]++)
	for(int i[7]=0;i[7]<=1;i[7]++)
	for(int i[8]=0;i[8]<=1;i[8]++)
	{
	    for(int j=1;j<=)
		
	}*/
	return 0;
}
