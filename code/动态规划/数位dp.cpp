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

const int N = 16;

int t,l,r;
long long dp[N][N];

long long dfs(int,int);

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    while(t--){    
        for(int i = 0;i <= 9;i++) dp[1][i] = i;
        scanf("%d %d",&l,&r);
        
        int bit = 1;
        long long cntl = 0,cntr = 0;
        while(l){
            cntl += dfs(bit,l % 10);
            l /= 10;
            bit++;
        }
        bit = 1;
        while(r){
            cntr += dfs(bit,r % 10);
            r /= 10;
            bit++;
        }
        printf("%lld\n",cntr - cntl);
    }
    return 0;
}

long long dfs(int bit,int num){
    if(num == 0) return 0;
    if(dp[bit][num] != -1) return dp[bit][num];
    dp[bit][num] = bit;
    if(num != 1) dp[bit][num] += dfs(bit,num - 1);
    for(int i = bit - 1;i > 0;i--) dp[bit][num] += dfs(i,9);
    return dp[bit][num];
}

//基础数位dp 记忆化搜索
//CodeForces 1538F
//2021-6-10