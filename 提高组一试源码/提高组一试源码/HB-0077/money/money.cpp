#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 25020;

bool f[maxN], m[maxN];
vector<int> p;
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int q;
	cin >> q;
	while(q--) {
		int n, rm = 0, mx = 0;
		cin >> n;
		p.resize(n);
		for(int i = 0; i < n; i++)
			cin >> p[i];
			
		sort(p.begin(), p.end());
		mx = p.back();
		
		memset(f, 0, (mx + 1) * sizeof(bool));
		f[0] = true;
		for(int i = 0; i < n; i++) {
			memset(m, 0, (p[i] + 1) * sizeof(bool));
			bool flag = false;
			for(int j = 0; j <= mx; j++)
				if(f[j])
					m[j % p[i]] = true;
				else if(m[j % p[i]])
					flag = true, f[j] = true;
			rm += !flag;
		}
		cout << n - rm << '\n';
	}
	cout << flush;
	return 0;
}
