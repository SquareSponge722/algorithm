#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long s;
int d[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i];
	for(int i=1;i<=n;i++)
	if(d[i-1]<d[i])s+=(d[i]-d[i-1]);
	cout<<s;
	return 0;
}
