#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
#include<ctime>
using namespace std;
int read()
{
	int anxs=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		anxs=anxs*10+c-'0';
		c=getchar();
	}
	return anxs;
}
int n,m;
priority_queue<int>nxt[5010];
int vis[5010];
vector<int>pot;
int flag;
void dfs(int x)
{
	cout<<x<<" ";
	vis[x]=1; 
	while(!nxt[x].empty())
	{
		int temp=-nxt[x].top();
		if(!vis[temp])
		{
			dfs(temp);
		}
		nxt[x].pop();
	}
}

	
vector<int>vv;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	srand(time(NULL));
	n=read();m=read();
	int a1,a2;
	for(int i=1;i<=m;i++)
	{
		a1=read();a2=read();
		nxt[a1].push(-a2);
		nxt[a2].push(-a1);
	}
	if(n==m)
	{
		int ttp=rand()%n+1;
		while(!nxt[ttp].empty())
		{
			vv.push_back(nxt[ttp].top());
			nxt[ttp].pop();
		}
		for(int i=0;i<vv.size()-1;i++)
		{
			nxt[ttp].push(vv[i]);
		}
	}
	//memset(vis,0,sizeof(vis));
	dfs(1);
	
	return 0;
}
