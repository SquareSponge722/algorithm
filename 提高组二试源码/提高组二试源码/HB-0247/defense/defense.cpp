#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define maxn 101000
using namespace std ;
struct nod{
	int to ;
	int nex ;
}edge[ maxn << 1 ];
int hea[ maxn ] , n , m , nu , t[ maxn ] , son[ maxn ];
string s ;
long long g[ maxn ][ 2 ] ;
bool book[ maxn ] , ll[maxn ];
void ad ( int u , int v )
{
	edge[ ++ nu ] = ( nod ) { v , hea[ u ]} ;
	hea[ u ] = nu ;
	edge[ ++ nu ] = ( nod ) { u , hea[ v ] } ;
	hea[ v ] = nu ;
}
	int  a, x, b , y ;
void dfs( int u )
{
	book[ u ] = true ; 
	for( int i = hea[ u ] ; i ; i = edge[ i ].nex)
	{
		int v = edge[ i ].to ;
		if( book[ v ] ) continue ;
		dfs( v ) ; 
		if( u == a )
		{
			if( x == 0 )
			{
				g[ u ][ 0 ] +=g[ v ][ 1 ] ;
				g[ u ][ 1 ] = 210000000000;
			}
			else 
			{
				g[ u ][ 1 ] +=  min ( g[ v ][ 0 ] , g[ v ][ 1 ]);
				g[ u ][ 0 ] = 210000000000 ;
			}
		}
		else if( u == b )
		{
			if( y == 0 )
			{
				g[ u ][ 0 ] += g[ v ][ 1 ] ;
				g[ u ][ 1 ] = 210000000000;
			}
			else 
			{
				g[ u ][ 1 ] += min ( g[ v ][ 0 ] , g[ v ][ 1 ]);
				g[ u ][ 0 ] = 210000000000 ;
			}
		}
		else
		{
			g[ u ][ 0 ] += g[ v ][ 1 ] ;
			g[ u ][ 1 ] += min ( g[ v ][ 0 ] , g[ v ][ 1 ]) ;
		}
	}
}
int main ()
{
	freopen("defense.in","r",stdin) ;
	freopen("defense.out","w",stdout) ;
	ios::sync_with_stdio( false ) ;
	cin >> n >> m >> s ;
	for( int i = 1 ; i <= n ; i ++ )
		cin >> t[ i ] ;
	for( int i = 1 ; i < n ; i ++ )
	{
		int u , v ;
		cin >> u >> v ;
		ad( u , v ) ;
	}
	for( int i = 1 ; i <= m ; i ++ )
	{
		cin >> a >> x >> b >> y ;
		memset( book , false , sizeof book ) ;
		for( int i = 1 ; i <= n ; i ++ )
			g[ i ][ 0 ] = 0 , g[ i ][ 1 ] = t[ i ] ; 
		g[ 0 ][ 0 ] = g[ a ][ ! x ] = g[ b ][ ! y ] = 21000000000 ;
		dfs( 1 ) ;
		long long o = min ( g[ 1 ][ 0 ] , g[ 1 ][ 1 ] ) ;
		if( o >= g[ 0 ][ 0 ] )
			cout << -1 << endl ;
		else cout << o << endl;
	}
	return 0 ;
}
