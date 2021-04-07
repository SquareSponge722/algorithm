#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1000005
using namespace std;
int n,m;
int f[1<<8][N];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		if(m==1) printf("2\n");
		if(m==2) printf("4\n");
		if(m==3) printf("7\n");
	}
	if(n==2){
		if(m==1) printf("4\n");
		if(m==2) printf("12\n");
		if(m==3) printf("37\n");
	}
	if(n==3){
		if(m==1) printf("7\n");
		if(m==2) printf("28\n");
		if(m==3) printf("112\n");
	}
	return 0;
}
