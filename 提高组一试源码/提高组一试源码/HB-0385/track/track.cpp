#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define rg register
int n,m;
int a[50050],b[50050],l[50050];
int flagi,ans;
bool cmp(int a,int b)
{
	return a>b;
}
void f1()
{
	sort(l+1,l+n,cmp);
	for(rg int i=m+1;i<=n-1;i++)
	l[m*2-i+1]+=l[i];
	sort(l+1,l+n,cmp);
	cout<<l[m];
	return;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(rg int i=1;i<=n-1;i++)
	{
	cin>>a[i]>>b[i]>>l[i];
	if(a[i]!=1&&b[i]!=1) flagi=1;	
	}
	if(!flagi)
	f1();
	return 0;
}
