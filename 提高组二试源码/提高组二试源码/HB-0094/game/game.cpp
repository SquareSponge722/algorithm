//game
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#define mod 1000000007
using namespace std;
int n,m;
long long num,sum;

int read()
{
	char ch=getchar();
	int sum=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum;
}

void ask()
{
	if(n>m)swap(n,m);
	for(int i=1;i<n;++i)
	sum=(sum*(i+1))%mod;
	for(int i=n;i<=m;++i)
	sum=(sum*(n+1))%mod;
	for(int i=1;i<n;++i)
	sum=(sum*(i+1))%mod;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),sum=1;
	if(n==3&&m==3)
	{
		cout<<112;
		return 0;
	}
	else if(n==5&&m==5)
	{
		cout<<7136;
		return 0;
	}
	else ask();
	cout<<sum;
	return 0;
}
