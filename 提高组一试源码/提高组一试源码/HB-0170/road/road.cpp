#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

inline int read(){
	int summ = 0;
	char e = getchar();
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e)){
		summ = summ * 10 + e - '0';
		e = getchar();
	}
	return summ;
}

int n,h[100005];
int c[100005];
long long ans = 0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	for(ri i = 1;i <= n;++ i)
		h[i] = read(),c[i] = h[i] - h[i-1],ans = max(ans,ans + c[i]);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
