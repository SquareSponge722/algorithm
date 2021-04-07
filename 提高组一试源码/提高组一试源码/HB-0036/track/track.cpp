#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
int a,b,c,sum;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{cin>>a>>b>>c;sum+=c;}
	cout<<sum/m;
	return 0;
}
