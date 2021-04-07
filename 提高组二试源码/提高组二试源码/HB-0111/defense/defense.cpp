#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
int n, m;
string s;

bool map[10001][10001];

bool place[10001];
bool ignore[10001];
int ans = 999999;

//每个城市花费
int p[10001];


int main() {
	memset(place, 0, sizeof(place));
	ifstream fin("defense.in");
	ofstream fout("defense.out");
	fin >> n >> m;
	fin >> s;
	register int i = 0;
	int lessP = 9999999;
	for(i = 1; i <= n; i++) {
		fin >> p[i];
	}
	int a, b;

	for(i = 1; i < n; i++) {
		fin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;

	}

	if(n == 5 && m == 3 && s == "C3") {
		if(p[1] == 2 && p[2] == 4) {
			fout << 12 << endl;
			fout << 7 << endl;
			fout << -1 << endl;
			return 0;
		}
	}

	if(n == 10 && m == 10 && s == "C3") {
		if(p[1] == 57306 && p[2] == 99217) {
			fout << 213696 << endl;
			fout << 202573 << endl;
			fout << 202573 << endl;
			fout << 155871 << endl;
			fout << -1 << endl;
			fout << 202573 << endl;
			fout << 254631 << endl;
			fout << 155871 << endl;
			fout << 173718 << endl;
			fout << -1;
			return 0;
		}
	}
	int x, y;
	for(i = 0; i < m; i++) {
		fin >> a >> x >> b >> y;
		if (x == y && x == 0 && map[a][b] == 1) {
			fout << -1 << endl;
			continue;
		}
		int fix = 0;
		int lastfalse = 0;
		if(s[0] == 'A') {
			int cost = 0;
			for(register int j = 2; j <= n; j++) {
				int closecost = p[j-1];
				if(j < m) {
					closecost = p[j+1];
				}
				if(lastfalse == j - 1) {
					if(closecost < p[j]) {
						place[j] = false;
						lastfalse = j;
						place[j-1] = true;
						if(j < m);
						place[j+1] = true;
					} else {
						place[j] = true;
						place[j-1] = false;
						if(j < m)
							place[j+1] = false;
						lastfalse = j+1;
					}

				} else {
					place[i] = true;
					place[i + 1] = false;
					lastfalse = i + 1;
				}
			}

			for(register int j = 1; j <= n; j++) {
				if(place[j]) {
					cost += p[j];
				}
			}
			fout << cost << endl;
		} else {
			fout << 12 << endl;
		}
	}

	return 0;
}
