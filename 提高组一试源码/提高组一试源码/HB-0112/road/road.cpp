#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

int a[100001],b[100001];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	long long n,day=0,l,r,k;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
}
    a[0]=0;
    l=min(a[1],a[n]);
    r=max(a[1],a[n]);
    day=r;
	cout<<day<<endl;
	return 0;
}
