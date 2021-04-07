#include<bits/stdc++.h>
using namespace std;

int n,m,begin=0;

struct ll
{
  int start;
  int end;	
}a[100000];
 
int  v[10000]={0,1},z[10000];
bool li[100000];

void find(int pp,int sum,int num,int han)
{
	if(sum>=n)
	{
		for(int b=1;b<=n;b++)
		cout<<v[b]<<" ";
		exit(0);
	}
	
	int min=9999999;
	int flag=0;
	
	for(int k=1;k<=m;k++)
	{
	    if(a[k].end==pp&&li[a[k].start]==1)
	    {
	         if(a[k].start<min)
	         min=a[k].start;
	         flag++;
		}
		if(a[k].start==pp&&li[a[k].end]==1)
		{
			if(a[k].end<min)
	        min=a[k].end;
	        flag++;
		}
	}
	if(flag)
    {
    if(n==m)
    {
    	if(min>begin&&han==0)
    	{
    		min=begin;
    		han++;
		}
	}
	v[++sum]=min;
	num=sum;
	pp=min;
	li[min]=0;
	find(pp,sum,num,han);
    }
    else
    {
    pp=v[--num];
    find(pp,sum,num,han);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int k=1;k<=m;k++)
	{
		cin>>a[k].start>>a[k].end;
	}
	for(int k=1;k<=n;k++)
	{
		li[k]=1;
	}
    for(int k=1;k<=m;k++)
    {
    	if(a[k].end==1)
    	begin=max(begin,a[k].start);
    	if(a[k].start==1)
    	begin=max(begin,a[k].end);
	}
	li[1]=0;
	find(1,1,1,0);
	return 0;
}
