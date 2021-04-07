#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct r
{
	int lt[5001];
	int gs;
}road [5001];
int pd(r road[5001],int st,int cd,int anss[10001],int j,int father)
{
	int i;
	cd++;
	anss[cd]=st;
	if(father==0)
	{
		if(road[st].gs!=0)
		{
			if(road[st].gs!=1)
				j=1;
			for(i=1;i<road[st].gs;i++)
				cd=pd(road,road[st].lt[i],cd,anss,j,st);
			j=0;
			cd=pd(road,road[st].lt[road[st].gs],cd,anss,j,st);
		}
	}
	else
	{
		if(j==0)
		{
			if(road[st].gs==2)
				pd(road,road[st].lt[road[st].gs],cd,anss,j,st);
			else if(road[st].gs!=1&&road[st].gs!=0&&road[st].gs!=2)
			{
				j=1;
				for(i=1;i<road[st].gs;i++)
					cd=pd(road,road[st].lt[i],cd,anss,j,st);
				j=0;
				pd(road,road[st].lt[road[st].gs],cd,anss,j,st);
			}
		}
		else
		{
			for(i=1;i<=road[st].gs;i++)
			{
				if(road[st].lt[i]!=father)
					cd=pd(road,road[st].lt[i],cd,anss,j,st);
			}
			cd++;
			anss[cd]=father;
		}
	}
	return cd;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	int a;
	int ans[10001]={5001};
	int anss[10001]={0};
	cin>>n>>m;
	for(a=1;a<=n;a++)
		road[a].gs=0;
	for(a=1;a<=m;a++)
	{
		int x,y;
		cin>>x>>y;
		road[x].gs++;
		road[y].gs++;
		road[x].lt[road[x].gs]=y;
		road[y].lt[road[y].gs]=x;
	}
	int k,l,o;
	for(a=1;a<=n;a++)
	{
		for(k=1;k<=road[a].gs;k++)
		{
			for(l=1;l<road[a].gs;l++)
			{
				if(road[a].lt[l]>road[a].lt[l+1])
				{
					o=road[a].lt[l];
					road[a].lt[l]=road[a].lt[l+1];
					road[a].lt[l+1]=o;
				}
			}
		}
	}
	for(a=1;a<n;a++)
	{
		int st=1;
		int f=0;
		int i=0;
		int c=0;
		pd(road,a,c,anss,i,f);
		if(anss<ans)
		{
			for(a=1;a<=10000;a++)
				ans[a]=anss[a];
		}
	}
	cout<<ans;
	return 0;
}
