#include<bits/stdc++.h>
using namespace std;
int n,m,type,maxd;
bool son[100010];
int dep[100010],p[100010];
int vis[100010];
char c;
int d[100010][2];
vector<int>v[100001];
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
void dfs(int x)
{
	bool ok=0;
	for(int i=0; i<v[x].size(); i++)
	{
		int y=v[x][i];
		if(dep[y])continue;
		ok=1;
		dep[y]=dep[x]+1;
		maxd=max(maxd,dep[y]);
		dfs(y);
	}
	son[x]=ok;
}
int dp(int x,int op)
{
	if(!son[x])
	{
		if(op==1)return d[x][op]=p[x];
		else return d[x][op]=0;
	}
	if(d[x][op]<0x3f3f3f3f)return d[x][op];
	d[x][op]=0;
	if(op==1)
	{
		d[x][op]=p[x];
		for(int i=0; i<v[x].size(); i++)
		{
			int y=v[x][i];
			if(dep[y]<dep[x])continue;
			if(vis[y]==-1)
				d[x][op]+=min(dp(y,1),dp(y,0));
			else if(vis[y]==1)
			{
				d[x][op]+=dp(y,1);
			}
			else if(vis[y]==0)
			{
				d[x][op]+=dp(y,0);
			}
		}
	}
	if(op==0)
	{
		for(int i=0; i<v[x].size(); i++)
		{
			int y=v[x][i];
			if(dep[y]<dep[x])continue;
			if(vis[y]==-1)
			{
				d[x][op]+=dp(y,1);
			}
			else if(vis[y]==1)
			{
				d[x][op]+=dp(y,1);
			}
			else if(vis[y]==0)continue;
		}
	}
	return d[x][op];
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n);
	read(m);
	scanf("%c%d",&c,&type);
	for(int i=1; i<=n; i++)
	{
		read(p[i]);
	}
	for(int i=1; i<=n-1; i++)
	{
		int x,y;
		read(x);
		read(y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dep[1]=1;
	dfs(1);
	for(int i=1; i<=m; i++)
	{
		memset(vis,-1,sizeof(vis));
		memset(d,0x3f3f3f3f,sizeof(d));
		int a,x,b,y;
		read(a);
		read(x);
		read(b);
		read(y);
		vis[a]=x;
		vis[b]=y;
		for(int i=1; i<=n; i++)
		{
			if(!son[i])
			{
				d[i][1]=p[i];
			}
		}
		if(type==1)printf("%d\n",dp(1,1));
		else
		{
			if(vis[1]==0)
			{
				int ans=dp(1,0);
				if(ans==0)
					printf("-1\n");
				else printf("%d\n",ans);
			}
			else if(vis[1]==1)
			{
				int ans=dp(1,1);
				if(ans==0)
					printf("-1\n");
				else printf("%d\n",ans);
			}
			else
			{
				int ans1=dp(1,0);
				int ans2=dp(1,1);
				if(ans1!=0||ans2!=0)printf("%d\n",min(ans1,ans2));
				else
				{
					printf("-1\n");
				}
			}
		}
	}
	return 0;
}
