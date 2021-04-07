#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n,last = 0;
long long ans = 0;
int main() {
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) {
		int d;
		scanf("%d",&d);
		if(d > last) ans += d - last;
		last = d;
	}
	printf("%lld\n",ans);
	return 0;
}
