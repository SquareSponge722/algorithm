#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define LL long long
#define inf 2147483647
#define N 1000001
using namespace std;
inline LL read(){
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return f*x;
}
int n,m,head[N*2],cnt,vis[N],ans[N],num,ind[N],ok,minn=inf;
vector<int>ve[N*2];
inline void addedge(int u,int v){
	ve[u].push_back(v);
}
inline void dfs(int u){
	vis[u]=1,ans[++num]=u;
	for(int i=0;i<ve[u].size();i++){
		int v=ve[u][i];
		if(!vis[v])dfs(v);
	}
}
inline bool check(){
	for(int i=1;i<=n;i++)
		if(!vis[i])return false;
	return true;
}
inline int getnum(vector<int>&vec,int pre){
	for(int i=0;i<vec.size();i++){
		int to=vec[i]; 
		if(!vis[to]&&to!=pre)return to;
	}
}
void dfs_(int u){
	vis[u]=1,ans[++num]=u;
	for(int i=0;i<ve[u].size();i++){
		int v=ve[u][i];
		if(vis[v])continue;
		int f=getnum(ve[u],v);
		if(f==0);
		else minn=min(f,minn);
		if(v>minn){minn=inf;continue;}
		else dfs_(v);
	}
}
inline void subtask_1(){
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		addedge(u,v),addedge(v,u);
	}
	for(int i=1;i<=n;i++)sort(ve[i].begin(),ve[i].end());
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis)),num=0,memset(ans,0,sizeof(ans)),dfs(i);
		if(check())break;
	}
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<' ';
}
inline void subtask_2(){
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		addedge(u,v),addedge(v,u);
	}
	for(int i=1;i<=n;i++)sort(ve[i].begin(),ve[i].end());
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis)),num=0,memset(ans,0,sizeof(ans)),dfs_(i);
		if(check())break;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
}
int main(){
	freopen("tarvel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	if(m==n-1)subtask_1();
	else subtask_2();
	return 0;
}
