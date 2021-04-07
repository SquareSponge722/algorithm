#include <bits/stdc++.h>
using namespace std;

const int maxn=5100;
struct stu
{
	int to,next;
	bool book;
}road[maxn*2]; int first[maxn],cnt=0;
int n,m,cnt1;
int ans[maxn],nowans[maxn],dep[maxn],fa[maxn],pos1[maxn],pos2[maxn];
bool map1[maxn][maxn],book[maxn];
queue <int> q;

void addedge(int x,int y)
{
	road[++cnt].to=y;
	road[cnt].next=first[x];
	first[x]=cnt;	
}

void dfs(int now)
{
	nowans[++cnt]=now;
	book[now]=1;
	for(int i=first[now];i;i=road[i].next)
	{
		if(road[i].book) continue;
		int to=road[i].to;
		if(book[to]) continue;
		dfs(to);
	}
}

void bfs()
{
	memset(book,0,sizeof(book));
	cnt1=0;
	int x,y;
	bool FLAG=0;
	book[1]=1;
	dep[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int i=first[now];i;i=road[i].next)
		{
			int to=road[i].to;
			if(to==fa[now]) continue;
			if(book[to])
			{
				x=now,y=to;
				pos1[++cnt1]=x,pos2[cnt1]=y;
				FLAG=1;
				break;
			}
			book[to]=1;
			fa[to]=now;
			dep[to]=dep[now]+1;
			q.push(to);
		}
		if(FLAG) break;
	}
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]!=dep[y])
	{
		pos1[++cnt1]=x,pos2[cnt1]=fa[x];
		x=fa[x];	
	}
	while(x!=y)
	{
		pos1[++cnt1]=x,pos2[cnt1]=fa[x];
		pos1[++cnt1]=y,pos2[cnt1]=fa[y];
		x=fa[x];y=fa[y];	
	}
}

void judge()
{
	for(int i=1;i<=n;i++)
	{
		if(nowans[i]>ans[i]) return;
		else if(nowans[i]<ans[i])
		{
			for(int j=1;j<=n;j++) ans[j]=nowans[j];
			return;	
		}
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map1[x][y]=1,map1[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(map1[i][j]) addedge(i,j);
		}
	}
	if(m==n-1)
	{
		memset(book,0,sizeof(book));
		cnt=0;
		dfs(1);
		for(int i=1;i<=n;i++) printf("%d ",nowans[i]);
	}
	else
	{
		for(int i=1;i<=n;i++) ans[i]=9999;
		bfs();
		for(int i=1;i<=cnt1;i++)
		{
			int x=pos1[i],y=pos2[i],mk1,mk2;
			for(int i=first[x];i;i=road[i].next)
			{
				int to=road[i].to;
				if(to==y)
				{
					road[i].book=1;
					mk1=i;
					break;
				}
			}
			for(int i=first[y];i;i=road[i].next)
			{
				int to=road[i].to;
				if(to==x)
				{
					road[i].book=1;
					mk2=i;
					break;
				}
			}
			memset(book,0,sizeof(book));
			memset(nowans,0,sizeof(nowans));
			cnt=0;
			dfs(1);
			judge();
			road[mk1].book=0,road[mk2].book=0;
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
	return 0;	
}
