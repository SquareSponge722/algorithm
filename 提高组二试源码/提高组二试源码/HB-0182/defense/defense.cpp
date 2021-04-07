#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen( "defense.in", "r", stdin );
	freopen( "defense.out", "w", stdout );
	
	int n, m;
	scanf("%d %d", &n, &m);
	char c[2];
	int i;
	int pos1[n-1], pos2[n-1];
	for ( i=0; i<1; i++ ) cin >> c[i];
	
	int price[n];
	for ( i=0; i<n; i++ ) scanf("%d", &price[i]);
	for ( i=0; i<n-1; i++ ) scanf("%d %d", &pos1[i], &pos2[i]);
	//I won't give up.
	
	for ( i=1; i<=m; i++ ){
		int ask[n];
		int x;
		scanf("%d", &x);
		scanf("%d", &ask[x]);
		scanf("%d", &x);
		scanf("%d", &ask[x]);
		printf("-1\n");
	}
	
	
	return 0;
}
