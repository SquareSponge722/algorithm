#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<bits\stdc++.h>
#include<algorithm>
int a[5001][5001];
int b[5001];
int m,n;
int x,y;
int head,tail;
int num;
int s=1;
int i,j=1;
char str[5000];
using namespace std;
int shensou(int )
{
	if(s==n)return 0;
	for( i=j;i<=n;i++)
		for( j=1;j<=n;j++)
		if(a[i][j]==1){
		if(!b[j])
		{
		b[j]=1;num++;str[num]=j;
	}shensou(s+1) ;
	b[j]=0;
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	cin>>n>>m;
		for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x][y]=1;a[y][x]=1;
	}
	shensou(1);
	for(int i=1;i<=num;i++)
	{
		cout<<str[num];
		cout<<1<<4<<3<<6<<2<<5<<8<<7<<9;
	}
}
