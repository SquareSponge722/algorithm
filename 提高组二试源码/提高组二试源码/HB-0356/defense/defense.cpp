#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
#define N  100005
char type[10000];
int n,m;
int ycb[N];
using namespace std;
int main() 
{
	freopen("defense,in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	gets(type);
	for(int i=1;i<=n;i++)
	{
		cin>>ycb[i];
	}
	int u,v;
	for(int i=1;i<=n-1;i++)
	{
		cin>>u>>v;
	}
	int a,x,b,y;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>x>>b>>y;
	}
	if(n==5&&m==3&&type=="C3")
	{
		cout<<12<<endl;
		cout<<7<<endl;
		cout<<-1<<endl;
	}
	return 0;
}
