#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	x*=f;
	return x;
}
const int N=1e4+10;
int nn,p[N],b[N],nt[N];
inline void add(int x,int y)
{
	b[++nn]=y;
	nt[nn]=p[x];p[x]=nn;
}
int n,m;
int ans[N];
int fa[N],tot;
struct node
{
	int u,v;
}a[N];
bool cmp(node s,node t)
{
	return (s.u<t.u)||((s.u==t.u)&&s.v>t.v);
}
void dfs1(int x)
{
	int e=p[x];
	while(e){
		int k=b[e];
		if(k!=fa[x]){
			fa[k]=x;
			dfs1(k);
		}
		e=nt[e];
	}
}
void RESET()
{
	nn=0;
	memset(p,0,sizeof(p));
	memset(nt,0,sizeof(nt));
	memset(b,0,sizeof(b));
}
void dfs(int x)
{
	ans[++tot]=x;
	int e=p[x];
	while(e){
		int k=b[e];
		if(k!=fa[x]){
			fa[k]=x;
			dfs(k);
		}
		e=nt[e];
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	int rt=(1<<30);
	for(register int i=1;i<=m;++i){
		a[i].u=read(),a[i].v=read();
		add(a[i].u,a[i].v);
		add(a[i].v,a[i].u);
		rt=min(min(rt,a[i].u),a[i].v);
	}
	dfs1(rt);
	RESET();
	for(register int i=1;i<=m;++i){
		if(fa[a[i].u]==a[i].v)a[i].u^=a[i].v^=a[i].u^=a[i].v;
	}
	sort(a+1,a+1+m,cmp);
	for(register int i=1;i<=m;++i){
		add(a[i].u,a[i].v);
		add(a[i].v,a[i].u);
	}
	dfs(a[1].u);
	for(register int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}
