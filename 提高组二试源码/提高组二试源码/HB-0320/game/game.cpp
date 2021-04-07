#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int s[1000001],a[9][1000001];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		a[i][j]==0||a[i][j]==1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
		 s[i]+=a[i][j];
		}
	}
	//sum+=s[i]; 
	sum=(2^(2*n+2)-2^n-1)*2^n; 
	cout<<sum<<endl;
	return 0;
}
