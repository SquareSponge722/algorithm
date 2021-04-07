#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
long long h[100010];
long long d[100010];
long long curr=0;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	curr=0;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		
		d[i]=h[i]-h[i-1];
		if( d[i] > 0 )
		{
			curr+=d[i];
		}
	}
	
	cout<<curr<<endl;
	return 0;
}
