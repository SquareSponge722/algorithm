#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 110, M = 25010;

int a[N];
bool vis[M];

inline void solve() {
    int large = 0, n;
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        large = std::max(large, a[i]);
    }
    std::sort(a + 1, a + n + 1);

    if(n == 2) {
        if((a[2] % a[1]) == 0) {
            puts("1");
        }
        else {
            puts("2");
        }
        return;
    }

    vis[0] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[a[i]]) {
            continue;
        }
        ans++;
        for(int j = a[i]; j <= large; j++) {
            vis[j] |= vis[j - a[i]];
        }
    }
    printf("%d\n", ans);
    return;
}

int main() {

    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
