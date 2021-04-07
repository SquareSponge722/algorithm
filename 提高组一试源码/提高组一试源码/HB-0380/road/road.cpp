#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
#define re register
using namespace std;

const int maxn=1000000;
int n;
ll a[maxn];
ll ans[maxn];
ll ed[maxn];
ll day=0;
ll cnt=1;

inline bool check()
{
    for(int i=1; i<=n; ++i)
        if(a[i]!=0) return false;
    return true;
}

inline void solve()
{
    ll maxr=0;
    ll maxcnt=0;
    cnt=1;
    memset(ans,0,sizeof(ans));
    for(re int i=1; i<=n; ++i) {
        if(i==n) {
            ans[cnt]++;
            ed[cnt]=n;
            if(maxr<ans[cnt]) {
                maxr=ans[cnt];
                maxcnt=cnt;
            }
            break;
        }
        if(a[i]!=0) ans[cnt]++;
        else {
            ed[cnt]=i-1;
            if(maxr<ans[cnt]) {
                maxr=ans[cnt];
                maxcnt=cnt;
            }
            cnt++;
        }
    }
    bool flag=true;
    while(flag) {
        for(re int i=maxr-1; i>=0; --i) {
            a[ed[maxcnt]-i]--;
            if(a[ed[maxcnt]-i]==0) flag=false;
        }
        day++;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d",&n);
    for(re int i=1; i<=n; ++i) scanf("%d",&a[i]);
    while(!check()) solve();
    printf("%d",day);
    return 0;
}
