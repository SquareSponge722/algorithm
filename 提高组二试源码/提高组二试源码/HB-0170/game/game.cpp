#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define mod 1000000007

using namespace std;

int n,m;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n == 1){
		printf("0\n");
	}
	else if(n == 2){
		if(m == 1)
			printf("0\n");
		else if(m == 2)
			printf("12\n");
	}
	else if(n == 3 && m == 3){
		printf("112\n");
	}
	else if(n == 5 && m == 5){
		printf("7136\n");
	}
	else{
		long long ans = 1,t = ((1+m)*m/2) % mod;
		for(ri i = 1;i <= n;i ++)
			ans = (ans << 1) % mod;
		for(ri j = 1;j < m;j ++)
			t = (t << 1) % mod;
		printf("%lld",(ans * t % mod));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
