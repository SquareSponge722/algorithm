#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n<100&&m<100)
	cout<<(long long)pow(2,m*n-m-n+4)-(long long)pow(2,m+n-2);
	else cout<<(long long)m*2;
	return 0;
}
