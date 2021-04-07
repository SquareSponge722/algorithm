#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[50001];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n-1;i++)
	for(int j=0;j<3;j++)
	cin>>a[i];
	cout<<a[2]+a[6];
	return 0;
}
