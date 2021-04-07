#include<bits/stdc++.h>
using namespace std;
int n,m,f[256][1000005],sum;
const int Mod=1000000007;
bool check(int x,int val)
{
	int p=x&val;
	if(p==val) return true;
	return false;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	int t=pow(2,n);
	for(int i=0;i<=t-1;i++)
		{
			f[i][1]=1;
		}
	for(int j=2;j<=m;j++)
		for(int i=0;i<=t-1;i++)
		{
			for(int k=max(0,i>>1);k<=t-1;k++)
			{
			if(!check(k,max(0,i>>1))) continue;
			f[i][j]=(f[i][j]+f[k][j-1])%Mod;
			}
		}
		for(int j=1;j<=m;j++)
			for(int i=0;i<=t-1;i++)
				cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
	for(int i=0;i<=t-1;i++)
		{
			sum=(sum+f[i][m])%Mod;
		}
	cout<<sum<<endl;
	return 0;
}
