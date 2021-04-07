#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 5005;

struct Edge{
	int v,next;
}e[maxn];

int dfn[maxn],num = 0;
int vis[maxn],head[maxn],tot;


void addnode(int x,int y)
{
	e[++tot].v = y;
	e[tot].next = head[x];
	head[x] = tot;
}

int ans[maxn];
int temp[maxn];
int n,m;

inline void read(int &x)
{
	x = 0;
	int w = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-') w = -1;
		c = getchar();
	}
	while(isdigit(c))
	{
		x = x*10 + c - '0';
		c = getchar();
	}
	x*=w;
}
//int flag;
int l;

void dfs(int x)
{
	
	dfn[++num] = x;
	/*if(num == n) 
	{
		//flag = 1;
		int ok = 0;
		for(int i=1;i<=num;i++)
		{
			if(dfn[i] > ans[i]) break;
			else if(dfn[i] < ans[i])
			{
				ok = 1;
				break;
			} 
		}
		if(ok) 
		{
			for(int i=1;i<=num;i++)
			{
				ans[i] = dfn[i];
			}
		}
		return;
	}*/
	int cnt = 0;
	for(int i=head[x];i;i=e[i].next)
	{
		/*
		int v = e[i].v;
		if(!vis[v])
		{
			vis[v] = 1;
			dfs(v);
			vis[v] = 0;
			
		}
		*/
		temp[++cnt] = e[i].v;
	}
	if(cnt == 0) return;
	sort(temp+1,temp+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		if(!vis[temp[i]])
		{
			vis[temp[i]] = 1;
			dfs(temp[i]);
			vis[temp[i]] = 0;
		}
	}
}


int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	
	memset(ans,0x3f3f3f,sizeof(ans));
	memset(vis,0,sizeof(vis));
	
	read(n),read(m);
	
	for(int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		addnode(x,y);
        addnode(y,x);
		//out[x] ++;
		//out[y] ++;
	}
	
	vis[1] = 1;
	dfs(1);
	
	
	
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dfn[i]);
	}
	
}
