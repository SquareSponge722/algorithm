#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<cmath>
int a[11];
using namespace std;
int main()
{  freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int m,n,c;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	sort(a,a+n);
	for(int i=0;i<n;i++)
	m=a[n-1];
	if(n<=11);
	cout<<m;
	return 0;
}
