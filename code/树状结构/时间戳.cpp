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

const int N = 2e5 + 10;

int t,n,stamp;

long long ans[N];

int in[N],out[N],siz[N];
vector <int> path[N];

void dfs(int,int);

int main(){
    scanf("%d",&t);
    while(t--){
        int u,v;
        ans[0] = stamp = 0;

        scanf("%d",&n);
        for(int i = 0;i <= n;i++){
            path[i].clear();
            ans[i] = 0;
        }
        for(int i = 1;i < n;i++){
            scanf("%d %d",&u,&v);
            path[u].push_back(v);
            path[v].push_back(u);
        }

        dfs(0,-1);

        int st = -1,l = 1,r = -1;
        ans[0] = ans[1] = (long long)(n) * (n - 1) / 2;
        for(auto to : path[0]){
            ans[1] -= (long long)(siz[to]) * (siz[to] - 1) / 2;
            if(in[to] <= in[1] && in[1] < out[to]){ // to 为 1 的 祖先或本身
                st = to;
            }
        }
        for(int i = 1;i < n;i++){
            bool isInSeg = false;
            if(in[i] <= in[l] && in[l] < out[i]) isInSeg = true;
            if(r != -1 && in[i] <= in[r] && in[r] < out[i]) isInSeg = true;
            if(!isInSeg){
                if(in[l] <= in[i] && in[i] < out[l]){
                    l = i;
                }else if((r == -1 && !(in[st] <= in[i] && in[i] < out[st])) || (in[r] <= in[i] && in[i] < out[r])){
                    r = i;
                }else{
                    break;
                }
            }
            if(r == -1){
                ans[i + 1] = (long long)(siz[l]) * (n - siz[st]);
            }else{
                ans[i + 1] = (long long)(siz[l]) * siz[r];
            }
        }
        for(int i = 0;i < n;i++){
            ans[i] -= ans[i + 1];
        }
        for(int i = 0;i <= n;i++){
            if(i == 0) printf("%lld",ans[i]);
            else printf(" %lld",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

void dfs(int cur,int pre){ //siz[cur] 包括 cur 本身
    in[cur] = stamp++;
    for(auto to : path[cur]){
        if(to == pre) continue;
        dfs(to,cur);
    }
    out[cur] = stamp;
    siz[cur] = out[cur] - in[cur];
}

//利用时间戳来计算子树大小和判断两点是否在一条链上

//ans[i] 为 MEX >= i 的个数
//那么 (MEX = i) 等于 (MEX >= i) - (MEX > i)
//即 (MEX = i) 等于 ans[i] - ans[i + 1]

//CF MEX tree
//2021-5-22