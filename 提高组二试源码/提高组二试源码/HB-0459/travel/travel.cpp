#include<bits/stdc++.h>
#define maxn 5010
using namespace std;

ifstream fin("travel.in");
ofstream fout("travel.out");
int deep[maxn],cir[maxn],hh,fa[maxn],c1,c2;
bool flag,bb;
struct pair_{
	int u,v;
}p[maxn<<2];
struct edge{
	int v,nxt;
}e[maxn<<1];
bool vis[maxn];
int cnt=0,tot=0,n,m;
int head[maxn],an[maxn];
void ade(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
bool cmp(pair_ a,pair_ b)
{
	if(a.u<b.u)
	return 1;
	if(a.u==b.u&&a.v>b.v)
	return 1;
	return 0;
}

void dfs(int u)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		if(!vis[e[i].v])
		{
		vis[e[i].v]=1;
		an[++tot]=e[i].v;
		dfs(e[i].v);
	    }
	}
	return;
}
void dfs2(int u)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		if(!vis[e[i].v])
		{
		vis[e[i].v]=1;
		deep[e[i].v]=deep[u]+1;
		an[++tot]=e[i].v;
		dfs2(e[i].v);
	    }
	}
	return;
}
void dfs3(int u)
{
	if(!flag)
	for(int i=head[u];i;i=e[i].nxt)
	{
		if(!vis[e[i].v])
		{
			if(cir[e[i].v])
			{
				flag=1;
				dfs(e[i].v);
			}
		vis[e[i].v]=1;
		dfs3(e[i].v);
	    }
	}
	if(flag)
	{
		for(int i=head[u];i;i=e[i].nxt)
		{
		if(cir[e[i].v]&&!bb)
		{
			hh=e[e[i].nxt].v;
			bb=1;
		}
		if(cir[e[i].v]&&bb)
		{
			if(e[i].v>hh)
			e[i].nxt=e[e[i].nxt].nxt;
			return;
		}
		if(cir[e[i].v])
		dfs3(e[i].v);
	    }
	}
	return;
}

//void dfs3(int u)
//{
//	for(int i=head[u];i;i=e[i].nxt)
//	{
//		if(!vis[e[i].v])
//		{
//			if(cir[e[i].v])
//			{
//				if(cir[e[e[i].nxt!].v])
//				{
//					
//				}
//			}
//		vis[e[i].v]=1;
//		an[++tot]=e[i].v;
//		dfs(e[i].v);
//	    }
//	}
//	return;
//}
void col(int a,int b)
{
	if(deep[a]>deep[b])
	while(deep[a]>deep[b])
	{
		b=fa[b];
		cir[fa[b]]=1;
	}
	if(a==b)
	return;
	while(a!=b)
	{
		a=fa[a];
		cir[fa[a]]=1;
		b=fa[b];
		cir[fa[b]]=1;
	}
}
int main()
{
	fin>>n>>m;
	if(m==n-1)
	{
	for(int i=1;i<=m;i++)
	{
		fin>>p[i].u>>p[i].v;
		p[i+m].v=p[i].u;p[i+m].u=p[i].v;
	}
	sort(p+1,p+2*m+1,cmp);
	for(int i=1;i<=2*m;i++)
	
	{
		ade(p[i].u,p[i].v);
	}
	vis[1]=1;
	dfs(1);
	fout<<"1 ";
	for(int i=1;i<=tot;i++)
	fout<<an[i]<<" ";
	return 0;
    }
    else
    {
    /*	for(int i=1;i<=m;i++)
	{
		cin>>p[i].u>>p[i].v;
		p[i+m].v=p[i].u;p[i+m].u=p[i].v;
	
	sort(p+1,p+m+1,cmp2);
    }
    //урх╕ 
	for(int i=1;i<=m;i++)
	{
		if(fa[p[i].v])
		{
			cir[p[i].v]=cir[p[i].u]=1;
			col();
		}
		fa[p[i].v]=p[i].u;
		deep[p[i].v]=++dep;
	}*/
	for(int i=1;i<=m;i++)
	{
		fin>>p[i].u>>p[i].v;
		p[i+m].v=p[i].u;p[i+m].u=p[i].v;
		if(fa[p[i].v])
		{
			cir[p[i].v]=cir[p[i].u]=1;
			int c1=p[i].v;
			int c2=p[i].u;
		}
		fa[p[i].v]=p[i].u;
	}
	sort(p+1,p+2*m+1,cmp);
	for(int i=1;i<=2*m;i++)
	{
		ade(p[i].u,p[i].v);
	}
	vis[1]=1;
	deep[1]=1;
	dfs2(1);
	col(c1,c2);
	dfs3(1);
	dfs(1);
	fout<<"1 ";
	for(int i=1;i<=tot;i++)
	fout<<an[i]<<" ";
	return 0;
    }
}
