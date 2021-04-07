#include <cstdio>
#include <algorithm>

const int N = 50010, INF = 0x3f3f3f3f;

struct Edge {
    int nex, v, len;
}edge[N << 1]; int top = 0;

int e[N], n, m, deg[N], tot = 0, small = INF;

inline void add(int x, int y, int z) {
    top++;
    edge[top].v = y;
    edge[top].len = z;
    edge[top].nex = e[x];
    e[x] = top;
    return;
}

namespace T1 {
    int f[N], ans = 0;

    void DFS(int x, int fa) {
        f[x] = 0;
        int a = 0;
        for(int i = e[x]; i; i = edge[i].nex) {
            int y = edge[i].v;
            if(y == fa) {
                continue;
            }
            DFS(y, x);
            if(f[y] + edge[i].len > f[x]) {
                a = f[x];
                f[x] = f[y] + edge[i].len;
            }
            else if(f[y] + edge[i].len > a) {
                a = f[y] + edge[i].len;
            }
        }
        ans = std::max(ans, f[x] + a);
        return;
    }

    inline void solve() {

        DFS(1, 0);
        printf("%d", ans);

        return;
    }
}

namespace T2 {

    int lm, f[N], ans;

    void DFS(int x, int fa) {
        f[x] = 0;
        int a = 0;
        for(int i = e[x]; i; i = edge[i].nex) {
            int y = edge[i].v;
            if(y == fa) {
                continue;
            }
            DFS(y, x);
            if(f[y] + edge[i].len > f[x]) {
                a = f[x];
                f[x] = f[y] + edge[i].len;
            }
            else if(f[y] + edge[i].len > a) {
                a = f[y] + edge[i].len;
            }
        }
        if(f[x] + a >= lm) {
            ans++;
            f[x] = 0;
        }
        return;
    }

    inline int cal(int k) {
        ans = 0;
        lm = k;
        DFS(1, 0);
        return ans;
    }

    inline void solve() {
        int l = small, r = tot / m;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(cal(mid) >= m) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        printf("%d", r);
        return;
    }
}

namespace T3 {
    int p[N], t;
    inline int cal(int k) {
        int ans = 0;
        int l = 1, r = t;
        while(r && p[r] >= k) {
            ans++;
            r--;
        }
        while(l < r) {
            if(p[l] + p[r] >= k) {
                ans++;
                r--;
                l++;
            }
            else {
                l++;
            }
        }
        return ans;
    }
    inline void solve() {
        for(int i = 2; i <= top; i += 2) {
            p[++t] = edge[i].len;
        }
        std::sort(p + 1, p + t + 1);
        int l = small, r = tot / m;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(cal(mid) >= m) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        printf("%d", r);
        return;
    }
}

int main() {

    freopen("track.in", "r", stdin);
    freopen("track.out", "w", stdout);

    int large = 0, a1 = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1, x, y, z; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
        tot += z;
        deg[x]++;
        deg[y]++;
        large = std::max(large, std::max(deg[x], deg[y]));
        small = std::min(small, z);
        a1 = std::max(a1, x);
    }

    if(m == 1) {
        T1::solve();
        return 0;
    }

    if(large <= 3) {
        T2::solve();
        return 0;
    }

    if(a1 == 1) {
        T3::solve();
        return 0;
    }

    return 0;
}
