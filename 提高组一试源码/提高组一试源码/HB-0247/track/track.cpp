#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define maxn 50010
using namespace std ;
int nu ,maxx = 0 , edw[ maxn ] , hea[ maxn ] , n , m , son1[ maxn ] ,son2 , b[maxn ];
bool bo1 = false , book[ maxn ] ;
struct node {
	int to ;
	int nex ;
	int w ;
}edge[ maxn ];
void ad ( int u , int v , int w )
{
	edge[ ++ nu ] = ( node ) { v , hea[ u ] , w } ;
	hea[ u ] = nu ; 
	edge[ ++ nu ] = ( node ) { u , hea[ v ] , w } ;
	hea[ v ] = nu ;
}
bool iis( int k )
{
	int mm = m ;
	for( int i = 1 , j = 0; i <= n ; i ++ )
	{
		if( b[ i ] - b [ j ] >= k )
		{
			j = i ;
			mm -- ;
			if( ! mm ) return true ;
		}
	}
	return false;
}
void dfs1 ( int u )
{
	book[ u ] = true ;
	for( int i = hea[ u ] ; i ; i = edge[ i ].nex )
	{
		int v = edge[ i ].to , w = edge[ i ].w ;
		if( ! book[ v ] ) 
		{
			dfs1( v ) ;
			son1[ u ] = max ( son1[ u ] , w + son1[ v ] ) ;
		}
	}
}
int main ()
{
	freopen("track.in","r",stdin) ;
	freopen("track.out","w",stdout) ;
	ios::sync_with_stdio( false ) ;
	cin >> n >> m ;
	for( int i = 1 ; i < n ; i ++ )
	{
		int u , v , w ;
		cin >> u >> v >> w ; b[ i ] = b[ i - 1 ] + w ; 
		ad( u , v , w ) ;
		if( v != u + 1 ) bo1 = true ;
	}
	if( m == 1 )
	{
		int res = 0 ;
		for( int kk = 1 ; kk <= n ; kk ++ )
		{
		memset( book , false , sizeof book ) ;
		memset( son1 , 0 , sizeof son1 ) ; son2 = 0 ;
		book[ kk ] = true ;
			for( int i = hea[ kk ] ; i ; i = edge[ i ].nex )
			{
				int v = edge[ i ].to , w = edge[ i ].w ;
				dfs1( v ) ;
				if( son1[ kk ] < son1[ v ] + w )
				{
					son2= son1[ kk ] ;
					son1[ kk ] = son1[ v ] + w ;
				}
				else if( son2 < son1[ v ] + w )
					son2 = son1[ v ] + w ;
			}
		res = max ( res , son2 + son1[ kk ] ) ;
		}
		cout <<res ;
		return 0 ;
	}
	if( ! bo1 )
	{
		int l = 0 , r = b[ n - 1 ] ,res = 0 ;
		while( l <= r )
		{
			int mid = ( l + r ) >> 1 ;
			if( iis( mid ) )
			{
				res = l ;
				l = mid + 1 ;
				
			}
			else r = mid - 1 ;
		}
		cout << res ;
	}
	return 0 ;
}
