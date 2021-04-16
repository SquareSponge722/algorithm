#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 8e4 + 10;
const int M = 18;

struct tree{
    int ls,rs;
    int size;
}tre[N * 600];
int cnt,tot;
int root[N];

int testcase;
int n,m,t;
int val[N],has[N];
char str[5];

int fa[N];

bool vis[N];
int treSize[N],dep[N];
int lca[N][M];

struct edge{
    int to,next;
}ed[N << 2];
int head[N],sum;

int getHash(int);
int fin(int);
void dfs(int,int,int);
int getLca(int,int);
void insert(int&,int,int,int,int);
int query(int,int,int,int,int,int,int);

inline void addEdge(int u,int v){
    ed[++sum].to = v;
    ed[sum].next = head[u];
    head[u] = sum;
}

int main(){
    scanf("%d",&testcase);
    scanf("%d %d %d",&n,&m,&t);

    for(int i = 1;i <= n;i++){
        scanf("%d",&val[i]);
        has[i] = val[i];
        fa[i] = i;
    }
    sort(has + 1,has + 1 + n);
    tot = unique(has + 1,has + 1 + n) - has - 1;
    
    int u,v;
    while(m--){
        scanf("%d %d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }

    for(int i = 1;i <= n;i++){
        if(vis[i]) continue;
        dfs(i,0,i);
        fa[i] = i;
    }

    int k,lastAns = 0;    
    while(t--){
        scanf("%s %d %d",str,&u,&v);
        u = u ^ lastAns;
        v = v ^ lastAns;
        if(str[0] == 'Q'){
            scanf("%d",&k);
            k = k ^ lastAns;
            int LCA = getLca(u,v);
            lastAns = query(root[u],root[v],root[LCA],root[lca[LCA][0]],1,tot,k);
            printf("%d\n",lastAns);
        }else{
            int fu = fin(u);
            int fv = fin(v);

            addEdge(u,v);
            addEdge(v,u);

            if(treSize[fu] > treSize[fv]) dfs(v,u,fu);
            else dfs(u,v,fv);
        }
    }

    return 0;
}

int getHash(int k){
    return lower_bound(has + 1,has + tot + 1,k) - has;
}
int fin(int k){
    if(fa[k] != k) fa[k] = fin(fa[k]);
    return fa[k];
}
void dfs(int now,int fat,int rt){
    vis[now] = true;
    treSize[rt]++;
    lca[now][0] = fa[now] = fat;
    dep[now] = dep[fat] + 1;

    insert(root[now],root[fat],1,tot,getHash(val[now]));

    for(int i = 1;i < M;i++){
        lca[now][i] = lca[lca[now][i - 1]][i - 1];
        //if(!lca[now][i]) break;
        //绝对不可以加这一行代码
        //如果存在 一条长链 连向 一颗节点但深度不及它的树
        //那么长链上的节点的深度可能会减小（比如链的中点为连接点）
        //那么如果存在此行代码
        //就会导致lca中倍增尺更长的地方不会更新为 0 ，而是保存有原先的旧数据
        //此时调用getLca()找公共祖先就可能会出现错误！！！
    }

    for(int i = head[now];i;i = ed[i].next){
        int to = ed[i].to;
        if(to == fat) continue;
        dfs(to,now,rt);
    }
}
int getLca(int u,int v){
    if(u == v) return u;
    if(dep[u] < dep[v]) swap(u,v);
    for(int i = M - 1;i >= 0;i--){
        if(dep[lca[u][i]] >= dep[v]) u = lca[u][i];
    }
    if(u == v) return u;
    for(int i = M - 1;i >= 0;i--){
        if(lca[u][i] != lca[v][i]){
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0];
}
void insert(int &now,int pre,int l,int r,int w){
    now = ++cnt;
    tre[now] = tre[pre];
    tre[now].size++;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(w <= mid) insert(tre[now].ls,tre[pre].ls,l,mid,w);
    else insert(tre[now].rs,tre[pre].rs,mid + 1,r,w);
}
int query(int leaf1,int leaf2,int LCA,int lcaFa,int l,int r,int q){
    if(l == r) return has[l];
    int mid = (l + r) >> 1;
    int lsize = tre[tre[leaf1].ls].size + tre[tre[leaf2].ls].size - tre[tre[LCA].ls].size - tre[tre[lcaFa].ls].size;
    if(q <= lsize) return query(tre[leaf1].ls,tre[leaf2].ls,tre[LCA].ls,tre[lcaFa].ls,l,mid,q);
    else return query(tre[leaf1].rs,tre[leaf2].rs,tre[LCA].rs,tre[lcaFa].rs,mid + 1,r,q - lsize);
}

//大数据情况下前向星的速度比vector还是快很多的
//对着出错的那行代码说“这行一定没问题”然后在其他地方找几个小时bug的我是傻逼
//如果没有连边的操作(深度改变)，那么那行优化是没问题的

//2021-4-16