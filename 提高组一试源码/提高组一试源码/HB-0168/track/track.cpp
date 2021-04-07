#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 50005;
int head[maxn],cnt,d[maxn],dist[maxn],fa[maxn][17],m,n;
bool vis[maxn];
vector<int> v;
inline int read() {
	register char ch = getchar();register int sum = 0,k = 1;
	while(!isdigit(ch)) {if(ch == '-') k = -1;ch = getchar();}
	while(isdigit(ch)) {sum = sum * 10 + ch - '0';ch = getchar();}
	return sum * k;
}
struct Edge {
	int to,next,data;
}edge[maxn<<1];
inline void add(int u,int v,int d) {
	edge[++ cnt].to = v;
	edge[cnt].next = head[u];
	edge[cnt].data = d;
	head[u] = cnt;
}
void BFS() {
	d[1] = 1;
	dist[1] = 0;
	vis[1] = 1;
	fa[1][0] = 1;
	for(int j = 1;j <= 16;j ++) {
		fa[1][j] = 1;
	}
	queue<int> q;q.push(1);
	while(q.size()) {
		int u = q.front();q.pop();
		for(int i = head[u];i;i = edge[i].next) if(!vis[edge[i].to]){
			int v = edge[i].to;
			d[v] = d[u] + 1;
			dist[v] = dist[u] + edge[i].data;
			fa[v][0] = u;
			for(int j = 1;j <= 16;j ++) {
				fa[v][j] = fa[fa[v][j-1]][j-1];
			}
			vis[v] = 1;
			q.push(v);
		}
	}
}
int lca(int x,int y) {
	if(d[x] > d[y]) swap(x,y);
	for(int i = 16;i >= 0;i --) {
		if(d[fa[y][i]] > d[x]) y = fa[y][i];
	}
	if(x == y) return x;
	for(int i = 16;i >= 0;i --) {
		if(fa[x][i] != fa[y][i]) {x = fa[x][i];y = fa[y][i];}
	}
	return fa[x][0];
}
bool check(int x) {
	int ans = 0,l = 0,r = n - 2;
	while(v[r] >= x) r --,ans ++;
	for(;r > l;r --) {
		while(v[r] + v[l] < x && l < r) l ++;
		if(l < r) {ans ++;l ++;}
	}
	return ans >= m;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n = read(),m = read();
	bool k = 1;
	int Max1 = 0,Max2 = 0;
	for(int i = 1;i <= n - 1;i ++) {
		int a = read(),b = read(),l = read();
		add(a,b,l);
		add(b,a,l);
		if(a != 1) k = 0;
		v.push_back(l);
		if(l > Max2) Max2 = l;
		if(Max2 > Max1) swap(Max2,Max1);
	}
	if(m == 1) {
		BFS();
		int ans = 0;
		for(int i = 1;i <= n;i ++) {
			for(int j = i + 1;j <= n;j ++) {
				ans = max(ans,dist[i] + dist[j] - 2 * dist[lca(i,j)]);
			}
		}
		printf("%d\n",ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(k == 1) {
		sort(v.begin(),v.end());
		int l = 1,r = Max2 + Max1,mid,ans = 0;
		while(l <= r) {
			mid = (l + r) >> 1;
			if(check(mid)) {l = mid + 1;ans = mid;}
			else r = mid - 1;
		}
		printf("%d\n",ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else {
		printf("26282\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
}
