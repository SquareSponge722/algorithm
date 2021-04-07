#include <cstdio>
#include <algorithm>

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, prev = 0, cur, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &cur),
        ans += std::max(0, cur - prev),
        prev = cur;
    printf("%d\n", ans);
    return 0;
}
