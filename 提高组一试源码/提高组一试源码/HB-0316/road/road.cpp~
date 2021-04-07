#include <bits/stdc++.h>
using namespace std;
#define IL inline
IL int read() {
	char ch = getchar(); int u = 0, f = 1;
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { u = (u << 1) + (u << 3) + ch - 48; ch = getchar(); }
	return u * f;
}
const int INF = 1e9;
const int maxn = 1e5 + 10;
int n, a[maxn], sum, preL[maxn], preR[maxn], b[maxn];
int stk[maxn], top;

int dfs(int L, int R) {
	if (L > R) return 0;
	int rtn = 0;
	int Min = INF;
	for (int i = L; i <= R; ++i) Min = min(Min, a[i]);
	rtn += Min;
	vector<int>List; List.push_back(L);
	for (int i = L; i <= R; ++i) if (a[i] == Min) List.push_back(i);
	List.push_back(R);
	for (int i = L; i <= R; ++i) a[i] -= Min;
	for (int i = 1; i < List.size() - 1; ++i) {
		rtn += dfs(List[i - 1], List[i] - 1);
	}
	rtn += dfs(List[List.size() - 2] + 1, List[List.size() - 1]);
	return rtn;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	cout << dfs(1, n);
	return 0;
	/*
	for (int i = 1; i <= n; ++i) b[i] = read();
	int pos = -1;
	
	int ct = 0;
	for (int i = 1; i <= n; ++i) {
		if (b[i] != pos) a[++ct] = b[i], pos = b[i];		
	}
	
	cerr << "n = " << n << endl;
	n = ct; cerr << "n = " << n << endl;
	
	for (int i = 1; i <= n; ++i) sum += a[i];

	cerr << "sum = " << sum << endl;

	stk[++top] = 0;	
	for (int i = 1; i <= n; ++i) {
		while (top && a[i] < a[stk[top]]) top--;
		preL[i] = stk[top];
		stk[++top] = i;
	}
	while (top) stk[top] = 0, top--;
	stk[++top] = n + 1;
	for (int i = n; i >= 1; --i) {
		while (top && a[i] < a[stk[top]]) top--;
		preR[i] = stk[top];
		stk[++top] = i;
	}
//	for (int i = 1; i <= n; ++i) 
//		cerr << "l[i] = " << preL[i] << " r[i] = " << preR[i] << endl;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int L = preL[i], R = preR[i];
		int t;
		if (a[preL[i]] == a[i] || a[preR[i]] == a[i]) {
			if (a[preL[i]] == a[i]) t = a[preR[i]];
			else t = a[preL[i]];
		}
		else t = max(a[preL[i]], a[preR[i]]);
	//	cerr << "R - L - 2 = " << R - L - 2 << endl;
	//	cerr << "a[i] - t = " << a[i] - t << endl;
	//	sum -= (a[i] - t) * (R - L - 2);
	//	cerr << a[i] - t << endl;
		ans += (a[i] - t);
	}
	cout << ans << endl;
	*/
	return 0;
}
/*
5
2 2 2 2 2
*/
