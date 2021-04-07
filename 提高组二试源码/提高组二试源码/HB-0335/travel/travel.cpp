#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
const int N=5e3+10;
int n,m,head[N],to[2*N],nxt[2*N],tot,dfn[N],low[N],cnt,d[N][N],maxn,last1,last2,father;
stack<int>st;
bool vis[N],flag[N],flag2,flag3;
inline void add(int x,int y) {
	tot++; to[tot]=y; nxt[tot]=head[x]; head[x]=tot;
}
inline void dfs1(int x,int fa) {
	printf("%d ",x);
	for(int i=head[x];i;i=nxt[i]) {
		int u=to[i];
		if(u==fa) continue ;
		d[x][++d[x][0]]=u;
	}
	sort(d[x]+1,d[x]+1+d[x][0]);
	for(int i=1;i<=d[x][0];i++)
		dfs1(d[x][i],x);
}
inline void targan(int x,int fa) {
	dfn[x]=low[x]=++cnt;
	st.push(x); vis[x]=1;
	for(int i=head[x];i;i=nxt[i]) {
		int u=to[i];
		if(u==fa) continue ;
		if(!dfn[u]) {
			targan(u,x);
			low[x]=min(low[x],low[u]);
		}
		else if(vis[u]) {
			low[x]=min(low[x],dfn[u]);
		}
	}
	if(low[x]==dfn[x]) {
		if(st.top()==x) st.pop(),vis[x]=0;
		else {
			while(!st.empty()) {
				int t=st.top(); st.pop(); 
				vis[t]=0; flag[t]=1; 
				if(t==x) break;
			}
		} 
	}
}
inline void dfs2(int x,int fa) {
	printf("%d ",x);
	for(int i=head[x];i;i=nxt[i]) {
		int u=to[i];
		if(u==fa) continue;
		if(flag2==0 && flag[fa] && flag[x] && flag[u] && u>maxn) {
			flag2=1; continue ;		
		}
		if(flag[x] && flag[u]==0) d[x][++d[x][0]]=u;
		if(flag[x] && flag[u] && flag3 && u!=last1) d[x][++d[x][0]]=u;
		if(flag[x]==0) d[x][++d[x][0]]=u;
		if(flag[fa]==0 && flag[x] && flag[u]) {
			if(last1==0) last1=u;
			else {
				last2=u;
				if(last1>last2) swap(last1,last2);
				maxn=last2; father=x; d[x][++d[x][0]]=last1;
			}
		}
	}
	sort(d[x]+1,d[x]+1+d[x][0]);
	for(int i=1;i<=d[x][0];i++)
		dfs2(d[x][i],x);
	if(flag2 && flag3==0) {
		flag3=1; dfs2(maxn,father); 
	}	
}
inline void calc() {
	targan(1,1); 
	vis[1]=1; dfs2(1,1); 
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		add(x,y); add(y,x);
	}
	if(m==n-1) dfs1(1,1);
	else calc();
	return 0;
}


