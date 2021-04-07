#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
int n,m;
int hed[10000];
struct edge{
	int to;
	int nxt;
}e[10000];
bool vis[10000];
int a[10000];
int ru[10000];
void dfs(int s){
	priority_queue<int>q;
	q.push((-s));
	vis[s]=1;
	while(!q.empty()){
		int u=q.top();
		q.pop();
		u=-u;
		printf("%d ",u);
		for(int x=hed[u];x;x=e[x].nxt){
			int v=e[x].to;
			if(!vis[v]){
				vis[v]=1;
				q.push(-v);
			}
		}
}}
int main( ){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v;
	for(int x=1;x<=m;x++){
		scanf("%d%d",&u,&v);
		e[x].to=v;
		e[x].nxt=hed[u];
		hed[u]=x;
		e[x+n].to=u;
		ru[u]++,ru[v]++;
		e[x+n].nxt=hed[v];
		hed[v]=x+n;
	}
	dfs(1);
	return 0;
}
