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

const int N = 1e5 + 10;
const int M = N - 10;
const long long MOD = 998244353;

int t,n;
char str[N];
long long fac[N],inv[N];

long long qpow(long long x,long long y){
    long long res = 1;
    while(y){
        if(y & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}
inline long long nCr(long long x,long long y){
    return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main(){
    fac[0] = 1;
    for(int i = 1;i < M;i++) fac[i] = (i *fac[i - 1]) % MOD;
    inv[M - 1] = qpow(fac[M - 1],MOD - 2);
    for(int i = M - 2;i >= 0;i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;

    scanf("%d",&t);
    while(t--){
        int gro = 0,zeo = 0;
        scanf("%d",&n);
        scanf("%s",str);
        for(int i = 0;i < n;i++){
            if(str[i] == '0') zeo++;
            else if(i > 0 && str[i] == '1' && str[i - 1] == '1'){
                gro++;
                str[i] = '#';
            }
        }
        printf("%lld\n",nCr(gro + zeo,zeo));
    }
    return 0;
}

//费马小定理： b^(p-1)%p=1  b的逆元是b^(p-2)
//Lucas定理(当m,n非常大时使用)： C(n, m) % p = C(n / p, m / p) * C(n%p, m%p) % p

//https://codeforces.com/contest/1546/problem/D
//2021-7-12