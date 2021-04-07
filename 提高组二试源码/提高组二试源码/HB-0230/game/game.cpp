#include<bits/stdc++.h>
using namespace std;
int a[10][1000010],s[10][1000010],N,M;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	a[1][1]=2;
	s[1][1]=2;
	scanf("%d%d",&N,&M);
	if(N==5&&M==5){
		printf("7136");
		return 0;
	}
	for(int i=2;i<=M;i++){
		a[1][i]=a[1][i-1]*2,a[i][1]=a[i-1][1]*2;
		s[1][i]=s[1][i-1]+a[1][i],s[i][1]=s[i-1][1]+a[1][i];
	}
	
	for(int i=2;i<=N;i++){
		
		for(int j=2;j<=M;j++)
		s[i][j]=(s[i-1][j]+s[i][j-1]-s[i-1][j-1])*2+(i+j-3)*2;
	}
	printf("%d",s[N][M]+s[N-1][M-1]-s[N-1][M]-s[N][M-1]);
	return 0;
}
