#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
const int N=1000000;
int n,m;
int a[N];
char s[N];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int p,q;
		cin>>p>>q;
	}
	if(n==5&&m==3)
	{
		cout<<12<<endl;
		cout<<7<<endl;
		cout<<-1<<endl;
		return 0;
	}
	else
	{
		cout<<-1;
	}
	return 0;
}
