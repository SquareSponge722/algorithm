#include<bits/stdc++.h>
using namespace std;

void splay()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}

int i1,i2;char ch;
inline int read()
{
	i1=i2=ch=0;
	while(!isdigit(ch))	i1|=ch=='-',ch=getchar();
	while(isdigit(ch))	i2=(i2<<1)+(i2<<3)+(ch^48),ch=getchar();
	return i1? -i2:i2;
}
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define derep(i,j,k) for(int i=j;i>=k;i--)
#define pic(i,j) for(int i=lin[j];i;i=e[i].nxt)

int m,n,u,v;
set<int> s[5010];
int siz[5010];
set<int>::iterator it;

int dfsx[5010];
bool vis[5010];
int tim_qq=0;
void dfs(int at,int fro)
{
	if(!vis[at]) dfsx[++tim_qq]=at,vis[at]=1;
	for(int i=1;i<=siz[at];i++)
	{
		it=s[at].begin();s[at].erase(it);
		if((*it)^fro) dfs((*it),at);
	}
}

int main()
{
	splay();
	
	n=read(),m=read();
	rep(i,1,m)
	{
		u=read(),v=read();
		s[u].insert(v);s[v].insert(u);
		siz[u]++,siz[v]++;
	}
	
	if(m==n-1){
		dfs(1,0);
		rep(i,1,n) printf("%d ",dfsx[i]);
		return 0;
	}
	
	return 0;
}
