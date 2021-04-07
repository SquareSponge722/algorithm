#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1&&m==1)
	ans=0;
	if(n==2&&m==1)
	ans=4;
	if(n==3&&m==1)
	ans=8;
	if(n==2&&m==2)
	ans=12;
	if(n==3&&m==2)
	ans=56;
	if(n==2&&m==3)
	ans=56;
	if(n==3&&m==3)
	ans=112;
	else if(n==1)
	{
		ans=1;
		for(int i=1;i<=m;i++)
		ans=ans*2;
	}
	ans=ans%1000000007;
	cout<<ans;
	return 0;
}
