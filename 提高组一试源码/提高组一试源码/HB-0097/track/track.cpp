#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>

using namespace std;

const int MAXN = 5e4 + 5;

int n, m, l, maxx, minn, sum;
int a[MAXN], b[MAXN];
bool flag;

inline int read ();

int main ()
{
	freopen ("track.in", "r", stdin);
	freopen ("track.out", "w", stdout);
	
	n = read (), m = read ();
	flag = 0;
	for (int i = 1; i < n; ++i){
		a[i] = read (), b[i] = read ();
		l = read ();
		if (b[i] = a[i] + 1) flag = 1;
		if (maxx < l){
			minn = maxx;
			maxx = l;
		}
		sum += l;
	}
	if (flag) printf ("%d", sum);
	else printf ("%d", minn + maxx);
	
	
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
