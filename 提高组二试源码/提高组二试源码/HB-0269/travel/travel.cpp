#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
int f[N][N] ,ans[N];
int n,m,t=1,used[N],cused[N];
bool road[N][N],gone[N];
bool finish(){
	for(int i=1;i<=n;i++)
		if(!gone[i]) return false;
	return true;
}
void connect(int u,int v){
	for(int i=1;i<=n;i++)
		if(f[v][i]) f[u][i]=true;
}
void search(int u,int v){
	if(finish()) return;
	if(road[u][v]&&!gone[v]){
		gone[v]=gone[u]=true;
		ans[t++]=v;
		used[v]=u;
		cused[u]=v;
		connect(used[u],v);
		search(v,1);
	} 
	else if(v<n)search(u,v+1);
		else search(used[u],1);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1,v,u;i<=m;i++){
		cin>>u>>v;
		road[u][v]=true;
		road[v][u]=true;
		road[i][i]=true;
	}
	ans[0]=1;
	search(1,2);
	for(int i=0;i<t;i++) cout<<ans[i]<<" ";
	return 0;
}
