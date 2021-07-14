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

//洛谷 P1401
//2021-4-26

/*
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

const int INF = 0x7f7f7f7f;
const int N = 512;
const int M = 4e4 + 10;

struct edge{
	int next,to,w;
	edge(){}
	edge(int next,int to,int w) :
		next(next),to(to),w(w) {}
}ed[M];
int tot = 1;
int head[N];

int ste[N],dis[N];

int n,p,q;
int s,t;

bool bfs();
int dfs(int,int);

inline void addEdge(int u,int v){
	ed[++tot] = edge(head[u],v,1);
	head[u] = tot;

	ed[++tot] = edge(head[v],u,0);
	head[v] = tot;
}
int main(){
	scanf("%d %d %d",&n,&p,&q);
	s = 401,t = 402;
	for(int i = 1;i <= p;i++) addEdge(s,200 + i);
	for(int i = 1;i <= q;i++) addEdge(300 + i,t);
	for(int i = 1;i <= n;i++) addEdge(i,i + n);
	int tmp;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= p;j++){
			scanf("%d",&tmp);
			if(tmp) addEdge(200 + j,i);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= q;j++){
			scanf("%d",&tmp);
			if(tmp) addEdge(i + n,300 + j);
		}
	}

	int ans = 0;
	while(bfs()) ans += dfs(s,INF); 

	printf("%d\n",ans);

	return 0;
}
bool bfs(){
	memset(dis,0,sizeof(dis));
	dis[s] = 1;
	ste[s] = head[s];
	queue <int> q;
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(int i = head[cur];i;i = ed[i].next){
			if(ed[i].w <= 0 || dis[ed[i].to]) continue;
			ste[ed[i].to] = head[ed[i].to];
			dis[ed[i].to] = dis[cur] + 1;
			q.push(ed[i].to);
			if(ed[i].to == t) return true;
		}
	}
	return false;
}
int dfs(int cur,int flow){
	if(cur == t) return flow;

	int sum = 0,tmp;
	for(int i = ste[cur];i && flow;i = ed[i].next){
		ste[cur] = i;
		if(dis[cur] + 1 != dis[ed[i].to] || ed[i].w <= 0) continue;
		tmp = dfs(ed[i].to,min(flow,ed[i].w));
		if(!tmp) dis[ed[i].to] = 0;
		sum += tmp;
		flow -= tmp;
		ed[i].w -= tmp;
		ed[i ^ 1].w += tmp;
	}

	return sum;
}

//最大流建模
//注意对人进行拆点并将两点边权赋为1从而防止一个人选两套房菜

//2021-7-14
*/