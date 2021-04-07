#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

const int N = 5010;

int p[N], top, n, m, fr[N], stk[N], t, val;
std::vector<int> G[N];
bool vis[N], inc, otc;

void DFS_1(int x, int fa) {
    p[++top] = x;
    for(int i = 0; i < G[x].size(); i++) {
        int y = G[x][i];
        if(y == fa) {
            continue;
        }
        DFS_1(y, x);
    }
    return;
}

bool DFS_f(int x, int fa) {
    vis[x] = 1;
    stk[++t] = x;
    for(int i = 0; i < G[x].size(); i++) {
        int y = G[x][i];
        if(y == fa) {
            continue;
        }
        if(!vis[y]) {
            if(DFS_f(y, x)) {
                return 1;
            }
            continue;
        }
        // find cir
        int z;
        do {
            z = stk[t];
            t--;
            fr[z] = z;
        } while(z != y);
        return 1;
    }
    t--;
    vis[x] = 0;
    return 0;
}

void DFS_2(int x, int fa, int from) {
    fr[x] = from;
    for(int i = 0; i < G[x].size(); i++) {
        int y = G[x][i];
        if(y == fa || fr[y] == y) {
            continue;
        }
        DFS_2(y, x, from);
    }
    return;
}

void solve(int x) {
    p[++top] = x;
    vis[x] = 1;
    if(!inc && fr[x] == x) { // first in circle
        inc = 1;
        bool fd = 0;
        for(int i = 0; i < G[x].size(); i++) {
            int y = G[x][i];
            if(fr[y] == y) {
                if(!fd) {
                    fd = 1;
                }
                else {
                    val = y;
                    break;
                }
            }
        }
        for(int i = 0; i < G[x].size(); i++) {
            int y = G[x][i];
            if(vis[y]) {
                continue;
            }
            solve(y);
            if(fr[y] == y) {
                otc = 1;
            }
        }
        return;
    }
    bool f = (fr[x] == x);
    for(int i = 0; i < G[x].size(); i++) {
        int y = G[x][i];
        if(vis[y]) {
            continue;
        }
        if(f && inc && (i == G[x].size() - 1) && (fr[y] == y) && (y > val) && (!otc)) {
            continue;
        }
        solve(y);
    }
    return;
}

int main() {

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        std::sort(G[i].begin(), G[i].end());
    }

    if(m == n - 1) {
        DFS_1(1, 0);
        for(int i = 1; i <= n; i++) {
            printf("%d ", p[i]);
        }
        return 0;
    }

    DFS_f(1, 0);
    for(int i = 1; i <= n; i++) {
        if(fr[i] == i) {
            DFS_2(i, 0, i);
        }
    }

    memset(vis, 0, sizeof(vis));
    solve(1);

    for(int i = 1; i <= n; i++) {
        printf("%d ", p[i]);
    }
    return 0;
}
