#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
#include<queue>
#include<cmath>
#define ll long long
#define inf 1e16
#define maxn 100005
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return w==1?x:-x;
}

int n,m,q,w[maxn],a,x,b,y;
ll ans,dp[maxn][2];
vector <int> mp[maxn];
string s1;

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(); q=read(); cin>>s1;
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	while(q--)
	{
		for(int i=0;i<=n;i++) for(int j=0;j<=1;j++) dp[i][j]=inf;
		dp[0][0]=0; dp[0][1]=0;
		a=read(); x=read(); b=read(); y=read();
		if(s1[0]=='A')
		{
			for(int i=1;i<=n;i++)
			{
				if(i!=a&&i!=b)
				{
					dp[i][0]=dp[i-1][1];
					dp[i][1]=min(dp[i-1][0],dp[i-1][1])+w[i];
				}
				else
				{
					if(i==a)
					{
						if(x==0)
						{
							dp[i][0]=dp[i-1][1];
							dp[i][1]=inf;
						}
						else if(x==1)
						{
							dp[i][0]=inf;
							dp[i][1]=min(dp[i-1][1],dp[i-1][0])+w[i];
						}
					}
					else
					{
						if(y==0)
						{
							dp[i][0]=dp[i-1][1];
							dp[i][1]=inf;
						}
						else if(y==1)
						{
							dp[i][0]=inf;
							dp[i][1]=min(dp[i-1][1],dp[i-1][0])+w[i];
						}
					}
				}
			}
			ll ans=min(dp[n][0],dp[n][1]);
			if(ans>=inf) puts("-1");
			else cout<<ans<<endl;
		}
	}
	return 0;
}
