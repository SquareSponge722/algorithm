#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5005
#define maxm 5005
using namespace std ;

struct bian{int qidian , zhongdian , changdu ; } tu[maxm<<1] ;
int bingchaji[maxn] ;
bool is_used[maxm<<1] ;
bool is_qidian[maxn] ;
int ansq[maxn] , ansz[maxn];
int n , m ;

bool paixu(const bian &a , const bian &b)
{
	return a.changdu < b.changdu ;
}

int main()
{
	scanf( "%d%d" , &n , &m ) ;
	int u , v ;
	for(int i=1 ; i<=n ; i++)
		bingchaji[i] = i ;
	for(int i=1 ; i<=m ; i++ )
	{
		scanf( "%d%d" , &u , &v ) ;
		tu[i] = (bian){ u , v , v-u } ;
		tu[i+m] = (bian){ v , u , u-v } ;
	}
	sort( tu+1 , tu+m*2+1 , paixu ) ;
	ansq[1] = 1 ;
	int k = m ; m <<= 1 ;
	while( tu[++k].qidian != 1 ) ;
	is_used[k] = true ; is_qidian[1] = true ; is_qidian[tu[k].zhongdian] = true ; ansz[1] = tu[k].zhongdian ;
	for(int i=2 ; i<=n ; i++)
	{
		for(int j=1 ; j<=m ; j++)
		{
			if( !is_used[j] && is_qidian[ tu[j].qidian ] && !is_qidian[ tu[j].zhongdian ] )
			{
				ansq[i] = tu[j].qidian ;
				ansz[i] = tu[j].zhongdian ;
				is_used[j] = true ;
				is_qidian[ tu[j].zhongdian ] = true ;
				break ;
			}
		}
	}
	for(int i=1 ; i<=n ; i++)
		printf("%d " , ansq[i] ) ;
	printf("\n");
	for(int i=1 ; i<=n ; i++)
		printf("%d " , ansz[i] ) ;
//	printf( "From %d to %d = %d" , tu[k].qidian , tu[k].zhongdian , tu[k].changdu ) ;
	return 0 ;
}
