#include <bits/stdc++.h>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> a[5050];
int m,n;
void addedge(int u,int v)
{
       a[u].push_back(v); a[v].push_back(u); 
}
void dfs(int u)
{
	if(u==n) return;
     for(int i=0;i<a[u].size();i++)
     {
     	int x=a[u][i];
     	cout<<x<<" ";
     	dfs(a[u][i]);
	 }
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	addedge(x,y);
	}
	dfs(1);
	return 0;
	
}
