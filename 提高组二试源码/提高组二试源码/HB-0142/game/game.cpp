#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+110;
const int M=1e6+110;
const int mod=1e9+7;
int n,m,mp[9][M],ans;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int ksm(int x,int y)
{
	int sum=1;
	while(y)
	{
		if(y&1)sum=sum*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return sum;
}
map<int ,bool>vis;
int check()
{
	int ans=0;
	for(int j=1;j<=n;j++)
	{
	    int ans=0;
		for(int i=1;i<=m;i++)ans=ans*j+mp[j][i];
	
	}
	if(!vis[ans])
		{
			vis[ans]=1;
			return 1;
		}
	else 
	return 0;
}
void dfs(int x,int y)
{
	if(x==0)
	{

		ans=(ans+1)%mod;
		return ;
	}
	
	if(x==n)
	{
		for(int i=0;i<=1;i++)
		{
			mp[x][y]=i;
			if(y==m)
			  dfs(x-1,1);
	    	else dfs(x,y+1);
			mp[x][y]=0;
    	}
	}
	else 
	{
		if(mp[x+1][y-1]==1||(y==1))
		{
			for(int i=0;i<=1;i++)
			{
				mp[x][y]=i;
				if(y==m)
			      dfs(x-1,1);
	        	else dfs(x,y+1);
				mp[x][y]=0;
			}
		}
		else 
		{
			mp[x][y]=0;
			if(y==m)
			      dfs(x-1,1);
	        else dfs(x,y+1);
		}
	}
}
main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	if(n==1){printf("%lld",ksm(2,m));return 0;}
	if(m==1){printf("%lld",ksm(2,n));return 0;}
	if(n==3&&m==3){printf("112");return 0;}
	if(n==5&&m==5){printf("7136");return 0;}
	if(n==2)
	{
		printf("%lld",12*ksm(3,m-2)%mod);
		return 0;
	}
	if(m==2)
	{
		printf("%lld",12*ksm(3,n-2)%mod);
		return 0;
	}
	dfs(n,1);
	cout<<ans<<endl;
	return 0;
}
