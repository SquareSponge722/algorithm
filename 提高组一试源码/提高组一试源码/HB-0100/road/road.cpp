#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int a[100010], n, ans;

void waru(int* haji, int* matu, int saisho) {
	if (haji == matu) return;
	int* ichi = min_element(haji, matu);
	ans += (*ichi - saisho);
	waru(haji, ichi, *ichi);
	waru(ichi + 1, matu, *ichi);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	waru(a, a + n, 0);
	printf("%d\n", ans);
	return 0;
}
