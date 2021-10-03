#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long
#define lson(k) (k << 1)
#define rson(k) (k << 1 | 1)

const int N = 1e5 + 10;
const int M = 128;
const int K = 25;
const ll MOD = 998244353;

struct node{
    int l,r;
    ll sum,laz;
    bool tag[K];

    node(){}
    node(int l,int r,ll sum,ll laz) :
        l(l),r(r),sum(sum),laz(laz) {}
}tre[N << 2];

int n,m;
ll x[N];

int eul[M],ecnt[M][K];
ll prime[K] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void build(int cur,int l,int r);
void update(int cur,int l,int r,int id,int cnt);
ll query(int cur,int l,int r);

inline void upp(int cur){
    for(int i = 0;i < K;i++){
        tre[cur].tag[i] = (tre[lson(cur)].tag[i] && tre[rson(cur)].tag[i]);
    }
    tre[cur].sum = (tre[lson(cur)].sum + tre[rson(cur)].sum) % MOD;
}
inline void ddown(int cur){
    if(tre[cur].laz != 1){
        tre[lson(cur)].sum = (tre[lson(cur)].sum * tre[cur].laz) % MOD;
        tre[rson(cur)].sum = (tre[rson(cur)].sum * tre[cur].laz) % MOD;
        tre[lson(cur)].laz = (tre[lson(cur)].laz * tre[cur].laz) % MOD;
        tre[rson(cur)].laz = (tre[rson(cur)].laz * tre[cur].laz) % MOD;
        tre[cur].laz = 1;
    }
}

int main(){
    int tmp;
    for(int i = 1;i <= 100;i++){
        tmp = eul[i] = i;
        for(int j = 0;j < K;j++){
            if(i % prime[j]) continue;
            eul[i] = eul[i] / prime[j] * (prime[j] - 1);
            while(!(tmp % prime[j])){
                ecnt[i][j]++;
                tmp /= prime[j];
            }
        }
    }

    int op,l,r,w;
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%lld",&x[i]);
    build(1,1,n);
    while(m--){
        scanf("%d %d %d",&op,&l,&r);
        if(op == 0){
            scanf("%d",&w);
            for(int i = 0;i < K && prime[i] <= w;i++){
                if(ecnt[w][i]) update(1,l,r,i,ecnt[w][i]);
            }
        }else{
            printf("%lld\n",query(1,l,r));
        }
    }
    return 0;
}

void build(int cur,int l,int r){
    tre[cur] = node(l,r,0,1);
    if(l == r){
        tre[cur].sum = eul[x[l]];
        for(int i = 0;i < K && prime[i] <= x[l];i++){
            if(ecnt[x[l]][i]) tre[cur].tag[i] = true;
        }
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson(cur),l,mid);
    build(rson(cur),mid + 1,r);
    upp(cur);
}
void update(int cur,int l,int r,int id,int cnt){
    if(tre[cur].tag[id] && l <= tre[cur].l && tre[cur].r <= r){
        while(cnt--){
            tre[cur].sum = (tre[cur].sum * prime[id]) % MOD;
            tre[cur].laz = (tre[cur].laz * prime[id]) % MOD;
        }
        return ;
    }else if(tre[cur].l == tre[cur].r){
        tre[cur].sum = (tre[cur].sum * (prime[id] - 1)) % MOD;
        tre[cur].laz = (tre[cur].laz * (prime[id] - 1)) % MOD;
        tre[cur].tag[id] = true;
        for(int i = 1;i < cnt;i++){
            tre[cur].sum = (tre[cur].sum * prime[id]) % MOD;
            tre[cur].laz = (tre[cur].laz * prime[id]) % MOD;
        }
        return ;
    }
    int mid = (tre[cur].l + tre[cur].r) >> 1;
    ddown(cur);
    if(l <= mid) update(lson(cur),l,r,id,cnt);
    if(r > mid) update(rson(cur),l,r,id,cnt);
    upp(cur);
}
ll query(int cur,int l,int r){
    if(l <= tre[cur].l && tre[cur].r <= r) return tre[cur].sum;
    int mid = (tre[cur].l + tre[cur].r) >> 1;
    ddown(cur);
    ll ans = 0;
    if(l <= mid) ans = query(lson(cur),l,r);
    if(r > mid) ans += query(rson(cur),l,r);
    return ans % MOD;
}

/**
 * Euler(n) = n * (1 - 1 / P_1) * (1 - 1 / P_2) ... * (1 - 1 / P_n)  P_i与n互质
 * 当 P 为质数时:
 *      - 若P与n互质，Euler(n * P) = Euler(n) * (P - 1)
 *      - 若P不与n互质，Euler(n * P) = Euler(n) * P
 *      - Euler(P) = P - 1
 * */

//2021 icpc2 L Euler Function
//https://pintia.cn/problem-sets/1441745686294945792/problems/1441745856154955787