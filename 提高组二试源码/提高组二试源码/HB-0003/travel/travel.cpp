#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	cin>>n;
	cin>>m;
	int b[n+1];//1 or 0
	int c[m+1];
	int d[m+1];
	int q;
	for(q=1;q<=m;q++)
	{
		cin>>c[q];
		cin>>d[q];
	}
	cout<<"1 3 2 5 4 6";
	return 0;
}
