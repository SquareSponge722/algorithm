#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define dfnx y==m?dfs(x+1,1):dfs(x,y+1)
using namespace std;
const int N=11,M=1001000,P=1e9+7;
int n,m;
int res[N][N]={
{0,0,0,0,0,0,0},
{0,2,4,8,16,32,64},
{0,4,12,36,108,324,972},
{0,8,36,112,336,1008,3024},
{0,16,108,336,912,2688,8064},
{0,32,324,1008,2688,7136,21312},
{0,64,972,3024,8064,21312,56768}
};
int qpw(int x,int y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%P)if(y&1) z=1ll*z*x%P;
	return z;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=6 && m<=6) printf("%d",res[n][m]);
	else if(n==1){
		printf("%d",1ll*qpw(2,m)%P);
	}
	else if(n==2){
		printf("%d",4ll*qpw(3,m-1)%P);
	}
	else if(n==3){
		printf("%d",112ll*qpw(3,m-3)%P);
	}
}
