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
const int N = 20;

int t,l,r;
ll dp[N][N][2];

int cnt;
int dig[N];

ll dfs(int,int,bool);
ll calc(int);

inline int GCD(int a1,int b1) {
    while(b1^=a1^=b1^=a1%=b1);
    return a1;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&l,&r);
        printf("%lld\n",calc(r) - calc(l - 1));
    }
    return 0;
}

ll calc(int num){
    memset(dp,-1,sizeof(dp));
    cnt = 0;
    while(num){
        dig[++cnt] = num % 10;
        num /= 10;
    }
    return dfs(cnt,0,true);
}
ll dfs(int pos,int num,bool isLim){
    if(pos <= 0) return 1;
    if(dp[pos][num][isLim] != -1) return dp[pos][num][isLim];
    ll res = 0;
    int lim = isLim ? dig[pos] : 9;
    for(int i = 0;i <= lim;i++){
        if(i != 0 && num != 0){
            int k = GCD(num,i);
            if(k != num && k != i) continue;
        }
        res += dfs(pos - 1,i,isLim && (i == lim));
    }
    dp[pos][num][isLim] = res;
    return res;
}

//dp[当前位数][当前位数的数字][低位是否有限制]
//dp[高位][数字K][限制] = SUM(dp[低位][合法数字G(K 与 G 为倍数关系)][限制(影响G的枚举范围)])

//https://ac.nowcoder.com/acm/contest/16786/I
//2021-6-17