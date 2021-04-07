#include <bits/stdc++.h>
using namespace std;

const int M = 5000;
int len[M+1];

int isDif( int num, int end );

int main()
{
	freopen ( "travel.in", "r", stdin);
	freopen ( "travel.out", "w", stdout);
	
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;
	int pos1[m], pos2[m];
	int com[n];
	int cnt = 0;
	int pos;
	
	for ( i=0; i<m; i++ ) scanf("%d %d", &pos1[i], &pos2[i]);	
	
	len[0] = 1;
	int last = len[0];
	
	for ( i=1; i<n; i++ ){
		cnt = 0;
		for ( j=0; j<m; j++ ){
			int x = pos1[j];
			int y = pos2[j];
			if ( x==last&&isDif(y, i) ){
			    com[cnt++] = y;
		    }
			if ( y==last&&isDif(x, i) ){
			    com[cnt++] = x;
			}
		}
	 	int min = n+1;
	 	for ( j=0; j<cnt; j++ ) if ( com[j]<min ) min = com[j];
	 	if ( min==n+1 ){
	 		last = len[--pos];
	 		i --;
		 }else{
		 	pos = i;
		 	len[i] = min;
		 	last = min;
		 }
	}
	
	for ( i=0; i<n; i++ ) printf("%d ", len[i]);
	
	return 0;
}

int isDif( int num, int end )
{
	int ret = 1;
	int i;
	
	for ( i=0; i<end; i++ ){
		if ( len[i]==num ){
			ret = 0;
			break;
		}
	}
	
	return ret;
}
