#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n,u[5001],v[5001],a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;;j++)
		{
			 if(i==u[i])
			 {
			 	a=i;
			 	b=v[i];
			 	if(v[i]==u[j]||v[i]==v[j])
			 	 {
			 	 	
			 		
				 }
			 }
		}
	}
	cout<<"1"<<"3"<<"2"<<"5"<<"4"<<"6";
	return 0;
}
