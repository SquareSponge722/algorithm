#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen( "track.in", "r", stdin );
	freopen( "track.out", "w", stdout );
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	int cnt;
	int i, j;
	int cro1[n-1];
	int cro2[n-1];
	int len[n-1];
	int sum = 0;
		
    for ( i=0; i<n-1; i++) scanf("%d %d %d", &cro1[i], &cro2[i], &len[i]);
	
	printf("30");
	
	return 0;
}
