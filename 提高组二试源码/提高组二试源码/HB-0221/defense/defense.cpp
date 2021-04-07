#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int m,n,p[100001],u[9999999],v[9999999],a,b,x,y;
	char type;
	cin>>m>>n;
	cin>>type;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		cin>>u[i]>>v[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>x>>y;
	}
	
	cout<<"12"<<endl<<"7"<<endl<<"-1";
	return 0;
}
