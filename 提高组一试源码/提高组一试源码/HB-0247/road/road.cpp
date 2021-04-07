#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define maxn 100010
using namespace std ;
int a[ maxn ] , n , mi = 0x7fffffff , tot = 0 ; 
int main ()
{
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	ios::sync_with_stdio( false ) ;
	cin >> n ; int mi1 = mi ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[ i ] ;
		if ( a[ i ] ) 
		mi = min ( mi , a[ i ] ) ;
	}
	while( mi != 0x7fffffff )
	{
		mi1 = 0x7fffffff ; bool flag = false ;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			if ( a[ i ] && !flag ) 
			{	
				a[ i ] -= mi ;
				mi1 = min( a[ i ] , mi1 ) ;
				if ( ! a[ i + 1 ] )
					flag = true ;
			}
			else if ( ! flag )
				continue ;
			else break ;
		}
		tot += mi ;
		mi = mi1 ; 
	}
	cout << tot ;
	return 0 ;
}
