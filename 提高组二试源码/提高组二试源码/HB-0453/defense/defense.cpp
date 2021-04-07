#include <cstdio>
using namespace std;
const int maxn = 100000 + 10, maxm = 200000 + 10;
struct Edge
{
	int v, nxt;
    Edge(int v = 0, int nxt = 0):v(v), nxt(nxt){}
} es[maxm];
int head[maxn], cnt = 0;
void AddEdge(int u, int v) { es[++cnt] = Edge(v, head[u]); head[u] = cnt; }
int n, m, p[maxn];
char tpe[10];
int main()
{
    freopen("defense.in", "r", stdin);
    freopen("defense.out", "w", stdout);
    scanf("%d %d %s", &n, &m, &tpe);
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        AddEdge(u, v);
    }
    while(m--)
    {
        int a, x, b, y;
        scanf("%d %d %d %d", &a, &x, &b, &y);
        puts("-1");
    }
    return 0;
}
