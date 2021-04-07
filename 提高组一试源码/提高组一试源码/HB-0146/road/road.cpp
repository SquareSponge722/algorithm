#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x * f;
}
const int N = 100010;
int a[N], n;
int work(int l, int r){
    if(l > r) return 0;
    //cout << "M " << l << ' ' << r << endl;
    //for(int i=l; i<=r; i++) cout << a[i] << " "; puts("");
    if(l == r) { int ans = a[l]; a[l] = 0; return ans; }
    while(a[l] == 0) l ++;
    while(a[r] == 0 && r > l) r --;
    int Min = 0x3f3f3f3f;
    for(int i=l; i<=r; i++){
        Min = min(a[i], Min);
    }
    int ans = Min;
    int la = l;
    for(int i=l; i<=r; i++) a[i] -= Min;
    for(int i=l; i<=r; i++){
        if(a[i] == 0) {
            ans += work(la, i-1); la = i;
        }
    }
    if(la <= r) ans += work(la, r);
    return ans;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read();
    for(int i=1; i<=n; i++) a[i] = read();
    cout << work(1, n);
    return 0;
}
/*
6
4 3 2 5 3 5
*/
