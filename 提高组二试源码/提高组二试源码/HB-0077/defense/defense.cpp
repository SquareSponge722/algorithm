#include <cstdio>
#include <climits>
#include <iostream>
using namespace std;

const int maxN = 100010;
namespace Graph {
	struct Link {
		int /*w,*/ v;
		Link *nxt;
		Link(int v=0, /*int w=0*/ Link *lk=NULL):/*w(w),*/ v(v), nxt(lk) {}
	};
	Link pool[maxN * 2], *ptr = pool, *head[maxN];
	void link(int u, int v) {
		*ptr = Link(v, head[u]);
		head[u] = ptr++;
		*ptr = Link(u, head[v]);
		head[v] = ptr++;
	}
}

unsigned int c[maxN], f[maxN][2];
char st[maxN];
void poi(int x, int fa) {
	using namespace Graph;
	int npMX = INT_MAX, id = -1, sum = 0;
	for(Link *lk = head[x]; lk != NULL; lk = lk->nxt) {
		if(lk->v == fa)
			continue;
		poi(lk->v, x);
		if(npMX > f[lk->v][1])
			npMX = f[lk->v][1], id = lk->v;
		sum += f[lk->v][0];
	}
	if(id != -1)
		f[x][0] = sum - f[id][0] + npMX;
	else
		f[x][0] = INT_MAX;
	f[x][1] = sum + c[x];
	if(st[x] == 1)
		f[x][1] = INT_MAX;
	else if(st[x] == 2)
		f[x][0] = INT_MAX;
}
char mode[10];
int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q >> mode;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		Graph::link(u - 1, v - 1);
	}
	
	for(int i = 0; i < q; i++) {
		int a, x, b, y;
		cin >> a >> x >> b >> y;
		st[a - 1] = x + 1;
		st[b - 1] = y + 1;
		poi(0, -1);
		cout << (min(f[0][0], f[0][1])) << endl;
		st[a - 1] = 0;
		st[b - 1] = 0;
	}
	return 0;
}
