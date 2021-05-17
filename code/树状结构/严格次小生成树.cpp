#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
const int K = 20;
const long long INF = 0x7f7f7f7f7f7f7f7f;

struct edge{
    int u,v;
    long long w;
    bool operator < (const edge & ot) const{
        return w < ot.w;
    }
}ed[N * 6];
bool isIn[N * 6];

struct node{
    long long w;
    int to,next;
    node() {}
    node(int to,long long w,int next) : to(to),w(w),next(next) {}
}nod[N * 6];
int tot;
int head[N * 6];

int n,m;
long long max1,max2;

int fa[N];

int dep[N],lca[N][K];
long long fax[N][K],sax[N][K];

int fin(int);
void dfs(int,int,long long);
void bfs(int);
void Lca(int,int);

inline void addEdge(int u,int v,long long w){
    nod[++tot] = node(v,w,head[u]);
    head[u] = tot;

    nod[++tot] = node(u,w,head[v]);
    head[v] = tot;
}
inline void update(long long k){
    if(k > max1) max2 = max1,max1 = k;
    else if(k != max1) max2 = max(max2,k);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 0;i < m;i++)
        scanf("%d %d %lld",&ed[i].u,&ed[i].v,&ed[i].w);
    sort(ed,ed + m);

    long long sum = 0;
    int fu,fv;
    for(int i = 0;i < m;i++){
        fu = fin(ed[i].u);
        fv = fin(ed[i].v);
        if(fu != fv){
            isIn[i] = true;
            sum += ed[i].w;
            addEdge(ed[i].u,ed[i].v,ed[i].w);
            fa[fu] = fv;
        }
    }

    dfs(1,0,0);

    long long ans = INF;
    for(int i = 0;i < m;i++){
        if(isIn[i]) continue;
        Lca(ed[i].u,ed[i].v);
        if(max1 != ed[i].w) ans = min(ans,sum - max1 + ed[i].w);
        else ans = min(ans,sum - max2 + ed[i].w);
    }

    printf("%lld\n",ans);

    return 0;
}

int fin(int k){
    if(fa[k] != k) fa[k] = fin(fa[k]);
    return fa[k];
}
void dfs(int cur,int fat,long long val){
    lca[cur][0] = fat;
    dep[cur] = dep[fat] + 1;
    fax[cur][0] = val;
    sax[cur][0] = -INF;

    for(int i = 1;i < K;i++){
        lca[cur][i] = lca[lca[cur][i - 1]][i - 1];
        if(fax[cur][i - 1] != fax[lca[cur][i - 1]][i - 1]){
            fax[cur][i] = max(fax[cur][i - 1],fax[lca[cur][i - 1]][i - 1]);
            sax[cur][i] = min(fax[cur][i - 1],fax[lca[cur][i - 1]][i - 1]);
        }else{
            fax[cur][i] = fax[cur][i - 1];
            sax[cur][i] = max(sax[cur][i - 1],sax[lca[cur][i - 1]][i - 1]);
        }
        if(lca[cur][i] == 0) break;
    }

    for(int i = head[cur];i;i = nod[i].next){
        if(nod[i].to == fat) continue;
        dfs(nod[i].to,cur,nod[i].w);
    }
}
void Lca(int u,int v){
    max1 = max2 = -INF;
    if(dep[u] < dep[v]) swap(u,v);
    for(int i = K - 1;i >= 0;i--){
        if(dep[lca[u][i]] >= dep[v]){
            update(fax[u][i]);
            update(sax[u][i]);
            u = lca[u][i];
        }
    }
    if(u == v) return ;
    for(int i = K - 1;i >= 0;i--){
        if(lca[u][i] != lca[v][i]){
            update(fax[u][i]);
            update(fax[v][i]);
            update(sax[u][i]);
            update(sax[v][i]);
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    update(fax[u][0]);
    update(sax[u][0]);
    update(fax[v][0]);
    update(sax[v][0]);
}

//次小生成树 LibreOJ 10133

//次小生成树：
//最小生成树依次尝试加一个未使用的边
//此时出现一个环
//将环上除新加的边外的最大边去除
//所有情况下最小的便是次小生成树

//此题求严格次小生成树
//重点在于维护次小倍增数组

//2021-5-17