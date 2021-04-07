#include<bits/stdc++.h>
using namespace std;
int n,m,d[5001];
int ans[5001],cnt;
int num[5001];
int dis[5001];
bool vis[5001];
vector<int>v[5001];
void read(int& x)
{
	char c=getchar();
	x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
bool cmp(int a,int b)
{
	return a<b;
}
void build(int x)
{
	printf("%d ",x);
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(d[y])continue;
		d[y]=d[x]+1;
		build(y);
	}
}
void dfs(int x)
{
	num[++cnt]=x;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(d[y]||y==0)continue;
		d[y]=d[x]+1;
		dfs(y);
	}
}
void tree()
{
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		read(x);
		read(y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	d[1]=1;
	for(int i=1;i<=n;i++)sort(v[i].begin(),(--v[i].end()),cmp);
	build(1);
	printf("\n");
	exit(0);
}
void solve(int x)
{
	memset(d,0,sizeof(d));
	d[1]=1;
	cnt=0;
	dfs(1);
	if(cnt<n)return ;
	bool ok=0;
	for(int i=1;i<=cnt;i++)
	{
		if(ans[i]>num[i])
		{
			ok=1;
			break;
		}
		else if(ans[i]!=num[i])
		{
			ok=0;
			break;
		}
	}
	if(ok)
	{
		for(int i=1;i<=cnt;i++)
		{
			ans[i]=num[i];
		}
	}
}
void ring()
{
	for(int i=1;i<=n;i++)
	{
		int x,y;
		read(x);
		read(y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(ans,0x3f3f3f3f,sizeof(ans));
	for(int i=1;i<=n;i++)
	{
		sort(v[i].begin(),(--v[i].end()),cmp);
		for(int j=0;j<v[i].size();j++)
		{
			int t=v[i][j];
			v[i][j]=0;
			solve(1);
			v[i][j]=t;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		printf("%d ",ans[i]);
	}
	putchar('\n');
	exit(0);
}
int main()
{
	freopen("tarvel.in","r",stdin);
	freopen("tarvel.out","w",stdout);
	read(n);
	read(m);
	if(m==n-1)
	{
		tree();
	}
	if(m==n)
	{
		ring();
	}
	return 0;
}
