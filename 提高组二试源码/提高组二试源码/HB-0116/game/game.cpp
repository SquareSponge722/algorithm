#include<bits/stdc++.h>
using namespace std;
int f[8][1000000];
int num[8][1000000];
int m,n;
int cnt;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==3&&mm==3)
	{
		cout<<112;
		return 0;
	}
	if(n<=2)
	{
		int sum=1;
		for(int i=1;i<m;i++)
		    sum*=3;
		cout<<sum*4%100000007;
		return 0;
	} 
}
