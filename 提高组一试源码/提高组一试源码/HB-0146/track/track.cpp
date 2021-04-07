#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x * f;
}
const int M = 100010;
const int N = 100010;
struct node{
    int nxt, to, dis;
}edge[M << 1];
int head[N], num = 1;
void build(int from, int to, int dis){
    edge[++num].nxt = head[from];
    edge[num].to = to;
    edge[num].dis = dis;
    head[from] = num;
}
int d[N], root, now;
namespace P1{
    void dfs(int u, int fa){
        for(int i=head[u]; i; i=edge[i].nxt){
            int v = edge[i].to;
            if(v == fa) continue;
            d[v] = d[u] + edge[i].dis;
            if(d[v] > now){
                now = d[v], root = v;
            }
            dfs(v, u);
        }
    }
    void work(){
        dfs(1, 0);
        memset(d, 0, sizeof(d));
        int NR = root; now = 0;
        dfs(root, 0);
        cout << now;
    }
}
int n, m, l = 0x3f3f3f3f, r;
int tmp[N], cnt, flag;
namespace P2{
    bool check(int mid){
        int now = 0, sum = 0, js = 0;
        while(now <= n){
            if(sum >= mid){
                sum = 0; js ++;
            }
            sum += tmp[now];
            now ++;
        }
        if(js >= m) return 1;
        return 0;
    }
    void work(){
        int Ans = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if( check(mid) ){
                Ans = mid; l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << Ans;
    }
}
namespace P3{
    int vis[N], use[M << 1], ans = 0;
    void dfs(int u, int now, int mid){
        if(now >= mid){
            ans ++;
            if(ans >= m) return;
            for(int i=1; i<=n; i++){
                dfs(i, 0, mid);
            }
            ans --;
        }
        else{
            for(int i=head[u]; i; i=edge[i].nxt){
                int v = edge[i].to;
                if(use[i]) continue;
                use[i] = use[i^1] = 1;
                dfs(v, now + edge[i].dis, mid);
                use[i] = use[i^1] = 0;
            }
        }
    }
    bool check(int mid){
        for(int i=1; i<=n; i++){
            ans = 0;
            dfs(i, 0, mid);
            if(ans >= m) return 1;
        }
        return 0;
    }
    void work(){
        int Ans = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if( check(mid) ){
                Ans = mid; l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << Ans;
    }
}
int main(){
    freopen("track.in", "r", stdin);
    freopen("track.out", "w", stdout);
    flag = 1;
    n = read(); m = read();
    for(int i=1; i<=n-1; i++){
        int u = read(), v = read(), d = read();
        if(v != u + 1) flag = 0;
        l = min(d, l); r += d;
        build(u, v, d); build(v, u, d);
        tmp[++cnt] = d;
    }
    if(flag){
        P2::work();
        return 0;
    }
    if(m == 1){
        P1::work();
        return 0;
    }
    P3::work();
    return 0;
}
/*
5 2
1 2 3
2 3 5
3 4 1
4 5 7

9 3
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4

7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
