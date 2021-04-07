#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#define gc getchar
using namespace std;
const int MAXN = 1e5 + 7;
int n, res, now;
int d[MAXN], L[MAXN], R[MAXN];

template <class T>
inline void read(T &x){
	static char buf = gc(); x = 0;
	for (; !isdigit(buf); buf = gc());
	for (; isdigit(buf); buf = gc())
		x = (x << 3) + (x << 1) + buf - 48;
}

struct Ask{
	int LL, RR, ID, len;
	bool operator < (const Ask &x) const{
		return len > x.len;
	}
}ask[MAXN];

struct Upstack{
	stack < int > S;
	
	void Upd(int *a, int x){
		if (S.empty()) a[x] = 0;
		else a[x] = S.top();
	}
	
	void Push(int *a, int x){
		while (!S.empty() and d[S.top()] >= d[x])
			S.pop();
		Upd(a, x), S.push(x);
	}
}us1, us2;

struct TreeArray{
	#define lowbit(x) (x & (-x))
	int C[MAXN];
	
	void Upd(int pos, int x){
		for (int i = pos; i <= n; i += lowbit(i))
			C[i] += x;
	}
	
	int query(int pos){
		int cnt = 0;
		for (int i = pos; i >= 1; i -= lowbit(i))
			cnt += C[i];
		return cnt;
	}
}tr;

void work(){
	read(n);
	for (int i = 1; i <= n; ++i) 
		read(d[i]), tr.Upd(i, d[i] - d[i - 1]);
	for (int i = 1; i <= n; ++i) us1.Push(L, i);
	for (int i = n; i >= 1; --i) us2.Push(R, i);
	for (int i = 1; i <= n; ++i){
		ask[i].LL = (!L[i]) ? 1 : L[i] + 1;
		ask[i].RR = (!R[i]) ? n : R[i] - 1;
		ask[i].ID = i;
 		ask[i].len = ask[i].RR - ask[i].LL + 1;
	}
	sort(ask + 1, ask + n + 1);
	for (int i = 1; i <= n; ++i){
		int t = tr.query(ask[i].ID);
		res += t;
		tr.Upd(ask[i].LL, -t);
		tr.Upd(ask[i].RR + 1, t);
	}
	printf("%d\n", res);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	work(); 
	return 0;
}
