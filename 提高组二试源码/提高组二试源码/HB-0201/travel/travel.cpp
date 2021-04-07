#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 60000;

int ans[N] , tot ; 
struct edge{
	int v , n , w ; 
}e[N<<1];int head[N];
int n , m ; 
int minson[N];
bool vis[N];

void dfs( int p ){
	vis[p] = 1;
	for( int i = head[p] ; i ; i = e[i].n ){
		int tv = e[i].v ; 
		if( !vis[tv] ){
			if( !minson[p] || tv < minson[p] ) minson[p] = tv ; 
			dfs( tv );
		} 
	}
}

void dfs2( int p ){
	ans[++tot] = p ; vis[p] = 1 ; 
	if( minson[p] ) dfs2( minson[p] );
	for( int i = head[p] ; i ; i = e[i].n ){
		int tv = e[i].v ; 
		if( !vis[tv] ){
			dfs2( tv );
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d" , & n , & m );
	int u , v ;
	for( int i = 1; i <= m ; i ++ ){
		scanf("%d%d" , & u , & v );
		e[i] = ( edge ){ v , head[u] };
		e[i+m] = ( edge ){ u , head[v] };
		head[u] = i ; head[v] = i+m ;
	}
	dfs( 1 );
	memset( vis , 0 , sizeof( vis ) );
	dfs2( 1 );
	for( int i = 1; i <= tot ; i ++ )printf("%d " , ans[i] );
	return 0;
}
