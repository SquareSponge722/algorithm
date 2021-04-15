#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
struct edge{
    int to;
    long long w;
    edge(){}
    edge(int T,long long W){
        to = T,w = W;
    }
    bool operator < (const edge & ot)const{
        return w > ot.w;
    }
}com[5];
int n,ans;

long long treDis;
int pre[N];
long long dis[N],sonDis[N];

vector <edge> path[N];

void dfs(int,int,int&);
void finPath(int,int);

int main(){
    int a,b;
    long long c;
    scanf("%d",&n);
    for(int i = 1;i < n;i++){
        scanf("%d%d%lld",&a,&b,&c);
        path[a].push_back(edge(b,c));
        path[b].push_back(edge(a,c));
    }

    int st,en;
    dfs(1,0,st);
    dis[st] = 0;
    dfs(st,0,en);

    int midPoi = en;
    while(dis[pre[midPoi]] * 2 >= treDis) midPoi = pre[midPoi];

    int unuse;
    if(dis[midPoi] * 2 == treDis){
        vector <edge> edg;
        dfs(midPoi,0,unuse);
        int size = path[midPoi].size();
        for(int i = 0;i < size;i++){
            edge ed = path[midPoi][i];
            edg.push_back(edge(ed.to,ed.w + sonDis[ed.to]));
        }
        sort(edg.begin(),edg.end());

        if(edg.size() < 3 || edg[2].w < edg[0].w){
            ans += 2;
            finPath(edg[0].to,midPoi);
            finPath(edg[1].to,midPoi);
        }
    }else{
        ans++;
        finPath(midPoi,pre[midPoi]);
        finPath(pre[midPoi],midPoi);
    }

    printf("%lld\n%d",treDis,ans);
    return 0;
}

void dfs(int now,int fa,int &res){
    sonDis[now] = 0;
    pre[now] = fa;

    if(dis[now] > treDis){
        res = now;
        treDis = dis[now];
    }

    int size = path[now].size();
    for(int i = 0;i < size;i++){
        edge ed = path[now][i];
        if(ed.to == fa) continue;
        dis[ed.to] = dis[now] + ed.w;
        dfs(ed.to,now,res);
        sonDis[now] = max(sonDis[now],ed.w + sonDis[ed.to]);
    }
}
void finPath(int now,int fa){
    int unuse;
    dfs(now,fa,unuse);

    while(true){
        int cnt = 0,next = 0;
        int size = path[now].size();
        for(int i = 0;i < size;i++){
            edge ed = path[now][i];
            if(ed.to == fa) continue;
            if(ed.w + sonDis[ed.to] == sonDis[now]){
                next = ed.to;
                cnt++;
            }
        }

        if(cnt != 1) break;

        fa = now;
        now = next;
        ans++;
    }
}

//树的所有直径拥有相同的中点
//这里的dfs不仅用来找直径，还用来计算节点的最大深度
//2021-4-15