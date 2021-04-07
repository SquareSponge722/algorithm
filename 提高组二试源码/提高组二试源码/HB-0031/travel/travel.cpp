#include <queue>
#include <fstream>
#include <algorithm>

std::ifstream fin("travel.in");
std::ofstream fout("travel.out");

bool vis[5005];
bool in_circle[5005];
bool graph[5005][5005];
int n, m;

bool findCircle(int p, int f) {
    if (vis[p]) {
        in_circle[p] = true;
        return true;
    }
    vis[p] = true;
    bool flag = false;
    for (int i = 1; i <= n; ++i)
        if (i != f && graph[p][i]) {
            flag = findCircle(i, p);
            if (flag)
                break;
    }
    if (in_circle[p])
        return in_circle[p] = false;
    else if (flag)
        return in_circle[p] = true;
    else
        return false;
}

void printNoCircle(int);

void printCircle(int p, int last) {
    if (vis[p])
        return;
    fout << p << ' ';
    vis[p] = true;
    for (int i = 1; i <= n; ++i) {
        if (vis[i] || !graph[p][i])
            continue;
        if (in_circle[i]) {
            if (i <= last)
                printCircle(i, last);
            else
                return;
        } else {
            printNoCircle(i);
        }
    }
}

void printNoCircle(int p) {
    if (vis[p])
        return;
    vis[p] = true;
    fout << p << ' ';
    int v1 = 0, v2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (!graph[p][i])
            continue;
        if (in_circle[i]) {
            if (v1 == 0)
                v1 = i;
            else
                v2 = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!graph[p][i])
            continue;
        if (i == v1)
            printCircle(v1, v2);
        else if (i == v2)
            printCircle(v2, 2147483647);
        else
            printNoCircle(i);
    }
}

int main() {
    fin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        fin >> u >> v;
        graph[u][v] = graph[v][u] = true;
    }
    if (n == m)
        findCircle(1, 0);
    for (int i = 1; i <= n; ++i)
        vis[i] = false;
    printNoCircle(1);
    fout << std::endl;
    return 0;
}
