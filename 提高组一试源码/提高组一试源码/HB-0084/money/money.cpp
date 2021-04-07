#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define rg register
using namespace std;
int maxx=0,c1=0,c2=0,c3=0,c4=0,c5=0,n,anss=0;
int a[101]={0};
bool f[101]={true};
inline int read()
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
	return x*f;
}
void dfs(int num)
{
	int find1=6;
	if(num>=n)
	{
		anss=n;
		return;
	}
	if(num==1)
	{
		for(int j=1;j<=maxx/c1;j++)
		{
			if(a[2]==j*c1)
			{
				f[2]=true;
			}
			if(a[3]==j*c1)
			{
				f[3]=true;
			}
			if(a[4]==j*c1)
			{
				f[4]=true;
			}
			if(a[5]==j*c1)
			{
				f[5]=true;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(f[j]!=true)
			{
				c2=a[j];
				find1=7;
				break;
			}
		}
		if(find1==6)
		{
			anss=1;
			return;
		}
		dfs(num+1);
		return;
	}
	else if(num==2)
	{
		for(int j=0;j<=maxx/c1;j++)
		{
			for(int k=0;k<=(maxx-j*c1)/c2;k++)
			{
			if(a[2]==j*c1+k*c2)
			{
				f[2]=true;
			}
			if(a[3]==j*c1+k*c2)
			{
				f[3]=true;
			}
			if(a[4]==j*c1+k*c2)
			{
				f[4]=true;
			}
			if(a[5]==j*c1+k*c2)
			{
				f[5]=true;
			}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(f[j]!=true)
			{
				c3=a[j];
				find1=7;
				break;
			}
		}
		if(find1==6)
		{
			anss=2;
			return;
		}
		dfs(num+1);
		return;
	}
	else if(num==3)
	{
		for(int j=0;j<=maxx/c1;j++)
		{
			for(int k=0;k<=(maxx-j*c1)/c2;k++)
			{
				for(int l=0;l<=(maxx-j*c1-k*c2)/c3;l++)
				  {
			          if(a[2]==j*c1+k*c2+l*c3)
			          {
				        f[2]=true;
			          }
			          if(a[3]==j*c1+k*c2+l*c3)
			          {
			 	         f[3]=true;
			          }
			          if(a[4]==j*c1+k*c2+l*c3)
			          {
				         f[4]=true;
			          }
			          if(a[5]==j*c1+k*c2+l*c3)
			          {
				         f[5]=true;
			          }
			      }
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(f[j]!=true)
			{
				c4=a[j];
				find1=7;
				break;
			}
		}
		if(find1==6)
		{
			anss=3;
			return;
		}
		dfs(num+1);
		return;
	}
	else if(num==4)
	{
		for(int j=0;j<=maxx/c1;j++)
		{
			for(int k=0;k<=(maxx-j*c1)/c2;k++)
			{
				for(int l=0;l<=(maxx-j*c1-k*c2)/c3;l++)
				  {
				  	for(int p=0;p<=(maxx-j*c1-k*c2-l*c3)/c4;p++)
			         {
					  if(a[2]==j*c1+k*c2+l*c3+p*c4)
			          {
				        f[2]=true;
			          }
			          if(a[3]==j*c1+k*c2+l*c3+p*c4)
			          {
			 	         f[3]=true;
			          }
			          if(a[4]==j*c1+k*c2+l*c3+p*c4)
			          {
				         f[4]=true;
			          }
			          if(a[5]==j*c1+k*c2+l*c3+p*c4)
			          {
				         f[5]=true;
			          }
			         }
			      }
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(f[j]!=true)
			{
				c5=a[j];
				find1=7;
				break;
			}
		}
		if(find1==6)
		{
			anss=4;
			return;
		}
		dfs(num+1);
		return;
	}
	else if(num==5)
	{
		anss=5;
		return;
	}
	return;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		c1=0,c2=0,c3=0,c4=0,c5=0,maxx=0,anss=0;
		f[1]=true,f[2]=true,f[3]=true,f[4]=true,f[5]=true;
		for(int j=1;j<=n;j++)
		{
			a[j]=0;
			f[j]=false;
		}
		for(int j=1;j<=n;j++)
		{
		   cin>>a[j];
		   maxx=max(maxx,a[j]);
		}
		sort(a+1,a+n+1);
		f[1]=true;
		c1=a[1];
		dfs(1);
		cout<<anss<<endl;
	}
	return 0;
}
/*
1 
5
3 6 9 8 6
*/
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
/*
1
4
7 10 9 8
*/

