#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
inline int read()
{
	register int a(0),p(1);register char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') p=-1,ch=getchar();
	while(ch>='0'&&ch<='9') a=a*10+ch-48,ch=getchar();
	return a*p;
}
const int N=5010;
int n,m,u,v,e[N][N],cnt[N],use[N],book[N],fa[N],num=0,t1,t2,ju,jv,jican;
int getf(int u){return fa[u]==u?u:fa[u]=getf(fa[u]);}
bool dfs(int u)
{
	int i;
	if(!book[u]) num++,printf("%d ",u);
	book[u]=1;
	if(num==n) return true;
	for(i=1;i<=cnt[u];i++) if(!book[e[u][i]])
	{
		if(dfs(e[u][i])&&(u!=1||num==n)) break;
	}
	if(cnt[u]+1==i) return false;
	return true;
}
bool dfs2(int u,int ci)
{
	int i,v,temp,happy=0;
	if(!book[u]) num++,printf("%d ",u);
	book[u]=1;
	if(num==n) return true;
	for(i=1;i<=cnt[u];i++) if(!book[e[u][i]])
	{
		temp=i;
		while(book[e[u][temp+1]]) ++temp;
		v=e[u][i];
		if((i==cnt[u]&&v==jv&&!jican&&ci<v) || (i==cnt[u]&&v==ju&&!jican&&ci<v))
		{
			jican=1;
			return false;
		}
		else if((u==ju&&jv<v&&!book[jv]))
			happy=1,dfs2(jv,0x3f3f3f3f);
		else if((u==jv&&ju<v&&!book[ju]))
			happy=1,dfs2(ju,0x3f3f3f3f);
		if(dfs2(v,min(ci,e[u][temp]))&&(u!=1||num==n)) break;
	}
	if(!happy&&u==ju&&jican&&!book[jv])
		dfs2(jv,0x3f3f3f3f);
	else if(!happy&&u==jv&&jican&&!book[ju])
		dfs2(ju,0x3f3f3f3f);
	if(cnt[u]+1==i) return false;
	return true;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	if(m==n-1)
	{
		for(int i=1;i<=m;++i)
		{
			u=read(),v=read();
			e[u][++cnt[u]]=v;
			e[v][++cnt[v]]=u;
		}
		for(int i=1;i<=n;++i) sort(e[i]+1,e[i]+1+cnt[i]);
		dfs(1);
	}
	else
	{
		// mems
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;++i)
		{
			u=read(),v=read();
			t1=getf(u);t2=getf(v);
			if(t1!=t2)
			{
				fa[t1]=t2;
				e[u][++cnt[u]]=v;
				e[v][++cnt[v]]=u;
			}
			else ju=u,jv=v;
		}
		for(int i=1;i<=n;++i) sort(e[i]+1,e[i]+1+cnt[i]);
		dfs2(1,0x3f3f3f3f);
	}
	return 0;
}

