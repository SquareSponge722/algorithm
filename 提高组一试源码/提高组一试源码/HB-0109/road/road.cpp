#include<cstdio>

#define maxn  100005
using namespace std ;

struct dian{ int l,r ; int data ; } shu[maxn<<2] ;	//data储存区间最小值 
int bushu[maxn<<2] ;
int ans ;
int shendus[maxn] ;
int n ;

int bixiao(int a,int b){return a<b ? a : b ;}		//返回较小值,即 min(a,b)
int bida(int a,int b){return a>b ? a : b ;}			//返回较大值,即 max(a,b) 

void zhongshu(int zuo,int you,int i)
{
	if( zuo==you )
	{
		shu[i] =(dian) { zuo,you,shendus[zuo] } ;
		return ;
	}
	int mid = ( zuo+you ) / 2 ;
	zhongshu(zuo,mid,i*2) ;
	zhongshu(mid+1,you,i*2+1) ;					//区间最小值 
	shu[i] =(dian){ zuo , you , bixiao( shu[i*2].data , shu[i*2+1].data ) } ;
	return ;
}

void qiujie(int zuo,int you,int i)
{
	if( zuo==you )
		return ;
	qiujie( zuo , (zuo+you)/2 , i*2 ) ;
	qiujie( (zuo+you)/2 +1 , you , i*2+1 ) ;
	
	int zuoer=shu[i*2].data , youer=shu[i*2+1].data ;
	int jiaoda = bida( zuoer , youer ) ;
	ans += jiaoda-shu[i].data ;
	return ;
}

int main()
{
	freopen("road.in","r",stdin) ;;
	freopen("road.out","w",stdout) ;
	scanf( "%d" , &n ) ;
	for(int i=1 ; i<=n ; i ++ )
		scanf( "%d" , &shendus[i] ) ;
	zhongshu(1,n,1) ;	
//	for(int i=1 ; shu[i].l ; i++)
//		printf("( %d , %d ) = %d \n",shu[i].l,shu[i].r,shu[i].data) ;
	ans = shu[1].data ;
	qiujie(1,n,1) ;
	printf( "%d" , ans) ;
	return 0 ;
}                                              
