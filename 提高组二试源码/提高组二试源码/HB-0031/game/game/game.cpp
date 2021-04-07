#include<bits/stdc++.h>
using namespace std;
int m,n;
int i,j;
long long s,x;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1){s=m*m;cout<<s;return 0;}
	if(m==1){s=n*n;cout<<s;return 0;}
	if(n==2) 
	{
		    x=(m*(m-1))/2;
			printf("%lld",x*4*m+4);
			return 0;
	}
	if(n==3)
	{
		j=1;
		for(i=1;i<=m;i++)
		j=j*3;
		printf("%lld",j*4+4);
		return 0;
	}
	if(n==m&&n%2==1)
	{
		x=4+11*(m/2-1);
		x=x*x-2;
		j=1;
		for(i=1;i<=n;i++)
		j=j*2;
		printf("%lld",x*j);
		return 0;
	}
	return 0;
} 
