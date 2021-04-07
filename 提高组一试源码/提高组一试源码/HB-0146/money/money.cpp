#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x * f;
}
const int N = 100010;
int vis[N], tmp[N], MAX[N], cnt;
int a[N], n, t, ans = 0x3f3f3f3f;
void dfs(int now, int sum){
    if(now > n){
        ans = sum - 1;
        return;
    }
    if(vis[a[now]]){
        dfs(now + 1, sum);
        return;
    }
    vis[a[now]] = 1;
    tmp[++cnt] = a[now];
    for(int j=a[now]; j<=MAX[now]; j++){
        vis[j] |= vis[j - a[now]];
    }
    dfs(now + 1, sum + 1);
}
int main(){
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    t = read();
    while(t --){
        ans = 0x3f3f3f3f;
        memset(vis, 0, sizeof(vis));
        memset(tmp, 0, sizeof(tmp));
        memset(MAX, 0, sizeof(MAX));
        n = read(); cnt = 0;
        for(int i=1; i<=n; i++){
            a[i] = read();
        }
        sort(a+1, a+n+1);
        for(int i=n; i>=1; i--){
            MAX[i] = max(MAX[i+1], a[i]);
        }
        dfs(1, 1);
        cout << ans << endl;
    }
    return 0;
}
