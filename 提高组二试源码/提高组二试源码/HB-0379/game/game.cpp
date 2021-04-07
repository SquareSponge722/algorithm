#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 5005
using namespace std;
int n,m,sum;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	sum+=pow(2,(1+m)*n/2)+pow(2,n);
	cout<<sum;
	return 0;
}
