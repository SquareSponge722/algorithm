#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int n,m,fw[5100],son[5100][5100],l[5100];

inline int getnum()
{
	int s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9')  ch=getchar();
	while (ch>='0'&&ch<='9') { s=s*10+ch-'0'; ch=getchar();}
	return s;
}

void dfs(int rt)
{
	fw[rt]=1; printf("%d ",rt);
	for (int i=1; i<=l[rt]; ++i)
	    {
	    	if (!fw[son[rt][i]]) dfs(son[rt][i]);
		}
}

void get_work()
{
	int u,v;
	n=getnum(); m=getnum();
	for (int i=1; i<=m; ++i)
	    {
	    	u=getnum(); v=getnum();
	    	son[u][++l[u]]=v;
	    	son[v][++l[v]]=u;
		}
	for (int i=1; i<=n; ++i)
	    {
	    	sort(son[i],son[i]+l[i]+1);
		}
	dfs(1);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	get_work();
	
	return 0;
}
