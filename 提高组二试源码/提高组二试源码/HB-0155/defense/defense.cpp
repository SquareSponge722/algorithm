#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
#define INF 2147483647
#define ll int

int a,aa,b,bb;
int n,m,type2,js=2;
char type1,c;
int book[100010]={0},mmap[200020][3]={0},last[100010]={0},p[100010]={0};
void add(int x,int y)
{
	mmap[js][0]=x;
	mmap[js][1]=y;
	mmap[js][2]=last[x];
	last[x]=js++;
}
ll dfs(int fa,int fay,int x,int y,ll dp[100010][2][2])
{
	if(dp[x][y][fay]) 
	{
		if(dp[x][y][fay]=-2) return 0;
		return dp[x][y][fay];
	}
	book[x]=1;
	//printf("dp[%d][%d][%d]\n",x,y,fay);
	if(y)
	{
		dp[x][y][fay]=p[x];
		for(int i=last[x];i;i=mmap[i][2])
		{
			if(mmap[i][1]==fa||book[mmap[i][1]]) continue;
			if(mmap[i][1]==b)
			{
				dp[x][y][fay]+=dfs(x,1,b,bb,dp);
			}
			else
			{
				ll d,e,f,g;
				d=dfs(x,1,mmap[i][1],0,dp);
				e=dfs(x,1,mmap[i][1],1,dp);
				f=min(d,e);
				g=max(d,e);
				if(f==-1) dp[x][y][fay]+=g;
				else dp[x][y][fay]+=f;
			}
		}
		if(!dp[x][y][fay]) dp[x][y][fay^1]=-2;
		else dp[x][y][fay^1]=dp[x][y][fay];
	}
	else
	{
		int flag=fay;
		for(int i=last[x];i;i=mmap[i][2])
		{
			if(mmap[i][1]==fa||book[mmap[i][1]]) continue;
			if(mmap[i][1]==b)
			{
				if(!bb) 
				{
					book[x]=0;
					dp[x][y][fay]=-1;
					return -1;
				}
				dp[x][y][fay]+=dfs(x,0,b,bb,dp);
			}
			else
			{
				ll d,e;
				d=dfs(x,0,mmap[i][1],0,dp);
				e=dfs(x,0,mmap[i][1],1,dp);
				if(e<d||d==-1) 
				{
					flag=1;
					dp[x][y][fay]+=e;
				}
				else
					dp[x][y][fay]+=d;
			}
		}
		if(!flag)
		{
			ll d=INF,fflag=0;
			for(int i=last[x];i;i=mmap[i][2])
			{
				if(mmap[i][1]==b||book[mmap[i][1]]) continue;
				fflag=1;
				d=min(d,dp[mmap[i][1]][1][0]-dp[mmap[i][1]][0][0]);
			}
			if(fflag) 
			{
				book[x]=0;
				dp[x][y][fay]=-1;
				return -1;
			}
			dp[x][y][fay]+=d;
		}
	}
	if(!dp[x][y][fay]) 
	{
		book[x]=0;
		dp[x][y][fay]=-2;
		return 0;
	}
	book[x]=0;
	//printf("dp[%d][%d][%d]=%d\n",x,y,fay,dp[x][y][fay]);
	return dp[x][y][fay];
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%c%c%d",&n,&m,&c,&type1,&type2);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	for(int i=1;i<=m;i++)
	{
		ll dp[100010][2][2]={0};
		scanf("%d%d%d%d",&a,&aa,&b,&bb);
		printf("%d\n",dfs(0,0,a,aa,dp));
	}
	return 0;
}
/*


*/
/*
struct node{
	int x;
	bool operator <(const node b) const
	{
		return this->x<b.x;
	}
};
*/
