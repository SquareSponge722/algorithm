#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int d[100001];
	int num=0,n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>d[i];
		if(d[i]>=d[i-1]) num++;
	    num++;
	}
	cout<<num;
	return 0;
}
