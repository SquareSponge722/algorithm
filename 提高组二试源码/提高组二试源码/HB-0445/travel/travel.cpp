#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int m,n;
vector<int> e[N];
bool vis[N];

inline int read(){
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') k=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*k;
}

void dfs111(int u){
	printf("%d ",u);
	vis[u]=0;
	int len=e[u].size();
	for(int i=0;i<len;i++)
		for(int j=i+1;j<len;j++)
			if(e[u][i]>e[u][j]) 
				swap(e[u][i],e[u][j]);
	for(int i=0;i<e[u].size();i++)
		if(vis[e[u][i]])
			dfs111(e[u][i]);
}

void dfs222(int u){
	printf("%d ",u);
	vis[u]=0;
	int len=e[u].size();
	if(e[u][0]>e[u][1]&&(len==3||len==2)) swap(e[u][0],e[u][1]);
	if(len>3){
		for(int i=0;i<len;i++)
		for(int j=i+1;j<len;j++)
			if(e[u][i]>e[u][j]) 
				swap(e[u][i],e[u][j]);
	}	
	for(int i=0;i<len;i++)
		if(vis[e[u][i]])
			dfs222(e[u][i]);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u,v;u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n<=100&&m==n-1){
		fill(vis,vis+n+1,1);
		for(int i=1;i<=n;i++)
			if(vis[i]) dfs111(i);
	}
	if(n>100&&n<=1000&&m==n-1){
		fill(vis,vis+n+1,1);
		for(int i=1;i<=n;i++)
			if(vis[i]) dfs222(i);
	}
//	if(m==n) RP++
	if(m==n){
		fill(vis,vis+n+1,1);
		for(int i=1;i<=n;i++)
			if(vis[i]) dfs111(i);
	}
	return 0;
}
