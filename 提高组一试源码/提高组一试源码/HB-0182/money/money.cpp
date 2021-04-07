#include <bits/stdc++.h>
using namespace std;

const int M = 25000;

int main()
{
	freopen( "money.in", "r", stdin );
	freopen( "money.out", "w", stdout );
	
	int t;
	int cnt;
	int i, j;
	scanf("%d", &t);
	
	for ( cnt=1; cnt<=t; cnt++ ){
		int n;
		scanf("%d", &n);
		int a[n];
		
		int min1 = M;
		int min2 = M;
		int pos;
		for ( i=0; i<n; i++ ){
		    scanf("%d", &a[i]);
		    if ( a[i]<min1 ){
			    min1 = a[i];
			    pos = i;
	    	}
	    }
		
		for ( i=0; i<n; i++ ){
			if ( a[i]<min2&&i!=pos ) min2 = a[i];
		}
		
		int max0 = min1*min2;
		
		for ( i=0; i<n; i++ ){
			int x = a[i];
			if ( x==0||x>=max0 ){
				a[i] = 0;
		        continue;
		    }
			for ( j=0; j<n; j++){
				int y = a[j];
				if ( i==j ) continue;
				if ( y==0||y>=max0 ){
				    a[j] = 0;
		    		continue;
	    		} 
			    if ( (x%y)*(y%x)==0 ){
					if ( x>y ) a[i] = 0;
					if ( x<=y ) a[j] = 0;
				}
			}
		}
		
		int cnt0 = 0;
		for ( i=0; i<n; i++ ) if ( !a[i] ) cnt0++;
		int m = cnt0;	
		printf("%d\n", m+(!m)*n);
	}
	
	return 0;
}
