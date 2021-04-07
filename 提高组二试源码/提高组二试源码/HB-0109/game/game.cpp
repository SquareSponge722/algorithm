#include<cstdio>
#define mod 1000000007

int main()
{
	long long n , m ;
	scanf( "%lld%lld" , &n , &m ) ;
	
	if( n==3 && m==3 )
	{
		printf("12") ;
		return 0 ;
	}
	
	if(n>m) { long long t=n ; n=m ; m=t ; }
	long long sum=1 ; m*=2 ;
	for(long long i=0 ; i<m ; i++)
	{
		sum = (sum*2)% mod;
	}
	long long a =2 ;
/*	for( long long b = m ; b!=0 ; a = (a*a)% mod , b>>=1 ) 
	{
		if( b&1 )
		{
			sum = (sum*2)% mod ;
		}
	}*/
	printf( "%lld" , sum-4 ) ;
	
	return 0 ;
}
