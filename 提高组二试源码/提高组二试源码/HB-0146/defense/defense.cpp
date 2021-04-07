#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x * f;
}
const int N = 100010;
const int M = 100010;
struct node{
    int nxt, to, from;
}edge[M << 1], edge2[M << 1], E[M];
int head[N], num = 1, head2[N], num2 = 1;
void build(int from, int to){
    edge[++num].nxt = head[from];
    edge[num].to = to;
    head[from] = num;
}
int must[N], no[N];
char t, op;
struct node2{
    int val, id;
}P[N];
bool cmp(node2 a, node2 b){
    return a.val < b.val;
}
int ans = 0, vis[N], val[N];
int n, m;
void work(){
    for(int i=1; i<=n; i++){
        if(vis[P[i].id] || no[P[i].id]) continue;
        ans += P[i].val;
        vis[P[i].id] = 1;
        for(int j=head[P[i].id]; j; j=edge[j].nxt){
            int v = edge[j].to;
            vis[v] = 1;
        }
    }
    cout << ans <<endl;
    return;
}
char a[10];
int main(){
    freopen("defense.in", "r", stdin);
    freopen("defense.out", "w", stdout);
    n = read(), m = read(); cin >> a + 1;
    for(int i=1; i<=n; i++){
        P[i].id = i; P[i].val = read(); val[i] = P[i].val;
    }
    sort(P+1, P+n+1, cmp);
    for(int i=1; i<=n-1; i++){
        int u = read(), v = read(); build(u, v); build(v, u);
    }
    for(int k=1; k<=m; k++){
        memset(vis, 0, sizeof(vis));
        memset(must, 0, sizeof(must));
        memset(no, 0, sizeof(no));
        ans = 0;
        int x = read(), opx = read();
        int y = read(), opy = read();
        if(opx == 1) {
            must[x] = 1;
            vis[x] = 1;
            for(int i=head[x]; i; i=edge[i].nxt){
                vis[edge[i].to] = 1;
            }
            ans += val[x];
        }
        else no[x] = 1;
        if(opy == 1) {
            must[y] = 1;
            vis[y] = 1;
            for(int i=head[y]; i; i=edge[i].nxt){
                vis[edge[i].to] = 1;
            }
            ans += val[y];
        }
        else no[y] = 1;
        work();
    }
    return 0;
}
