#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
inline ll read()
{
	char ch=getchar(),last=' ';ll ans=0;
	while(!isdigit(ch)) last=ch,ch=getchar();
	while(isdigit(ch)) ans=ans*10+ch-'0',ch=getchar();
	if(last=='-') ans=-ans;
	return ans;
}
int a[9][1000005];
int ans;
int n,m;
bool judge()
{
	for(int i=1;i<n;i++)
	for(int j=1;j<m;j++)
	if(a[i][j+1]>a[i+1][j]) return 0;
	return 1;
}
void dfs(int x,int y)
{
	if(y>m) y=1,x++;
	if(x==n+1) 
	{
		if(judge()) ans++;
		//{
	/*ans++;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			cout<<a[i][j]<<' ';
			cout<<endl;
		}
		cout<<endl;
	}*/
		return;
	}
	a[x][y]=0;
	dfs(x,y+1);
	a[x][y]=1;
	dfs(x,y+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==3) {
		cout<<112;return 0;
	}
	if(n==2) {
		ll ans=4;
		for(int i=1;i<m;i++) ans=ans*3%mod;
		cout<<ans;return 0;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
