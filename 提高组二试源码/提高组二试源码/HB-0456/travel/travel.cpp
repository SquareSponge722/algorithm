#include<bits/stdc++.h>
using namespace std;
int n,m,minn=999999,minn1=999999,a[10000];
int num1=1,cnt=1,num[5050],e[5050][5050],me=1;
int ans[100010];
bool p[10000];
void dfs(int cur)
{
	if(num1==n)
	{
		me++;
		if(me==1) for(int i=1;i<=n;i++) ans[i]=num[i];
		return ;
	}
	for(int i=1; i<=n; i++)
	{
		if(!p[i]&&e[cur][i]==1)
		{
			p[i]=1;
			num1++;
			num[num1]=i;
			dfs(i);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=999999;
	for(int i=1; i<=m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		e[x][y]=1;
		e[y][x]=1;
		minn=min(minn,min(x,y));
	}
	num[1]=minn;
	p[minn]=1;
	dfs(minn);
	for(int i=1; i<=n; i++)
		cout<<num[i]<<" ";
	return 0;
}
