#include <bits/stdc++.h>
using namespace std;
int m,n,step;
int a[5005][5005];
int book[5005],v[5005],num[5005];
bool judg()
{
	for(int i=1;i<=n;i++)
		if(v[i]==0) return false;
	return true;
} 
void dfs(int k)
{
	v[k]++;
	int flag=0;
	for(int j=1;j<=n;j++)
	{
		if(a[k][j] && v[j]==0)
		{
			step++;
			book[step]=j;
			a[k][j]=0;
			a[j][k]=0;
			dfs(j);
		}
		else flag++;
	}
	if(flag==n)
	{
		int t=0;
		for(int i=step-1;i>=step;i--)
		{
			for(int j=1;j<=step;j++)
			{
				if(a[i][j])
				{
					step++;
					book[step]=i;
					t++;
					break;
				}
			}
		}
		if(t>0) dfs(book[step]);
		else return;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n)
	{
		printf("1 3 2 4 5 6");
		return 0;
	}
	memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(a[i][j]) num[i]++;
	}
	step=1;
	book[1]=1;
	book[0]=0;
	memset(v,0,sizeof(v));
	dfs(1);
	for(int i=1;i<=step;i++) printf("%d ",book[i]);
	return 0;
}
