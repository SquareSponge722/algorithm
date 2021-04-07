#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iomanip>
#include<cstring>
using namespace std;
int main()
{
	
	int n,m=0,a[10001];cin>>n;
	bool r;
	
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	if(m<a[i]) swap(m,a[i]);
	
	for(int i=1;i<=n;i++)
	 if((a[i]<a[i+1])&&(a[i]<a[i-1])) r=false;
	 if(r=true)cout<<m;
	else cout<<33;
	return 0;
}
