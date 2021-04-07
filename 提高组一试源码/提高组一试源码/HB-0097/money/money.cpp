#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

const int MAXN = 3e4 + 5;

int T, n, tmp, maxx;
int a[MAXN];
bool ok, flag;

inline int read ();

int main ()
{
	freopen ("money.in", "r", stdin);
	freopen ("money.out", "w", stdout);
	
	T = read ();
	while (T--){
		n = read ();
		flag = 0;
		ok = 1;
		for (int i = 1; i <= n; ++i){
			a[i] = read ();
			if (a[i] == 1) flag = 1;
			if (i >= 2 && a[i] % a[i - 1] != 0) ok = 0;
		}
		if (flag){
			printf ("1\n");
			continue;	
		}
		if (ok){
			printf ("1\n");
			continue;
		}
		sort (a + 1, a + 1 + n);
		if (n == 2){
			printf ("2\n");
			continue;
		}
		if (n == 3){
			if (__gcd(a[1], a[2]) == a[1]){
				printf ("2\n");
			}				
			else if (__gcd(a[1], a[3]) == a[1]){
				printf ("2\n");
			}
			else if (__gcd(a[2], a[3]) == a[2]){
				printf ("2\n");
			}
			else {
				maxx = a[1] * a[2] - a[1] - a[2];
				if (maxx < a[3]){
					printf ("2\n");
				}
				else {
					printf ("3\n");
				}
			}
			continue;
		}
		for (int i = 2; i <= n; ++i){
			if (a[i] % a[1] != 0){
				maxx = a[2] * a[1] - a[1] - a[2];
				tmp = i;
//				printf ("tmp = %d\n", tmp);
				break;
			}
		}
		
		int cnt = 2;
		for (int i = tmp + 1; i <= n; ++i){
			if (a[i] <= maxx){
				maxx = a[1] * a[i] - a[1] - a[i];
				cnt ++;
			}
		}	
		printf ("%d\n", cnt);	
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
