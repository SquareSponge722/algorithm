#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>

#define N 110
#define M 25010

using namespace std;

int t, n, r;
int f[M];
priority_queue <int, vector<int>, greater<int> > q;
vector <int> v;

void init() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
}

int main() {
	init();
	scanf("%d", &t);
	while(t --) {
		scanf("%d", &n);
		memset(f, 0, sizeof(f));
		f[0] = 1;
		r = 0;
		v.clear();
		
		for(int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			r = max(r, x);
			q.push(x);
		}
		
		int a = q.top();
		q.pop();
		v.push_back(a);
		for(int i = 1; (a * i) <= r; i ++)
			f[a * i] = 1;
		
		
		while(!q.empty()) {
			int x = q.top();
			q.pop();
			if(f[x])
				continue;
			v.push_back(x);
			for(int i = 0; i <= r; i ++) 
				if(f[i])
					for(int j = 1; (i + x * j) <= r; j ++)
						f[i + x * j] = 1;
		}
		printf("%d\n", v.size());
	}	
	return 0;
}
