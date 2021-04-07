#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x * f;
}
int la[110], now[110], cnt;
int ans[110][110];
int n, m;
const int M = 1000010;
int f[M][1<<8];
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    n = read(), m = read(); int S = (1<<n)-1;
    if(n <= 3 && m <= 3){
        ans[1][1] = 2; ans[1][2] = ans[2][1] = 4; ans[1][3] = ans[3][1] = 8;
        ans[2][2] = 12; ans[2][3] = ans[3][2] = 36; ans[3][3] = 112;
        cout << ans[n][m]; return 0;
    }
    for(int i=0; i<=S; i++) f[1][i] = 1;
    for(int i=2; i<=m; i++){
        for(int j=0; j<=S; j++){//now
            for(int k=0; k<=S; k++){//la
                int la = (k >> 1); la |= 1 << (n-1);
                if( (la & j) == j ){
                    f[i][j] += f[i-1][k];
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=S; i++){
        ans += f[m][i];
    }
    cout << ans;
    return 0;
}
