#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <queue>
#include <cstring>
#include <set>
#include <vector>


using namespace std;
int n, m;
bool map[5001][5001];
int pre[5001];
bool visited[5001];
bool pushed[5001];
int s[5001];
priority_queue<int, vector<int>, greater<int> > q;
priority_queue<int, vector<int>, greater<int> > q2;
priority_queue<int, vector<int>, greater<int> > q3;

inline bool pass(int from, int to) {
	if(map[from][to] || pre[from] == to || from == to) {
		return true;
	}

	vector<int> v;
	int i = from;
	int j = to;
	while(pre[i] > 0) {
		i = pre[i];
		if(map[from][to]) {
			return true;
		}
		v.push_back(i);
	}

	while(pre[j] > 0) {
		int p = pre[j];
		for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			if(p == *it) {
				return map[*it][j];
			}
		}
		j = pre[j];
	}
	return false;
}

inline void dfs(int index = 0, int now = 1) {
	if(index == n - 1) {
		s[index] = now;
		return;
	}

	s[index] = now;
	visited[now] = true;
	for(int i = 1; i <= n; i++) {
		if(!visited[i] && map[now][i]) {
			if(!pushed[i]) {
				q.push(i);
				pushed[i] = true;
			}
			pre[i] = now;
		}
	}

	int next;
	bool cq2 = false;
	if(!q.empty()) {
		next = q.top();
		q.pop();
	} else if(!q2.empty()) {
		next = q2.top();
		cq2 = true;
		q2.pop();
	} else {
		next = q3.top();
		q3.pop();
	}

	while(!q.empty() && !pass(next, q.top())) {
		q2.push(next);
		next = q.top();
		q.pop();
	}


	while(!q2.empty() && !pass(next, q2.top())) {
		if(!q2.empty()) {
			q3.push(next);
			next = q2.top();
			q2.pop();
		} else {
			next = q3.top();
			q3.pop();
			break;
		}
	}

	map[now][next] = false;
	pre[next] = now;
	dfs(index+1, next);
}


int main() {
	memset(pre, 0, sizeof(pre));
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	memset(visited, 0, sizeof(visited));
	fin >> n >> m;
	int a, b;
	register int i = 0;
	for(; i < m; i++) {
		fin >> a >> b;
		if(a == b) {
			continue;
		}
		map[a][b] = 1;
		map[b][a] = 1;
	}

	dfs();
	for(i = 0; i < n-1; i++) {
		fout << s[i] << " ";
	}
	fout << s[n-1];

	return 0;
}
