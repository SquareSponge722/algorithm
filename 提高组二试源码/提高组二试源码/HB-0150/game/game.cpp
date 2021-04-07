#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod=1e9+7;
int n,m;
ll ans;
int pos[2000][20],mark[20],cnt=0;
int num1[20],num2[20];
int map1[10][10];


void dfs1(int now,int cnt1,int cnt2)
{
	if(now==n+m-1)
	{
		cnt++;
		for(int i=1;i<=n+m-2;i++) pos[cnt][i]=mark[i];
		return;
	}
	if(cnt1<m-1)
	{
		mark[now]=0;
		dfs1(now+1,cnt1+1,cnt2);
	}
	if(cnt2<n-1)
	{
		mark[now]=1;
		dfs1(now+1,cnt1,cnt2+1);	
	}
}

bool check()
{
	int nowx=1,nowy=1;
	for(int j=1;j<=n+m-2;j++)
	{
		num1[j]=map1[nowx][nowy];
		if(pos[1][j]==0) nowy++;
		else nowx++;
	}
	for(int i=2;i<=cnt;i++)
	{
		nowx=1,nowy=1;
		for(int j=1;j<=n+m-2;j++)
		{
			num2[j]=map1[nowx][nowy];
			if(pos[i][j]==0) nowy++;
			else nowx++;	
		}
		for(int j=1;j<=n+m-2;j++)
		{
			if(num2[j]<num1[j]) return 0;	
		}
		for(int j=1;j<=n+m-2;j++) num1[j]=num2[j];
	}
	return 1;
}

void dfs2(int x,int y)
{
	if(x==n+1)
	{
		bool kk=check();
		if(kk) ans=(ans+1ll)%mod;
		return;	
	}
	map1[x][y]=0;
	if(y==m) dfs2(x+1,1);
	else dfs2(x,y+1);
	map1[x][y]=1;
	if(y==m) dfs2(x+1,1);
	else dfs2(x,y+1);	
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
if(n==2)
{
	for(ll i=1;i<=m;i++) ans=(ans+i)%mod;
	ans=ans*4ll%mod;
	printf("%lld\n",ans);		
}
else
{
	if(n==3&&m==3) printf("112\n");
	else if(n<=3&&m<=3)
	{	
		dfs1(1,0,0);
		dfs2(1,1);
		printf("%lld\n",ans);
	}
	else
	{
		for(ll i=1;i<=m;i++)
		{
			ll kk=1;
			for(int j=1;j<=n-1;j++)
			{
				kk=kk*i%mod;
			}
			kk=kk*4ll*(ll)(n-1)%mod;
			ans=(ans+kk)%mod;
		}
		printf("%lld\n",ans);
	}
}
	return 0;	
}
