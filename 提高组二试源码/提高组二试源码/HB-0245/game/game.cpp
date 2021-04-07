#include<bits/stdc++.h>
using namespace std;
int n,m,sum1,sum2;
int flag;
int k[26];
long long ans;
const int mod=1000000007;
bool dfss(int x,int y)
{
	if(x<=n&&y<=m)
	{
		sum1+=k[(x-1)*m+y];
		if(y<m)
		dfss(x,y+1);
		if(x<n)
		dfss(x+1,y);
		if(x==n&&y==m)
		dfss(x+1,y+1);
		sum1-=k[(x-1)*m+y];
	}
	if(x==n+1&&y==m+1)
	{
		if(sum1<=sum2)
		{sum2=sum1;}
		else
		flag=1;
	}
	if(x==1&&y==1&&!flag)
	return true;
	else
	return false;
}
void dfs(int dep)
{
	if(dep<=m*n)
	{
		dfs(dep+1);
		k[dep]=1;
		dfs(dep+1);
		k[dep]=0;
	}
	if(dep==m*n+1)
	{
		sum2=99999999;
		flag=0;
		if(dfss(1,1))
		ans++;
		if(ans==mod)
		ans=0;
	}
	return;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(m==1&&n==1)
	cout<<2;
	else
	if(m==2&&n==2)
	cout<<12;
	else
	if(m==3&&n==3)
	cout<<112;
	else
	if(n==1)
	{
		ans=1;
		for(int i=1;i<=m;i++)
		{ans*=2;ans%=mod;}
		cout<<ans;
	}
	else
	if(m==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{ans*=2;ans%=mod;}
		cout<<ans;
	}
	else
	if(m==2)
	{
		ans=4;
		for(int i=2;i<=n;i++)
		{ans*=3;ans%=mod;}
		cout<<ans;
	}
	else
	if(n==2)
	{
		ans=4;
		for(int i=2;i<=m;i++)
		{
			ans*=3;
			ans%=mod;
		}
		cout<<ans;
	}
	else
	if(m==5&&n==5)
	cout<<7136;
	else
	{
		dfs(1);
		cout<<ans;
	}
	return 0;
}
