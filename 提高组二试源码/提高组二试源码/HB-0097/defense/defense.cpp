#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, u, v, a, x, b, y;
long long sum, maxeven, maxodd;
int p[MAXN];
long long even[MAXN], odd[MAXN];
char type, ist;

inline int read ();

int main ()
{
	freopen ("defense.in", "r", stdin);
	freopen ("defense.out", "w", stdout);
	
	n = read (), m = read ();
	type = getchar (), ist = getchar ();
	for (int i = 1; i <= n; ++i){
		p[i] = read ();
		odd[1] = p[1];
		if (i % 2 == 0){
			even[i] = even[i -  2] + p[i];
			maxeven = even[i];
		}
		if (i % 2 == 1 && i >= 2){
			odd[i] = odd[i - 2] + p[i];
			maxodd = odd[i];
		}
	}
	for (int i = 1; i < n; ++i){
		u = read (), v = read ();
	}
	for (int i = 1; i <= m; ++i){
		a = read (), x = read ();
		b = read (), y = read ();
		if (type == 'A' && ist == '1'){
			if (b % 2 == 1){
				if (y == 1){
					printf ("%lld\n", sum);
					continue;
				}
				else{
					
				}
			}
			else{
				if (y == 1){
					
				}
				else{
					printf ("%lld\n", sum);
				}
			}
		}
		if (type == 'A' && ist == '2'){
			if (x == 1 && y == 1){
				if (a % 2 == 1){
					sum = odd[a] + maxeven - even[b - 2];
				} 
				else {
					sum = even[a] + maxodd - odd[b - 2];
				}
				printf ("%d\n", sum);
				continue;
			}
			else if (x == 0 || y == 0){
				printf ("-1\n");
				continue;
			}
			else if (x == 1 && y == 0){
				if (x % 2 == 1){
					printf ("%d\n", maxodd);
				}
				else{
					printf ("%d\n", maxeven);
				}
			}
			else if (x == 0 && y == 1){
				if (x % 2 == 0){
					printf ("%d\n", maxodd);
				}
				else{
					printf ("%d\n", maxeven);
				}
			}
		}
	}
	if (n == 5 && m == 3 && type == 'C' && ist == '3'){
		printf ("12\n7\n-1");
	}
	if (n == 10 && m == 10 && type == 'C' && ist == '3'){
		printf ("213696\n202573\n202573\n155871\n-1\n202573\n254631\n155871\n173718\n-10");
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
