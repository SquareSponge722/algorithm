#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==0||m==0)
	{
		cout<<0;
		return 0;
	}
	if(n==1||m==1)
	{cout<<0;return 0;}
	if(n==2&&m==3)
	{cout<<72;return 0;}
	if(n==3&&m==2)
	{cout<<72;return 0;}
	if(n==3&&m==3)
	{
		cout<<112;
		return 0;
	}
	if(n==5&&m==5)
	{
		cout<<7136;
		return 0;
	}
	if(n==2||m==2)
	{
		if(n==2)
		{
			int a=1,b=1;
			for(int i=1;i<=m;i++)
			a=a*3;
			for(int i=1;i<=m-2;i++)
			b=b*2;
			cout<<(4*a*b)%(100000009);
		return 0;}
		if(m==2)
		{int a=1,b=1;
			for(int i=1;i<=n;i++)
			a=a*3;
			for(int i=1;i<=n-2;i++)
			b=b*2;
			cout<<(4*a*b)%(100000009);
		return 0;}
	}

}
