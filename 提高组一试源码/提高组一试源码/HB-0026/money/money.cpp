#include <bits/stdc++.h>
using namespace std;

inline int read(int u = 0, char c = getchar(), bool f = false) {
	for (;!isdigit(c); c = getchar()) f |= c == '-';
	for (; isdigit(c); c = getchar()) u = u * 10 + c - '0';
	return f ? -u : u;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1; y = 0;
		return a;
	} else {
		int d = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return d;
	}
}

bool check(int a, int b, int c) {
	int x, y, d = exgcd(a, b, x, y);
	if (c % d != 0) return false;
	int _a = a / d, _b = b / d, _c = c / d;
	if (_a * _b - _a - _b < _c) return true;	
	x *= c / d; y *= c / d;
	while (x < 0) {
		x += _b; y -= _a;			
	}
	while (y < 0) {
		y += _a; x -= _b;
	}
	return (x >= 0) && (y >= 0);
}

bool check(int a, int b, int d, int x, int y, int c) {
	//cout << a << ' ' << b << ' ' << d << ' ' << x << ' ' << y << ' ' << c << endl;
	if (c % d != 0) return false;
	int _a = a / d, _b = b / d, _c = c / d;
	if (_a * _b - _a - _b < _c) return true;	
	x *= c / d; y *= c / d;
	while (x < 0) {
		x += _b; y -= _a;			
	}
	while (y < 0) {
		y += _a; x -= _b;
	}
	return (x >= 0) && (y >= 0);
}

const int maxn = 200;
const int maxm = 25000 + 10;

int a[maxn], b[maxn];

bool del[maxn];

vector<int>G[maxm];
int dis[maxm], tmp[maxm];
bool vis[maxm];

struct Node {
	int dis, id;
	Node (int _dis, int _id) {
		dis = _dis; id = _id;
	}
	friend bool operator < (const Node &a, const Node &b) {
		return a.dis > b.dis;
	}
};

priority_queue<Node>pq;

void dijkstra(int A, int n, int id) {
	memset(dis, 0x3f, sizeof(int) * (A + 1));
	memset(vis, 0, sizeof(bool) * (A + 1));		
	
	//cout << "#"; for (int i = 0; i < n; i++) if (i != id) cout << a[i] << ' '; cout << endl;
	
	dis[0] = 0;
	pq.push(Node(0, 0));
	while (pq.size()) {
		int u = pq.top().id; 
		pq.pop();
		if (vis[u]) continue; vis[u] = true;
		for (int i = 1; i < n; i++) if (i != id) {
			int v = (u + a[i]) % A, w = dis[u] + (u + a[i]) / A;
			if (dis[v] > w) {
				dis[v] = w;
				pq.push(Node(dis[v], v));
			}
		}
	}
}

bool cmp(int *A, int *B, int n) {
	for (int i = 0; i < n; i++)
		if (A[i] != B[i]) return false;
	return true;
}

int deal(int n) {
	sort(a, a + n);
	int A = a[0];
	
	//cout << "GG" << endl;
	dijkstra(A, n, -1);
	
	for (int i = 0; i < A; i++) tmp[i] = dis[i];
	//for (int i = 0; i < A; i++) cout << dis[i] << ' '; cout << endl;
	
	for (int i = 1; i < n; i++) {
		//cout << "GG" << endl;
		dijkstra(A, n, i);
		
		//for (int j = 0; j < A; j++) cout << dis[j] << ' '; cout << endl;
		
		if (cmp(dis, tmp, A)) {
			for (int j = i + 1; j < n; j++)	{
				a[j - 1] = a[j];
			}
			i--, n--;
		}
	}
	return n;
}

void work() {
	memset(del, 0, sizeof del);
	int n = read(), _gcd = 0;
	for (int i = 0; i < n; i++) a[i] = read();
	for (int i = 0; i < n; i++) _gcd = gcd(a[i], _gcd);
	for (int i = 0; i < n; i++) a[i] /= _gcd;
	for (int i = 0; i < n; i++) if (!del[i]) {
		for (int j = i + 1; j < n; j++) if (!del[j]) {
			if (a[i] == a[j]) del[j] = true;
			else {
				if (a[i] % a[j] == 0) {
					del[i] = true;
				}
				if (a[j] % a[i] == 0) {
					del[j] = true;
				}
			}
		}
	}
	b[0] = 0;
	for (int i = 0; i < n; i++) if (!del[i]) b[++b[0]] = a[i];
	n = b[0];
	for (int i = 0; i < n; i++) a[i] = b[i + 1];
		
	cout << deal(n) << endl;
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	int T = read();
	while (T--) work();
	return 0;
} 
