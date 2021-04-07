#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define ll long long
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
const int N=1e5+10;
int nn,b[N],nt[N],p[N],w[N];
inline void add(int x,int y,int val){
	b[++nn]=y;w[nn]=val;
	nt[nn]=p[x];p[x]=nn;
}
int n,m;
int ans=0;
int fa[N];
void dfs(int x,int dist)
{
	ans=max(ans,dist);
	int e=p[x];
	while(e){
		int k=b[e];
		if(k!=fa[x]){
			fa[k]=x;
			dfs(k,dist+w[e]);
		}
		e=nt[e];
	}
}
int in[N];
void dfs1(int x,int cnt)
{
	int e=p[x];
	while(e){
		int k=b[e];
		if(k!=fa[x]){
			fa[k]=x;
			dfs(k,cnt+1);	
		}	
		e=nt[e];
	}
}
int main() 
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);	
	n=read();m=read();
	for(register int i=1;i<n;++i){
		int u=read(),v=read(),val=read();
		add(u,v,val);
		add(v,u,val);
		in[u]++;in[v]++;
	}
	if(m==1){
		for(register int i=1;i<=n;++i){
			memset(fa,0,sizeof(fa));
			dfs(i,0);
		}
		printf("%d",ans);
	}
	else if(m!=1){
		int rt=0;
		for(register int i=1;i<=n;++i)if(in[i]==1)rt=i;
		dfs1(rt,0);
		printf("%d",ans);
	}
	return 0;
}
