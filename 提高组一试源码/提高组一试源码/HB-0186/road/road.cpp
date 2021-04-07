#include <cstdio>

typedef long long LL;
const int N = 100010;

int d[N], p[N], top = 0;

int main() {

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }

    LL ans = 0;
    for(int i = 1; i <= n + 1; i++) {
        if(top && d[p[top]] > d[i]) {
            ans += d[p[top]] - d[i];
            top--;
        }
        while(top && d[p[top]] >= d[i]) {
            top--;
        }
        p[++top] = i;
    }

    printf("%lld", ans);
    return 0;
}
