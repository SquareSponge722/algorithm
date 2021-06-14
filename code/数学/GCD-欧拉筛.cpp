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
const int N = 5e5 + 10;

ll t,a,b,k;

ll cnt;
bool vis[N];
ll prime[N];

inline ll GCD(ll a1,ll b1) {
    while(b1^=a1^=b1^=a1%=b1);
    return a1;
}
inline ll getSum(ll num){
    ll tot = 0,lim = num;
    for(int i = 0;i < cnt && prime[i] * prime[i] <= lim;i++){ //此处的判断非常重要，此题至少加快了4倍
        if(num == 1) break;
        while(num % prime[i] == 0){
            tot++;
            num /= prime[i];
        }
    }
    if(num > 1) tot++;
    return tot;
}

int main(){
    for(int i = 2;i < N;i++){
        if(!vis[i]) prime[cnt++] = i;
        for(int j = 0;j < cnt && i * prime[j] < N;j++){
            vis[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }

    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld %lld",&a,&b,&k);
        ll gcd = GCD(a,b);
        ll l = 0,r = 0;
        if(a != b) l = (gcd == a || gcd == b) ? 1 : 2;
        r = getSum(a) + getSum(b);
        if(l <= k && k <= r){
            if(l == 1 && k == 1){
                printf("YES\n");
                continue;
            }
            if(k != 1){
                printf("YES\n");
                continue;
            }
        }
        printf("NO\n");
    }
    return 0;
}

//GCD 欧拉素数筛 质因数分解
//一定要注意细节，一个小判断就可以加速4倍

//CodeForces 1538D

//2021-6-14