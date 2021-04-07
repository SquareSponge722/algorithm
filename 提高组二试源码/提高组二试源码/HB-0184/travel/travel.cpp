#include <bits/stdc++.h>

#define maxn 5010

#define ll long long

using namespace std;

struct node {
	ll x;
	bool operator < (const node &a) const {
		return x > a.x;
	}
};

ll n, m, o[maxn], jsq; 

bool pp[maxn];

string s;

vector <ll> v[maxn];

queue <ll> q;

priority_queue <node> pq;

inline ll read() {
	ll f = 1, k = 0; char c = getchar();
	while(c > '9' || c < '0') {if(c == '-') f = -1; c = getchar();}
	while(c <= '9' && c >= '0') {k = k * 10 + c - '0'; c = getchar();}
	return k * f;
}

void LZRsearch() {
	q.push(1); o[++jsq] = 1; pp[1] = true;
	while(!q.empty()) {
		ll t1 = q.front();
		q.pop();
		for(ll i = 0; i < (int)v[t1].size(); i ++) {
			node e;
			e.x = v[t1][i]; 
			pq.push(e);
		}
		while(!pq.empty()) { //cout << "#43#" << endl;
			node t2 = pq.top();
			pq.pop();
			if(v[t2.x].size() == 0) {
				v[t1].pop_back();
				continue ;
			}
			if(v[t2.x].size() > 0) {
				if(pp[t2.x] != true) {
					pp[t2.x] = true;
					o[++jsq] = t2.x;
				}
				v[t1].pop_back();
				q.push(t2.x);
				break;
			}
			while(!pq.empty()) {
				pq.pop();
			}
		}
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n = read(); m = read();
	for(int i = 1; i <= m; i ++) { //cout << "#67#" << endl;
		ll start, end;
		start = read(); end = read();
		v[start].push_back(end);
		swap(start, end);
		v[start].push_back(end);
	}
	LZRsearch();
	for(int i = 1; i <= jsq; i ++) {
		printf("%lld ", o[i]);
	}
	return 0;
}
