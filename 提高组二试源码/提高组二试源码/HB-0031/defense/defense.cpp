#include <string>
#include <fstream>
#include <algorithm>

std::ifstream fin("defense.in");
std::ofstream fout("defense.out");

typedef long long LL;
const LL inf = 0X3F3F3F3F3F3F3F3F;

struct Point {
    int head, val, state;
    LL f1, f2, g;
    Point() : head(0), val(0), state(-1), f1(0), f2(0), g(0) {}
} pt[100005];
struct Path {
    int to, next;
    Path(int t = 0, int n = 0) : to(t), next(n) {}
} ph[200005];

int n, m, ptr;

void setPath(int u, int v) {
    ph[++ptr] = Path(v, pt[u].head), pt[u].head = ptr;
    ph[++ptr] = Path(u, pt[v].head), pt[v].head = ptr;
}

void DP(int p, int f) {
    pt[p].f1 = pt[p].val;
    pt[p].f2 = pt[p].val;
    for (int i = pt[p].head; i; i = ph[i].next) {
        int x = ph[i].to;
        if (x == f) continue;
        DP(x, p);
        pt[p].f1 += std::min(std::min(pt[x].f1, pt[x].f2), pt[x].g);
        pt[p].f2 += pt[x].f1;
        pt[p].g += pt[x].f1;
    }
    if (pt[p].state == 1)
        pt[p].g = inf;
    else if (pt[p].state == 0)
        pt[p].f1 = pt[p].f2 = inf;
}

int main() {
    std::string s;
    fin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
        fin >> pt[i].val;
    for (int i = 2; i <= n; ++i) {
        int u, v;
        fin >> u >> v;
        setPath(u, v);
    }
    while (m--) {
        int a, b, x, y;
        fin >> a >> x >> b >> y;
        pt[a].state = x, pt[b].state = y;
        DP(1, 0);
        LL ans = std::min(pt[1].g, std::min(pt[1].f1, pt[1].f2));
        if (ans >= inf)
            fout << -1 << std::endl;
        else
            fout << ans << std::endl;
        for (int i = 1; i <= n; ++i)
            pt[i].f1 = pt[i].f2 = pt[i].g = 0;
        pt[a].state = pt[b].state = -1;
    }
    return 0;
}
