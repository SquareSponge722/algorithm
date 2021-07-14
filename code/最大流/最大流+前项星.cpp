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

const long long INF_LL = 0x7f7f7f7f7f7f7f7f;
const int N = 5e4 + 10;

struct edge{
    long long val;
    int to,next;
}ed[N << 1];

int n,m,s,t;

//tot的初始值应为1或-1
//因为后面要用到异或运算应保证初始值低位为0（++tot 为 0 or 2）
//但使用-1会用到0，导致需要重新定义一个edge.next的终止标志
//所以更推荐用 1
int tot = 1;
int head[N];

//ste为startEdge，此处为弧优化
//dis为点的bfs分层的层数
int ste[N],dis[N];

bool bfs();
long long dfs(int,long long);

inline void addEdge(int u,int v,long long w){
    ed[++tot].val = w;
    ed[tot].to = v;
    ed[tot].next = head[u];
    head[u] = tot;

    ed[++tot].val = 0;
    ed[tot].to = u;
    ed[tot].next = head[v];
    head[v] = tot;
}

int main(){
    int u,v;
    long long w,ans = 0;
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i = 0;i < m;i++){
        scanf("%d %d %lld",&u,&v,&w);
        addEdge(u,v,w);
    }

    while(bfs()) ans += dfs(s,INF_LL);

    printf("%lld\n",ans);

    return 0;
}
bool bfs(){
    memset(dis,0,sizeof(dis));
    dis[s] = 1;
    ste[s] = head[s];
    queue <int> q;
    q.push(s);
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = head[now];i;i = ed[i].next){
            if(ed[i].val <= 0 || dis[ed[i].to]) continue;
            ste[ed[i].to] = head[ed[i].to]; //在此处对弧优化初始化
            dis[ed[i].to] = dis[now] + 1;
            q.push(ed[i].to);
            if(ed[i].to == t) return true;
        }
    }
    return false;
}
//flow为之前节点至当前节点的流量限制
long long dfs(int now,long long flow){
    if(now == t) return flow;

    long long sum = 0,tmp;
    for(int i = ste[now];i && flow;i = ed[i].next){
        ste[now] = i;
        if(dis[ed[i].to] != dis[now] + 1 || ed[i].val <= 0) continue;
        tmp = dfs(ed[i].to,min(flow,ed[i].val));
        if(!tmp) dis[ed[i].to] = 0; //剪枝 去除无法抵达汇点的下一个节点
        sum += tmp;
        flow -= tmp;
        ed[i].val -= tmp;
        ed[i ^ 1].val += tmp;
    }

    return sum;
}

//最大流Dinic算法 O（n²m） 1e4~1e5
//P3376
//2021-4-10