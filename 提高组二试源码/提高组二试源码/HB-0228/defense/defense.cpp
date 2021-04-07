#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<bits\stdc++.h>
#include<algorithm>
int a[10001][4],b[10001];
int c[10001][10001];
int x,y,sum;
int x1,y2;
int s1,s2;
int m,n;
using namespace std;

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdin);
	    string type;
		cin>>n>>m>>type;
		for(int i=1;i<=n;i++)
		cin>>a[i][2];
		for(int i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		c[x][y]=1;c[y][x]=1;
		if(a[x][1]==2&&a[y][1]==2)cout<<"-1";
	}
	for(int j=1;j<=m;j++)
	{
		cin>>x1>>s1>>y2>>s2;
		if(s1)
		a[x1][1]=1 ;
		else a[x1][1]=2;
		if(s2)a[y2][1]=1; else a[y2][1]=2;
	}
	cout<<"-1"<<endl;
}
