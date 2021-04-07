#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int mn = 1000005;
const int mod = 1e9 + 7;
const int maxn = (1<<8)+5;
vector<int> ve[maxn];
int n,m,f[mn][(1<<3) + 5],ans;
bool vis[maxn][maxn];
void prit(int x)
{
	cout<<"x = "<<x<<endl;
	while(x)
	{
		int tmp=x&-x;
		cout<<int(log2(tmp))<<" ";
		x-=tmp;
	}
	cout<<endl;
}
bool check(int sit1,int sit2)
{
	for(int j=0;j<n-1;j++)
	{
		if((sit1 & (1<<(j+1)))==0 && ((sit2 & (1<<j)) !=0))
			return false;
		if((sit1 & (1<<(j+1)))!=0 && ((sit2 & (1<<j)) ==0))
			return true;
	}
	return true;
}
int now[105][105];
int st[mn],top;
bool flag;
bool cmp(int x,int y)
{
	for(int i=0;i<=n+m-2;i++)
	{
		if((((1<<i) & x) ==0) && (((1<<i) & y)!=0))
		{
			return true;
		}
		if((((1<<i) & x) !=0) && (((1<<i) & y)==0))
		{
			return false;
		}
	}
	return false;
}
void dfs2(int x,int y,int cost,int k)
{
	if(x==n && y==m)
	{
		//cout<<k<<endl;
		for(int i=1;i<=top;i++)
		{
			if(cmp(st[i],cost))
			{
				//cout<<st[i]<<" "<<cost<<" "<<cmp(st[i],cost)<<endl;				
				flag=false;
				return ;
			}
		}
		st[++top] = cost;
		return ;
	}
	if(!flag) return ;
	if(x<n)
		dfs2(x+1,y,cost+(now[x+1][y]<<k),k+1);
	if(y<m)
		dfs2(x,y+1,cost+(now[x][y+1]<<k),k+1);
}
void dfs(int x,int y)
{
	if(y>m)
	{
		dfs(x+1,1);
		return ;
	}
	if(x==n+1)
	{
		flag=true;
		top=0;
		dfs2(1,1,now[1][1],1);
		if(flag)
			ans++;
		return ; 
	}
	now[x][y]=1;
	dfs(x,y+1);
	now[x][y]=0;
	dfs(x,y+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<(1<<n);j++)
			if(check(i,j))
			{
				vis[i][j]=1;
				ve[i].push_back(j);
			}
	}
	if(m<=10 && n<=3)
	{
		dfs(1,1);
		printf("%d",ans);
		return 0;
	}
	for(int i=0;i<(1<<n);i++)
		f[1][i]=1;
	for(int i=1;i<m;i++)
		for(int j=0;j<(1<<n);j++)
		{
			int tmp=ve[j].size();
			for(int k=0;k<tmp;k++)
			{
				int t;
				if(cmp(j,ve[j][k])) t=j;
				else t=ve[j][k];
				//f[i+1][ve[j][k]] = (f[i+1][ve[j][k]]+f[i][j])%mod;
				f[i+1][t] = (f[i+1][t]+f[i][j])%mod;
			}
		}
	int ans=0;
	for(int i=0;i<(1<<n);i++)
	{
		//cout<<f[m][i]<<endl;
		ans = (ans+f[m][i])%mod;
	}
	printf("%d",ans);
	return 0;
}

