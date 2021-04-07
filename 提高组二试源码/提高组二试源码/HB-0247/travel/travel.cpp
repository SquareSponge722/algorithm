#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>//需要回溯 
#include <algorithm>
#define maxn 5100
#define maxm 10100
using namespace std ;
int n , m , nu , hea[ maxn ] , xulie[ maxn ] ;// 记录每次搜完后的字典序最小的数列 
int cnt ;//记录访问城市的个数 

bool book[ maxn ] ;
struct nod{
	int to ;
	int nex ;
}edge[ maxm ] , u1[ maxm ];
void ad ( int u , int v )
{
	edge[ ++ nu ] = ( nod ) { v , hea[ u ] } ;
	hea[ u ] = nu ;
	edge[ ++ nu ] = ( nod ) { u , hea[ v ] } ;
	hea[ v ] = nu ;
}
bool cmp ( nod a , nod b )
{
	if( a.nex == b.nex ) return a.to > b.to ;
	return a.nex > b.nex ;
}
void dfs1 ( int u )
{
	book[ u ] = true ; xulie[ ++ cnt ] = u ;
	for( int i = hea[ u ] ; i ; i = edge[ i ].nex )
	{
		int v = edge[ i ].to ;
		if( ! book[ v ] ) dfs1 ( v ) ; 	
	} 
}
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio( false ) ;
	cin >> n >> m ; 
		for ( int i = 1 ; i <= m ; i ++ )
		{
			int u , v ;
			cin >> u >> v ;
			if ( u < v ) swap ( u , v ) ;
			u1[ i ].nex = u , u1[ i ].to = v ;  
		}
		sort( u1 + 1 , u1 + m + 1 , cmp ) ;
		for( int i = 1 ; i <= m ; i ++ )
		{
			ad( u1[ i ].nex , u1[ i ].to ) ;
		}
		dfs1( 1 ) ; 
		for( int i = 1 ; i <= n ; i ++ )
			cout << xulie[ i ] << ' ' ;
		return 0 ;
}
