#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>

using namespace std;

const int MAXN = 5e3 + 5;

int n, m, u, v, sp;
int deep[MAXN], du[MAXN], inq[MAXN];
int s[MAXN][3];
int adj[MAXN][MAXN];
bool flag;

inline int read ();
inline void DFS (int x);
inline void markDepth (int x);
inline void dfs (int x);

int main ()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	n =  read (), m = read ();
	for (int i = 1; i <= m; ++i){
		u = read (), v = read ();
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	
	if (m == n - 1) DFS (1);
	else {
//		cout << 'M' << endl;
		deep[1] = 1;
		markDepth(1);
/*		for (int i = 1; i <= n; ++i) cout << deep[i];
		cout << endl;
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j) cout << adj[i][j] << ' ';
			cout << endl;
 		}
		cout << sp << endl;
*/		for (int i = 1; i < sp; ++i){
			if (deep[i] == deep[sp] - 1){
				adj[i][sp] = 0;
				adj[sp][i] = 0;
				break;
			}
		}

		if (s[sp][1] > s[sp][2]) swap (s[sp][1], s[sp][2]);
		if (s[sp][2] > sp){
			adj[s[sp][2]][sp] = 0;
			adj[sp][s[sp][2]] = 0;
		}
//		cout << s[sp][1] << ' ' << s[sp][2] << endl; 
		dfs (1);
	}
	
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}

inline int read ()
{
	char ch = getchar ();
	int f = 1;
	while (!isdigit (ch)){
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	int x = 0;
	while (isdigit (ch)){
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
	return x * f;
}

inline void DFS (int x)
{
	printf ("%d ", x);
	 for (int i = 1; i <= n; ++i){
	 	if (adj[x][i]){
	 	 	adj[x][i] = 0;
	 	 	adj[i][x] = 0;
			 DFS (i);	
	 	}
	 }
	
}

inline void markDepth (int x)
{	
	if (flag) return ;
	for (int i = 1; i <= n; ++i){
		if (adj[x][i] == 1 && deep[i] == 0){
			adj[i][x] = 2;
			du[i] ++;
			s[i][du[i]] = x;
			if (du[i] == 2){
				flag = 1;
				sp = i;
				return ;
			}
//			cout << i << x << adj[i][x] << endl;
			deep[i] = deep[x] + 1;
		}
		else if (adj[x][i] == 1 && deep[i] < deep[x]){
			adj[x][i] = 2;
			du[x] ++;
			s[x][du[x]] = i;
			if (du[x] == 2){
				flag = 1;
				sp = x;
				return ;
			}
		}
	}
	for (int i = 1; i <= n; ++i){
		if (deep[i] == deep[x] + 1) markDepth (i);
	}
}

inline void dfs (int x)
{
	printf ("%d ", x);
	inq[x] = 1;
	 for (int i = 1; i <= n; ++i){
	 	if (adj[x][i]){
	 	 	adj[x][i] = 0;
	 	 	adj[i][x] = 0;
	 	 	if (!inq[i]) dfs (i);	
	 	}
	 }
	
}

