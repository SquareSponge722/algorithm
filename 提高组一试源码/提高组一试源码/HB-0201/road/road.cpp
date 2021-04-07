#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

const int N = 200010;

int c[N] , h[N];
int n ; 
struct mycchange{
	int l , r ;
}ms[N];
int myst[N] , mytop ;
long long ans ;
int num[N];

void myupdate( int p , int x ){ while( p <= n ) {  c[p] += x ; p += ( p & -p ) ;} }
int myquery( int p ){ int sum(0) ; while( p ){ sum += c[p] ; p -= (  p & -p ); } return sum ; }
bool cmp( const int & a , const int & b ){ return h[a] < h[b] ; }

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d", & n );
	for( int i = 1; i <= n ; i ++ ) scanf("%d" , & h[i] );
	myst[0] = 0 ; mytop = 0 ;
	for( int i = 1; i <= n ; i ++ ){
		while( mytop && h[i] <= h[myst[mytop]] ) mytop -- ; 
		myst[++mytop] = i ;
		ms[myst[mytop]].l = myst[mytop-1]+1 ;
	}
	mytop = 0 ;
	for( int i = 1; i <= n ; i ++ ){
		while( mytop && h[i] < h[myst[mytop]] ){ ms[myst[mytop]].r = i - 1;  mytop -- ; }
		myst[++mytop] = i ; 
	}
	while( mytop ) { ms[myst[mytop]].r = n ; mytop --;}
	for( int i =1 ; i <= n ; i ++ ) num[i] = i ; 
	sort( num+1 , num+n+1 , cmp );
	for( int i = 1; i <= n ; i ++ ){
		int zz = num[i];
		int ll = ms[zz].l , rr = ms[zz].r ;
		int th = myquery( zz ) ; int delta = h[zz] - th ;
		ans += delta ;
		myupdate( ll  , delta ); myupdate( rr+1 , -delta );
	}
	printf("%lld" , ans );
	return 0;
}
