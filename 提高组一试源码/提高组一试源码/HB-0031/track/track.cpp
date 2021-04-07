#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream fin("track.in");
std::ofstream fout("track.out");

struct Point {
    int head, res;
    bool vis;
} pt[50005];
struct Path {
    int to, cost, next;
    Path(int t = 0, int c = 0, int n = 0) :
        to(t), cost(c), next(n) {}
} ph[100005];

int n, m, ptr, val;

void setPath(int u, int v, int c) {
    ph[++ptr] = Path(v, c, pt[u].head), pt[u].head = ptr;
    ph[++ptr] = Path(u, c, pt[v].head), pt[v].head = ptr;
}

int DFS(int p) {
    int temp = 0;
    pt[p].vis = true;
    std::vector<int> vec;
    std::vector<bool> vis;
    for (int i = pt[p].head; i; i = ph[i].next) {
        int x = ph[i].to;
        if (pt[x].vis) continue;
        temp += DFS(x);
        vec.push_back(pt[x].res + ph[i].cost);
        vis.push_back(false);
    }
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i) {
        if (vis[i]) continue;
        std::vector<int>::iterator it =
            std::lower_bound(vec.begin(), vec.end(), val - vec[i]);
        if (it - vec.begin() < i) break;
        else if (it == vec.begin() + i)
            ++it;
        while (it != vec.end() && vis[it - vec.begin()])
            ++it;
        if (it == vec.end()) continue;
        vis[it - vec.begin()] = vis[i] = true;
        temp += 1;
    }
    int ans = 0;
    for (int i = 0; i < vec.size(); ++i)
        if (!vis[i])
            ans = std::max(ans, vec[i]);
    pt[p].res = ans;
    return temp;
}

bool check(int v) {
    val = v;
    for (int i = 1; i <= n; ++i)
        pt[i].res = 0, pt[i].vis = false;
    int val = DFS(1);
    return val >= m;
}

int main() {
    int l = 2147483647, r = 0;
    fin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int u, v, c;
        fin >> u >> v >> c;
        setPath(u, v, c);
        l = std::min(l, c);
        r += c;
    }
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    fout << l << std::endl;
    return 0;
}
