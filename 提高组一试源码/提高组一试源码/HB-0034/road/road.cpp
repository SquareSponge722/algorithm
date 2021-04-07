#include<iostream>
#include<cstdio>
using namespace std;
int n,i,a,b,c;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a>b)
			c=c+a-b;
		b=a;
	}
	cout<<c;
	return 0;
}
