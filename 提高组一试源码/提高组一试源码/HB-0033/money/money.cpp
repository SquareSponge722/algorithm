#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int hb[6];
int get_rnd(int l,int r)
{
	int a=rand();
	a=a<<16|a;
	return l+a%(r-l+1);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	srand(time(0));
	int T;
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		for(int i=0;i<x;++i)
			scanf("%d",&hb[i]);
		printf("%d\n",get_rnd(x/2,x+3));	
	}
	return 0;
}
