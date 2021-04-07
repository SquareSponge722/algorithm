#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long LL;
const int N=1000010;
const LL M=(LL)((LL)1e9+7);
using namespace std;
int n,m;
LL pow_m(LL x,LL p){
	LL res=1;
	while(p){
		if(p&1){res=res*x%M;}
		x=x*x%M;p=p>>1;
	}
	return res%M;
}
LL f[10][N][2],na,nb,s[10][N];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){printf("%lld",pow_m((LL)2,(LL)m));}
	else if(n==2){
		printf("%lld",(LL)pow_m((LL)3,(m-1))*4%M);		
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i==1&&j==1){f[i][j][0]=f[i][j][1]=1;s[1][1]=2;continue;}
				if(j==1){na=1;}else na=s[i][j-1];
				if(i==1||j==m){nb=1;}else nb=f[i-1][j+1][0];
				f[i][j][0]=na*nb%M;
				if(i==1||j==m){nb=1;}else nb=s[i-1][j+1];
				f[i][j][1]=na*nb%M;
				s[i][j]=(f[i][j][0]+f[i][j][1])%M;
			}
		}
		printf("%lld",s[n][m]%M);
		
	}
	return 0;
}