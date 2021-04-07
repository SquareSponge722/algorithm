#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int gcd(int a,int b) {
	if(b == 0) return a;
	return gcd(a,a % b);
}
bool prime(int x) {
	for(int i = 2;i <= sqrt(x);i++) {
		if(x % i == 0) return false;
	}
	return true;
}
int t,n,a[110],cnt = 0;
//int maxt = 0,mint = 0x3f3f3f3f;
int main() {
	//freopen("money.in","r",stdin);
	//freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		int front = 0,rear = 1;
		scanf("%d",&n);
		if(n == 2) {
			int x,y;
			scanf("%d%d",&x,&y);
			if(y % x == 0 || x % y == 0) {
				printf("1\n");
				continue;
			}
			else {
				printf("2\n");
				continue;
			}
		}
		for(int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
		}
		for(int i = 1;i <= n;i++) {
			if(prime(a[i])) cnt++;
		}
		printf("%d\n",cnt);
		cnt = 0;
	}
	return 0;
}
