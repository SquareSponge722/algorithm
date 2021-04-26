#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;

const int N = 2e2 + 10;
const int M = 4e4 + 10;
const int INF = 0x3f3f3f3f;

struct node{
    int next,to,w;
    node(){}
    node(int Next,int To,int W){
        next = Next,to = To,w = W;
    }
}nod[M];
int tot = 1;
int head[N];

struct edge{
    int u,v,w;
    bool operator < (const edge & ot)const{
        return w < ot.w;
    }
}ed[M];
int n,m,t;

int dis[N],ste[N];

int dinic();
bool bfs();
int dfs(int,int);

inline void addNode(int u,int v,int w){
    nod[++tot] = node(head[u],v,w);
    head[u] = tot;

    nod[++tot] = node(head[v],u,w);
    head[v] = tot;
}
int main(){
    scanf("%d %d %d",&n,&m,&t);
    for(int i = 0;i < m;i++){
        scanf("%d %d %d",&ed[i].u,&ed[i].v,&ed[i].w);
    }
    sort(ed,ed + m);

    for(int i = 0;i < m;i++){
        addNode(ed[i].u,ed[i].v,1);
        for(int j = i + 1;j < m;j++){
            if(ed[j].w != ed[i].w){
                i = j - 1;
                break;
            }
            addNode(ed[j].u,ed[j].v,1);
        }

        t -= dinic();
        if(t <= 0){
            printf("%d\n",ed[i].w);
            break;
        }
    }
    return 0;
}
int dinic(){
    int ans = 0;
    while(bfs()) ans += dfs(1,INF);
    return ans;
}
bool bfs(){
    memset(dis,0,sizeof(dis));
    dis[1] = 1;
    ste[1] = head[1];
    
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = head[now];i;i = nod[i].next){
            if(dis[nod[i].to] || nod[i].w <= 0) continue;
            ste[nod[i].to] = head[nod[i].to];
            dis[nod[i].to] = dis[now] + 1;
            q.push(nod[i].to);
            if(nod[i].to == n) return true;
        }
    }
    return false;
}
int dfs(int now,int flow){
    if(now == n) return flow;

    int tmp,sum = 0;
    for(int i = ste[now];i && flow;i = nod[i].next){
        ste[now] = i;
        if(dis[now] + 1 != dis[nod[i].to] || nod[i].w <= 0) continue;
        tmp = dfs(nod[i].to,min(flow,nod[i].w));
        if(!tmp) dis[nod[i].to] = 0;
        sum += tmp;
        flow -= tmp;
        nod[i].w -= tmp;
        nod[i ^ 1].w += tmp;
    }

    return sum;
}

//最大流练习
//当边权为1时 最大流 = 从原点至汇点无重边最大路径数
//此题在残量图上加边计算比用二分重新建图计算更快
//2021-4-26