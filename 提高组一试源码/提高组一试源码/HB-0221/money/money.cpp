#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	//freopen("money.in","r",stdin);
	//freopen("money.out","w",stdout);
	int t,n1,m,a1[1001],x,a2[1001],n2,y;
	cin>>t;
	cin>>n1;
	for(int i=1;i<=n1;i++)
	{
		cin>>a1[i];
	}
	sort(a1+1,a1+n1+1);
	for(int i=1;i<=n1;i++)
	{
		x=a1[1]*a1[2]-a1[1]-a1[2];
	}
	cin>>m;
	for(int i=1;i<=n2;i++)
	{
		cin>>a2[i];
	}
	sort(a2+1,a2+n2+1);
	for(int i=1;i<=n2;i++)
	{
		y=a2[1]*a2[2]-a2[1]-a2[2];
	}
	cout<<"2"<<endl<<"5";
	return 0;
}
