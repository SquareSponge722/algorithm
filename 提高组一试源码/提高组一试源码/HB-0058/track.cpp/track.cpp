#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int a[10001],b[10001],c[10001];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++)
		cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<n;i++)
		ans=c[i]+ans;
	cout<<ans-14;	
}
