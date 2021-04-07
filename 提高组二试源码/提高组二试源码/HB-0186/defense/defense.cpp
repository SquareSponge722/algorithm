#include <cstdio>
#include <algorithm>

typedef long long LL;
const int N = 100010;
const LL INF = (1ll << 58);

struct Edge {
    int nex, v;
    bool use;
}edge[N << 1]; int top = 1;

int e[N], n, val[N], p[N], t;
bool vis[N];
char str[10];
LL f[N][2], fx[N][2];

inline void add(int x, int y) {
    top++;
    edge[top].v = y;
    edge[top].nex = e[x];
    e[x] = top;
    return;
}

bool DFS_f(int x, int fa, int T) {
    if(x == T) {
        p[++t] = x;
        return 1;
    }
    for(int i = e[x]; i; i = edge[i].nex) {
        int y = edge[i].v;
        if(y == fa) {
            continue;
        }
        if(DFS_f(y, x, T)) {
            vis[x] = 1;
            p[++t] = x;
            edge[i].use = edge[i ^ 1].use = 1;
            return 1;
        }
    }
    return 0;
}

void DFS(int x, int fa) {
    f[x][0] = f[x][1] = 0;
    for(int i = e[x]; i; i = edge[i].nex) {
        int y = edge[i].v;
        if(y == fa || edge[i].use) {
            continue;
        }
        DFS(y, x);
        f[x][0] += f[y][1];
        f[x][1] += std::min(f[y][0], f[y][1]);
    }
    f[x][1] += val[x];
    return;
}

int main() {

    freopen("defense.in", "r", stdin);
    freopen("defense.out", "w", stdout);

    int m;
    scanf("%d%d", &n, &m);
    scanf("%s", str);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }
    for(int i = 1, x, y; i < n; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }

    int a, b, ca, cb;
    LL ans;
    while(m--) {
        scanf("%d%d%d%d", &a, &ca, &b, &cb);
        for(int i = 2; i <= top; i++) {
            edge[i].use = 0;
        }
        for(int i = 1; i <= n; i++) {
            vis[i] = 0;
        }
        t = 0;
        DFS_f(a, 0, b);
        vis[a] = vis[b] = 1;
        for(int i = 1; i <= t; i++) {
            DFS(p[i], 0);
        }
        if(cb) {
            fx[1][0] = INF;
            fx[1][1] = f[b][1];
        }
        else {
            fx[1][1] = INF;
            fx[1][0] = f[b][0];
        }
        for(int i = 2; i <= t; i++) {
            fx[i][0] = fx[i - 1][1] + f[p[i]][0];
            fx[i][1] = std::min(fx[i - 1][1], fx[i - 1][0]) + f[p[i]][1];
        }
        if(ca) {
            ans = fx[t][1];
        }
        else {
            ans = fx[t][0];
        }
        if(ans >= INF) {
            ans = -1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
