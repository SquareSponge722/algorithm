#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x * f;
}
const int N = 5050;
const int M = 5050;
struct node{
    int nxt, to, from;
}edge[M << 1], edge2[M << 1], E[M];
int head[N], num = 1, head2[N], num2 = 1;
void build(int from, int to){
    edge[++num].nxt = head[from];
    edge[num].to = to;
    head[from] = num;
}
namespace P1{
    void dfs(int u, int fa){
        cout << u << " ";
        int tmp[N], cnt = 0;
        for(int i=head[u]; i; i=edge[i].nxt){
            int v = edge[i].to;
            if(v == fa) continue;
            tmp[++cnt] = v;
        }
        sort(tmp+1, tmp+cnt+1);
        for(int i=1; i<=cnt; i++) dfs(tmp[i], u);
    }
    void work(){
        dfs(1, 0);
    }
}
int n, m;
int id[N][N];
namespace P2{
    void build2(int from, int to){
        edge2[++num2].nxt = head2[from];
        edge2[num2].to = to;
        head2[from] = num2;
    }
    int low[N], dfn[N], rev[N], cnt, color, bridge[N];
    void tarjan(int u, int in_edge){
        low[u] = dfn[u] = ++cnt; rev[cnt] = u;
        int tmp = in_edge ^ 1;
        for(int i=head[u]; i; i=edge[i].nxt){
            if(i == tmp) continue;
            int v = edge[i].to;
            if(!dfn[v]) tarjan(v, i), low[u] = min(low[u], low[v]);
            else low[u] = min(low[u], dfn[v]);
            if(low[v] > dfn[u]){
                bridge[i] = bridge[i ^ 1] = 1;
            }
        }
    }
    int col[N], vis[N], Min[N];
    void dfs(int u, int nowcol){
        vis[u] = 1, col[u] = nowcol; id[nowcol][ ++id[nowcol][0] ] = u;
        //Min[nowcol] = min(Min[nowcol], u);
        for(int i=head[u]; i; i=edge[i].nxt){
            int v = edge[i].to;
            if(bridge[i]) continue;
            if(vis[v]) continue;
            dfs(v, nowcol);
        }
    }
    void solve(int u, int fa){
        if(id[u][0] > 1){
            bool flag = 0;
            cout << id[u][1] << " ";
            int l = 1;
            while(l <= id[u][0] && id[u][l+1] < id[u][id[u][0]]) l ++;
            if(l == 1){
                flag = 1;
                int r = id[u][0];
                while(r > 2 && id[u][r-1] < id[u][2]) r --;
                for(int i=id[u][0]; i>=r; i--) cout << id[u][i] << " ";
                for(int i=2; i<r; i++) cout << id[u][i] << " ";
            }
            else{
                for(int i=2; i<=l; i++) cout << id[u][i] << " ";
                for(int i=id[u][0]; i>l; i--) cout << id[u][i] << " ";
            }
        }
        else for(int i=1; i<=id[u][0]; i++) cout << id[u][i] << " ";
        int tmp[N], cnt = 0;
        for(int i=head2[u]; i; i=edge2[i].nxt){
            int v = edge2[i].to;
            if(v == fa) continue;
            tmp[++cnt] = v;
        }
        sort(tmp+1, tmp+cnt+1);
        for(int i=1; i<=cnt; i++) solve(tmp[i], u);
    }
    void work(){
        for(int i=1; i<=n; i++) if(!dfn[i]) tarjan(i, 0);
        for(int i=1; i<=n; i++) if(!vis[rev[i]]) dfs(rev[i], ++color);
        //for(int i=1; i<=n; i++) cout << col[i] << " ";
        //for(int i=1; i<=id[2][0]; i++) cout << id[2][i] << " ";
        for(int i=1; i<=m; i++){
            int u = E[i].from, v = E[i].to;
            if(col[u] == col[v]) continue;
            build2(col[u], col[v]); build2(col[v], col[u]);
        }
        solve(col[1], 0);
    }
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    n = read(), m = read();
    for(int i=1; i<=m; i++){
        E[i].from = read(), E[i].to = read(); build(E[i].from, E[i].to); build(E[i].to, E[i].from);
    }
    if(m == n - 1){
        P1::work();
        return 0;
    }
    P2::work();
    return 0;
}
