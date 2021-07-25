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
#define ll long long

const ll MOD = 1e9 + 7;
const int N = 128;

int t,n,k;
int cnt[N];
bool vis[N];
ll dp[N][N];
vector <int> path[N];

ll calc(int,int);

int main(){
    int a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i = 0;i <= n;i++) path[i].clear();
        for(int i = 1;i < n;i++){
            scanf("%d %d",&a,&b);
            path[a].push_back(b);
            path[b].push_back(a);
        }
        if(k == 2){
            printf("%lld\n",(n - 1ll) * n / 2 % MOD);
            continue;
        }
        ll ans = 0;
        for(int root = 1;root <= n;root++){
            memset(vis,false,sizeof(vis));
            vis[root] = true;
            int size = path[root].size();
            vector <pair<int,int>> layer;
            for(int i = 0;i < size;i++){
                int son = path[root][i];
                layer.emplace_back(son,i);
                cnt[i] = 1;
                vis[son] = true;
            }
            while(!layer.empty()){
                ans = (ans + calc(size,k)) % MOD;
                vector <pair<int,int>> newLayer;
                for(auto node : layer){
                    cnt[node.second]--;
                    for(auto son : path[node.first]){
                        if(vis[son]) continue;
                        vis[son] = true;
                        cnt[node.second]++;
                        newLayer.emplace_back(son,node.second);
                    }
                }
                layer = newLayer;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

ll calc(int x,int y){ //前x棵子树内选y个点(每棵至多选1个点)
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0;i < x;i++)
        for(int j = 0;j <= y;j++){
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * cnt[i] % MOD) % MOD;
        }
    return dp[x][y];
}

//vector::emplace_back() 与push_back功能相同，但可以根据传入参数自动调用构造函数(若类型为对象)

//http://codeforces.com/contest/1551/problem/F
//2021-7-25