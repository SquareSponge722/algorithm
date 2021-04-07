#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5005;
int n,m;
vector<int> G[N];
int b[N][N],t[N],ans[N];
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-48,ch=getchar();
	return s;
}
void dfs(int u,int f){
	printf("%d ",u);
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v!=f) dfs(v,u);
	}
}
int num;
int vis[N];
void dfs1(int u){
	t[++num]=u;vis[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(!vis[v]&&b[u][i]==0) dfs1(v);
	}
}
inline bool check(){
	for(int i=1;i<=n;i++)
		if(ans[i]!=t[i]) return ans[i]>t[i];
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	if(m<n){
		int u,v;
		for(int i=1;i<=m;i++)  {
			u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
		dfs(1,0);
	}else {
		int u,v;
		for(int i=1;i<=m;i++)  {
			u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			sort(G[i].begin(),G[i].end());
			ans[i]=n;
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<G[i].size();j++){
				memset(vis,0,sizeof(vis));
				b[i][j]=1;
				num=0;
				dfs1(1);
				b[i][j]=0;
				if(num==n)
					if(check()) for(int i=1;i<=n;i++) ans[i]=t[i];
			}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
	return 0;
}
