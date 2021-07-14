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

const int N = 35;
const int M = 1e3 + 10;
const int INF = 0x7f7f7f7f;

struct edge{
    int val;
    int to,next;
    edge(){}
    edge(int V,int T,int N){
        val = V,to = T,next = N;
    }
}ed[M << 1];
struct road
{
    int u,v,w;
    bool operator < (const road & ot)const{
        return w > ot.w;
    }
}roa[M];

int n,m,tot = 1;
int head[N];

int dis[N],ste[N];
bool del[N];

bool bfs();
int dfs(int,int);

inline void addEdge(int u,int v,int w){
    ed[++tot] = edge(w,v,head[u]);
    head[u] = tot;

    ed[++tot] = edge(0,u,head[v]);
    head[v] = tot;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d %d %d",&roa[i].u,&roa[i].v,&roa[i].w);
        addEdge(roa[i].u,roa[i].v,roa[i].w);
    }

    int ans = 0;
    while(bfs()) ans += dfs(1,INF);

    sort(roa,roa + m);
    int tmpAns = ans,cnt = 0;
    for(int i = 0;i < m;i++){
        if(!tmpAns) break;
        if(roa[i].w > tmpAns) continue;
        memset(head,0,sizeof(head));
        tot = 1;

        del[i] = true;
        for(int j = 0;j < m;j++){
            if(del[j]) continue;
            addEdge(roa[j].u,roa[j].v,roa[j].w);
        }

        int tmpSum = 0;
        while(bfs()) tmpSum += dfs(1,INF);

        //在此处做记录即可得最小割集
        if(tmpSum + roa[i].w == tmpAns){
            tmpAns -= roa[i].w;
            cnt++;
        }
        else del[i] = false;
    }

    printf("%d %d\n",ans,cnt);

    return 0;
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

        for(int i = head[now];i;i = ed[i].next){
            if(dis[ed[i].to] || ed[i].val <= 0) continue;
            dis[ed[i].to] = dis[now] + 1;
            ste[ed[i].to] = head[ed[i].to];
            q.push(ed[i].to);
            if(ed[i].to == n) return true;
        }
    }
    return false;
}
int dfs(int now,int flow){
    if(now == n) return flow;

    int sum = 0,tmp;
    for(int i = ste[now];i && flow;i = ed[i].next){
        ste[now] = i;
        if(dis[now] + 1 != dis[ed[i].to] || ed[i].val <= 0) continue;
        tmp = dfs(ed[i].to,min(flow,ed[i].val));
        if(!tmp) dis[ed[i].to] = 0;
        flow -= tmp;
        sum += tmp;
        ed[i].val -= tmp;
        ed[i ^ 1].val += tmp;
    }

    return sum;
}

//众所周知，最大流 = 最小割
//那么先用最大流Dinic求出最小割
//再枚举删边
//若此边权等于最大流减去删去此边的最大流
//那么这条边就是应割去的边

//关于此题还有一个巧妙的解法
//若只询问最小的割边数
//将  边权 × K + 1  作为新的边权求最大流（K > m * 1）
//那么 真实最大流 = 最大流 / K   最小割边数 = 最大流 % K

//P1344
//2021-4-10