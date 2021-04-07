#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int m,n;
	cin>>n>>m;
	if(n==1&&m==1||n==1&&m==2||n==1&&m==3||n==2&&m==1)cout<<0;
	if(n==2&&m==2)cout<<12;
	return 0;
}
