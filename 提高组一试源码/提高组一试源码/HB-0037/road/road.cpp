#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int N, a[MAXN];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>N;
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	int ans = 0;
	for(int i = 1; i <= N; i++)
		if(a[i] > a[i - 1]) ans += a[i] - a[i - 1];
	cout<<ans<<endl;
	return 0;
}
