#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define rg register
using namespace std;
vector<int>g[30010];
vector<int>w[30010];
int maxx=0,now=0;
bool vis[30010]={false};
bool bd[50010];
/*bool cmp(note a,note b)
{
	return a.data<b.data;
}*/
inline int read()
{
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-f;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void dfs(int i,int summ)
{
	vis[i]=true;
	if(maxx<=summ)
	{
		maxx=summ;
		now=i;
	}
	for(int j=1;j<=g[i][0];j++)
	{
		if(vis[g[i][j]]!=true)
		{
			dfs(g[i][j],summ+w[i][j]);
		}
	}
	return;
}
/*void build(int val,int num,int xuhao)
{
	if(bd[num]!=true)
	{
		tree[num].data=val;
		tree[num].num=xuhao;
		bd[num].data=true;
		return;
	}
	if(val>tree[num].data);
	{
		build(val,num*2+1,xuhao);
	}
	else if(val<tree[num].data)
	{
		build(val,num*2,xuhao);
	}
	return;
}
int ask(int val,int num)
{
	int anss=0;
    if(val>tree[num].data)
	{
		if(bd[num*2+1]!=true)
		{
		  return num;
		}
		anss=ask(val,num*2+1);
	}
	else if(val<=tree[num].data)	
	{
		if(bd[num*2]!=true)
		{
		  return num;
		}
		anss=ask(val,num*2);
	}
	return anss;
}*/
/*void dfss(int i,int num)
{
	num++;
	if(g[i][0]==1&&i!=start)
	{
		return;
	}
	vis[i]=true;
	for(int j=1;j<=2;j++)
	{
		if(vis[g[i][j]]!=true)
		{
			c[num]=g[i][j];
			dfs(g[i][j]);
			return;
		}
	}
	return;
}*/
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int m,n;
	cin>>n>>m;
    	for(int i=1;i<=n;i++)
    	{
    		g[i].push_back(0);
    		w[i].push_back(0);
    		vis[i]=false;
		}
    	for(int i=1;i<=n-1;i++)
    	{
    		int a,b,l;
    		cin>>a>>b>>l;
    		g[a][0]++;
    		g[b][0]++;
    		g[a].push_back(b);
    		g[b].push_back(a);
    		w[a].push_back(l);
    		w[b].push_back(l);
		}
		now=0;
		vis[1]=true;
    	dfs(1,0);
    	for(int i=1;i<=n;i++)
    	{
    		vis[i]=false;
		}
		maxx=0;
    	dfs(now,0);
    	cout<<maxx<<endl;
    	return 0;
	/*else
	{
		
		int minn=99999999,maxx=0,summ=0;
		for(int i=1;i<=n;i++)
		{
			g[i].push_back(0);
		}
		for(int i=1;i<=n-1;i++)
		{
			int a,b,l;
			cin>>a>>b>>l;
			g[a][0]++;
			g[b][0]++;
			g[a].push_back(b);
			g[b].push_back(a);
			w[a].push_back(l);
			w[b].push_back(l);
			summ=summ+ff[i].data;
		}
		for(int i=1;i<=n;i++)
		{
			if(g[i][0]==1)
			{
				start=i;
				break;
			}
		}
		dfss(start,1);
		tryy(1,summ);
		/*for(int i=1;i<=n-1;i++)
		{
			int a,b,l;
			cin>>a>>b>>l;
			ff[i].num=b;
			ff[i].data=l;
			minn=min(minn,ff[i].data);
			maxx=max(maxx,ff[i].data);
			summ=summ+ff[i].data;
		}
		for(int i=1;i<=n;i++)
		{
		   build(ff[i].data,1,ff[i].num);	
	    }
		tryy(minn,maxx*2);
		
		return 0;
	}*/
}
/*
10 1
1 2 3
1 3 4
1 4 7
2 5 999
5 6 4
8 9 10
3 8 2
3 7 6
4 10 2
*/
