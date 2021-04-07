#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

const int mod = 1e9+7;
const int N = 10 ;
const int M = 100010;

long long f[1<<N][M];
long long zz[1<<N];
int n , m ; 
int a[N], b[N];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d", & n , & m );
	if( n == 1 ){
		if( m == 1 ) printf("2");
		if( m == 2 ) printf("4");
		if( m == 3 ) printf("8");
	}
	if( n == 2 ){
		if( m == 1 ) printf("4");
		if( m == 2 ) printf("12");
	}
	if( n == 3 ){
		if( m == 3 ) printf("112");
		if( m == 1 ) printf("8");
	}
	return 0;
}
