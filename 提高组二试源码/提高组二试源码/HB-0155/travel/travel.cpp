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

//int gd=0,paa,pa1,pa2,bookgd=0; //n==m专用
int n,m,js=2;
int jjs=2,gd=0,son1=0,son2;
int low[5001]={0},dfn[5001]={0},ys[5001]={0};
int book[5001]={0},ans[5001]={0};
vector<set<int> >mmap;

void swap(int &a,int &b){a^=b;b^=a;a^=b;}
void add(int a,int b)
{
	mmap[a].insert(b);
	mmap[b].insert(a);
}
//m==n-1
void dfs(int x,int fa)
{
	set<int>::iterator it;
	for(it=mmap[x].begin();it!=mmap[x].end();it++)
	{
		if(*it==fa) continue;
		ans[js++]=*it;
		dfs(*it,x);
	}
}
//m==n-1
void tarjan(int a,int fa)
{
	ys[js]=a;low[a]=js;dfn[a]=js++;
	set<int>::iterator it;
	for(it=mmap[a].begin();it!=mmap[a].end();it++)
	{
		if(*it==fa) continue;
		if(dfn[*it])
		{
			low[a]=dfn[*it];
			gd=ys[dfn[*it]];
			return;
		}
		tarjan(*it,a);
		low[a]=min(low[*it],low[a]);
		if(gd) return;
	}
}
void find()
{
	set<int>::iterator it;
	for(it=mmap[gd].begin();it!=mmap[gd].end();it++)
	{
		if(low[*it]==dfn[gd])
		{
			if(son1) 
			{
				son2=*it;
				if(son1>son2) swap(son1,son2);
				return ;
			}
			else
				son1=*it;
		}
	}
}
void dfs2(int a,int fa)
{
	set<int>::iterator it;
	book[a]=1;
	for(it=mmap[a].begin();it!=mmap[a].end();it++)
	{
		if(*it==fa) continue;
		if(low[*it]==dfn[gd])
		{
			if(*it<son2) 
			{
				ans[jjs++]=*it;
				dfs2(*it,a);
			}
		}
		else 
		{
			ans[jjs++]=*it;
			dfs2(*it,a);
		}
	}
}
void dfs1(int a,int fa)
{
	book[a]=1;
	set<int>::iterator it;
	for(it=mmap[a].begin();it!=mmap[a].end();it++)
	{
		int b=*it;
		if(*it==fa||book[*it]) continue;
		ans[jjs++]=*it;	
		if(*it==son1) 
			dfs2(b,a);
		else dfs1(b,a);
	}
}
int main()
{
	int a,b;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	mmap.resize(n+1);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			add(a,b);
		}
	if(m==n-1)
	{
		ans[1]=1;
		dfs(1,0);
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
	else
	{
		book[1]=1;
		tarjan(1,0);
		/*
		find(1,0);
		findpa(gd);
		if(pa2<gd) bookgd=1;
		*/
		find();
		ans[1]=1;
		dfs1(1,0);
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
	return 0;
}


//m==n
/*
void dfs1(int x,int fa)
{
	set<int>::iterator it;
	for(it=mmap[x].begin();it!=mmap[x].end();it++)
	{
		if(*it==fa) continue;
		if(*it==gd&&bookgd)
		{
			bookgd=0;
			continue;
		}
		ans[js++]=*it;
		dfs(*it,x);
	}
}
void find(int a,int fa)
{
	set<int>::iterator it;
	for(it=mmap[a].begin();it!=mmap[a].end();it++)
	{
		if(*it==fa) continue;
		if(book[*it])
		{
			paa=a;
			gd=*it;
			return ;
		}
		cs[*it]=cs[a]+1;
		pa[*it]=a;
		book[*it]=1;
		int b=*it;
		find(b,a);
		if(gd) return ;
	}
}
void findpa(int a)
{
	pa1=pa[a];pa2=paa;
	if(cs[pa1]<cs[pa2]) 
		swap(pa1,pa2);
	while(cs[pa1]>cs[pa2]) 
		pa1=pa[pa1];
	while(pa[pa1]!=pa[pa2])
	{
		pa1=pa[pa1];pa2=pa[pa2];
	}
	if(pa1>pa2) swap(pa1,pa2); 
}
*/
//m==n