#include <cstdio>
#include <cstdlib>
using namespace std;
const int MOD=1000000007;
long long fa(int r,int c){
	if(r==2)
		return c;
	if(c==2)
		return r;
	return fa(r-1,c)+fa(r,c-1);
}
long long fblq(int x){
	if(x==1)
		return 1;
	if(x==2)
		return 3;
	return fblq(x-1)+x;
}
long long num(int c,int num){
	long long re=0*1ll;
	if(num==2)
		return fblq(1<<c);
	//else
		
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int m,n;
	scanf("%d %d",&n,&m);
	printf("%d",(num(n+m-3,fa(n,m))*4)%MOD);
}
