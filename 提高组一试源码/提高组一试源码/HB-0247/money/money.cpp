#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define maxn 25010
using namespace std ;
int  n , a[ 110 ] , t;
int main ()
{
	freopen("money.in","r",stdin) ;
	freopen("money.out","w",stdout) ;
	ios::sync_with_stdio( false ) ;
	cin >> t ;
	while( t-- )
	{
	cin >> n ; int num = 1 ;
	for ( int i = 1 ; i <= n ; i ++ )
		cin >> a[ i ] ;
	sort ( a + 1 , a + 1 + n ) ;
	if( a[ 1 ] == 1 ) 
	{
		cout << 1 << endl;
		continue ;
	}
	int b[ 110 ] , pp = 1, ma = a[ n ] ; b[ 1 ] = a[ 1 ] ;
	bool c[ ma + 2 ] ;
	memset( c , false ,sizeof c ) ;
	for	( int i = b[ 1 ] ; i <= ma ; i += b[ 1 ] )
		c[ i ] = true ;
	for ( int i = 2 ; i <= n ; i ++ )
	{

		if( c[ a[ i ] ] )
			continue ;
		num ++ ; c[ a[ i ] ] = true ;
		for( int j = 1 ; j <= ma ; j ++ )
			if( c[ j ] && j + a[ i ] <= ma ) c[ j + a[ i ] ] = true ;
	}
	cout << num << endl ;
}
	return 0 ;
}
