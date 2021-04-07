#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 5005;
int head[maxn],cnt,n,m,vis[maxn];
priority_queue<int,vector<int>,greater<int> > q;
struct Edge {
	int next,to;
}edge[maxn<<1];
inline int read() {
	register char ch = getchar();register int k = 1,sum = 0;
	while(!isdigit(ch)) {if(ch == '-') k = -1;ch = getchar();}
	while(isdigit(ch)) {sum = sum * 10 + ch - '0';ch = getchar();}
	return sum * k;
}
inline void add(int u,int v) {
	edge[++cnt].next = head[u];
	edge[cnt].to = v;
	head[u] = cnt;
}
void DFS(int u) {
	printf("%d ",u);
	vector<int> v;
	vis[u] = 1;
	for(int i = head[u];i;i = edge[i].next) if(!vis[edge[i].to]){
		v.push_back(edge[i].to);
	}
	sort(v.begin(),v.end());
	for(int i = 0;i < (int)v.size();i ++) if(!vis[v[i]]){
		DFS(v[i]);
	}
	v.clear();
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= m;i ++) {
		int u = read(),v = read();
		add(u,v);add(v,u);
	}
	if(m == n - 1) DFS(1);
	else {
	/**/
	vis[1] = 1;
	q.push(1);
	while(q.size()) {
		int u = q.top();
		printf("%d ",u);q.pop();
		for(int i = head[u];i;i = edge[i].next) if(!vis[edge[i].to]) {
			vis[edge[i].to] = 1;
			q.push(edge[i].to);
		}
	}
	}
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
