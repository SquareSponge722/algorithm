#include<cstdio>
#include<algorithm>		//sort函数默认从小到大 
#include<vector>
#include<cstring>
#define maxn  110
using namespace std ;

int n , ans=0 ;
vector<int>dongtai ;
int huobi[maxn] ;
int lianbiao[maxn][3] ;
int huobia , huobib ;
int zuida ;

bool keyi(int qian)
{
	int l=dongtai.size() ;
	for(int i=0 ; i<l ; i++)
	{
		for(int j=i+1 ; j<l ; j++)
		{
			while(qian>0)
			{
				if( qian%dongtai[i] == 0 )
					return true ;
				qian -= dongtai[j] ;
			}
			
		}
	}
	return false ;
}

int main()
{
	freopen("money.in","r",stdin) ;
	freopen("money.out","w",stdout) ;
	int ndata ;
	scanf( "%d" , &ndata ) ;
	for(int adfjklasjfkla=0 ; adfjklasjfkla<ndata ; adfjklasjfkla++)
	{
		scanf( "%d" , &n ) ;
		for(int i=1 ; i<=n ; i++ )
		{
			scanf( "%d" , &huobi[i] ) ;
		}
		
		sort( huobi+1 , huobi+1+n ) ;
		
		if( huobi[1]==1 )
		{
			printf("1\n") ;
			continue ;
		}
		//将数组huobi[]存入链表中 
		for(int i=1 ; i<=n ; i++ )
		{
			lianbiao[i][0] = huobi[i] ;
			lianbiao[i][1] = i+1 ;
			lianbiao[i][2] = i-1 ;
		}
		//链表末尾
		lianbiao[n][1] = 0 ;
		
		int k=1 ; dongtai.push_back( lianbiao[1][1] ) ;
		while(k)
		{
			int l=dongtai.size() ;
			for(int i=0 ; i<l ; i++)
			{
				if( lianbiao[k][0] % dongtai[i] == 0)
				{
					lianbiao[ lianbiao[k][2] ][1] = lianbiao[k][1] ;
					lianbiao[ lianbiao[k][1] ][2] = lianbiao[k][2] ;
				}
				else
					dongtai.push_back( lianbiao[k][0] ) ;
			}
			k = lianbiao[k][1] ;
		}
		
		do
			dongtai.pop_back() ;
		while( !dongtai.empty() ) ;
		
		huobia=lianbiao[1][0] ; k = lianbiao[1][1] ;
		
		dongtai.push_back( lianbiao[1][0] ) ; dongtai.push_back( lianbiao[k][0] ) ; ans=2 ;
		
		zuida = lianbiao[1][0]*lianbiao[k][0] - lianbiao[k][0] - lianbiao[1][0] ; k=lianbiao[k][1] ; 
		
		while(k)
		{
			if( lianbiao[k][0] > zuida )
				break ;
			if( !keyi( lianbiao[k][0] ) )
			{
				dongtai.push_back( lianbiao[k][0] ) ;
				ans++ ;
			}
			k=lianbiao[k][1] ;
		}
		
		printf( "%d\n" , ans ) ;
		
		memset(huobi,0,sizeof(huobi)) ;
		memset(lianbiao,0,sizeof(lianbiao)) ;
	}
	return 0 ;
}
