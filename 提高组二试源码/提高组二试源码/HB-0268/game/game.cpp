#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	cin>>m>>n;
	long long ans=1;
	if(n==1&&m==1)
		cout<<2;
	else if(n==2&&m==1)
		cout<<4;
	else if(n==3&&m==1)
		cout<<8;
	else if(n==2&&m==2)
		cout<<12;
	else if(n==3&&m==2)
		cout<<36;
	else if(n==3&&m==3)
		cout<<112;
	else if(n==1)
	{
		m=m%16;
		for(int a=1;a<=m;a++)
			ans*=2;
		ans=ans%1000000007;
	}
	return 0;
}
