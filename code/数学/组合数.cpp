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

const int N = 55;

long long n,k;
long long l,r;
long long num[N],c[N][N];

long long sol(long long);

int main(){
    c[0][0] = 1;
    for(int i = 1;i < N;i++)
        for(int j = 0;j <= i;j++){ //预处理组合数
            if(j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }

    scanf("%lld %lld",&n,&k);
    for(int i = 0;i < n;i++) scanf("%lld",&num[i]);
    sort(num,num + n,greater<long long>());

    scanf("%lld %lld",&l,&r);
    printf("%lld\n",sol(r) - sol(l - 1));
    return 0;
}

long long sol(long long t){
    long long ans = 0,res = k;
    for(int i = 0;i < n;i++){
        if(num[i] > t) continue;
        ans += c[n - i - 1][res];
        if(res == 0) return ans;
        t -= num[i];
        res--;
    }
    return ans + (res == 0); //非法返回 0 //合法加上 1 因为选择的那一种没算进去
}

// SBC's Hangar
// 2021-5-8