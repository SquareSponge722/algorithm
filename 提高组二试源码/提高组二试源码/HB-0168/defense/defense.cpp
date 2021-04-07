#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const long long maxn = 100005;
char str[10];
struct Node {
	long long x,y;
	Node(long long x = 0,long long y = 0):x(x),y(y){}
	bool operator < (const Node& k) const {
		return x == k.x ? y < k.y : x < k.x;
	}
};
set<Node> S;
long long val[maxn],col[maxn],head[maxn],cnt,ans[3],a,x,b,y;
struct Edge {
	long long next,to;
}edge[maxn<<1];
inline void add(long long u,long long v) {
	edge[++cnt].next = head[u];
	edge[cnt].to = v;
	head[u] = cnt;
}
inline long long read() {
	register char ch = getchar();register long long k = 1,sum = 0;
	while(!isdigit(ch)) {if(ch == '-') k = -1;ch = getchar();}
	while(isdigit(ch)) {sum = sum * 10 + ch - '0';ch = getchar();}
	return sum * k;
}
void DFS(long long u,long long r) {
	for(long long i = head[u];i;i = edge[i].next) {
		long long v = edge[i].to;
		if(v == r) continue;
		col[v] = col[u]%2 + 1;
		ans[col[v]] += val[v];
		DFS(v,u);
	}
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	long long n = read(),m = read();
	scanf("%s",str);
	for(long long i = 1;i <= n;i ++) {
		val[i] = read();
	}
	for(long long i = 1;i < n;i ++) {
		long long u = read(),v = read();
		add(u,v);add(v,u);
		S.insert(Node(u,v));
		S.insert(Node(v,u));
	}
	col[1] = 1;
	ans[1] += val[1];
	DFS(1,0);
	for(long long i = 1;i <= m;i ++) {
		a = read(),x = read(),b = read(),y = read();
		if(x == 0 && y == 0 && S.count(Node(a,b))) printf("-1\n");
		else if(x == 1 && y == 1) {
			if(col[a] != col[b]) {
				long long ans1 = min(ans[col[a]] + val[b],ans[col[b]] + val[a]);
				printf("%lld\n",ans1);
			}
			else {
				long long ans1 = min(ans[col[a]],ans[col[a]%2+1] + val[a] + val[b]);
				printf("%lld\n",ans1);
			}
		}
		else {
			if(x == 1) {
				long long ans1 = min(ans[col[a]],ans[col[a]%2+1] + val[a]);
				printf("%lld\n",ans1);
			}
			else if(y == 1) {
				long long ans1 = min(ans[col[b]],ans[col[b]%2+1] + val[b]);
				printf("%lld\n",ans1);
			}
			else {
				long long ans1 = ans[col[a]%2+1];
				printf("%lld\n",ans1);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
