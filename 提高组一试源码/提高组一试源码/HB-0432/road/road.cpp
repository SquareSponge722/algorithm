#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m=0,d,day=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d;
		if(d>m)day=day+(d-m);
		m=d;
	}
	cout<<day<<endl;
	return 0;
}
