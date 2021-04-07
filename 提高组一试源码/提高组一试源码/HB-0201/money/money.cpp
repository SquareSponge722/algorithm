#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#include<set>
#include<queue>
using namespace std;

const int N = 200;

int a[N];
bool b[N];
int n ;
int t ;
 
int main( )
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d" , & t );
	while( t ){
		memset( a , 0 , sizeof( a ) );
		scanf("%d" , & n ); int ans(1) ; 
		for( int i =1 ; i <= n ; i ++ ) scanf("%d" , & a[i] );
		sort( a+1 , a+n+1 );
		for( int i = 2 ; i <= n; i ++ ){
			int zz = a[i] ;
			for( int j = i-1 ; j >=1; j -- ){
				zz %= a[j];
				if( zz == 0 ) break;
			}
			if( zz != 0 ) ans ++;
		}
		printf("%d\n" , ans );
		t--;
	}
	return 0;
}
