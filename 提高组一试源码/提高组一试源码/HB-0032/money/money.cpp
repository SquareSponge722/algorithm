#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxl=30;
int a[maxl]={0},b[maxl]={0},c[maxl]={0};
int i,j,k,m,l=1,nn,fff=1;
int t,n,swaper,flag;	
void dfs(int aaa , int jj)
{
	if(aaa==a[jj]){flag--;return;}
	if(aaa>a[jj]){return;}
	
		for(k=1;k<=jj;k++)
		{	
			aaa=aaa+a[k];
			dfs(aaa,jj);
			aaa=aaa-a[k];
		}
	return;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;flag=n;
		for(j=1;j<=n;j++)
		{cin>>a[j];}
		//------------
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=j;k++)
			{
				if(a[j]<a[k])
				{swaper=a[j];a[j]=a[k];a[k]=swaper;}
			}
		}//1->50
		//---------------
		for(j=2;j<=n;j++)
		{
			if(a[j]==a[j-1])
			{
				for(k=j;k<=n;k++)
				{
					a[k]=a[k-1];
				}
				flag--;j--;n--;
			}
		}
		//---------------
		for(j=1;j<=n;j++)
		{
			dfs(0,j);
		}
		c[fff]=flag;fff++;
	}
	for(i=1;i<=fff-1;i++)
	{
		cout<<c[i];
	}
	return 0;
}