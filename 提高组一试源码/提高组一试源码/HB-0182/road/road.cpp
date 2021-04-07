#include <bits/stdc++.h>
using namespace std;

const int M = 100000;
int road[M+1];


int min( int len, int less, int *p );

int main()
{
	freopen ( "road.in", "r", stdin );
	freopen ( "road.out", "w", stdout );
	
	int n;
	scanf("%d", &n);
	int i;
	int day = 0;
	int minNum = M;
	int count;
	
	for ( i=1; i<=n; i++ ){
	    scanf("%d", &road[i]);
	    if ( road[i]<minNum ) minNum = road[i];
	}
	
	day += minNum;
	while ( n ){
		minNum = min( n, minNum, &count );	    
		day += minNum*count;
		
	    if ( !minNum ) break;
	}
	
	printf("%d", day);
	
	return 0;
}

int min( int len, int less, int *p)
{
	int ret = M;
	int ret2 = 0;
	int able = 0;
	int cnt = 0;
	int i;
	for ( i=1; i<=len; i++ ){
		if ( road[i] ) road[i] -= less;
	    if ( road[i]<ret&&road[i] ) ret = road[i];
	    if ( road[i] ){
		    able = 1;
		}else{
			able = 0;
		}
		if ( able ){
	    cnt ++;
		}else{
			if ( cnt ) ret2 ++;
			cnt = 0;
		}
		if ( i==len&&cnt ) ret2 ++;
    }
    if ( ret==M ) ret = 0;
    
    *p = ret2;
	
	return ret;
}
