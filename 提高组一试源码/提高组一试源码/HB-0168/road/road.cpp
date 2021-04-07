#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,last = 0;
	long long ans = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) {
		int t;scanf("%d",&t);
		if(last < t) ans += t - last;
		last = t;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
