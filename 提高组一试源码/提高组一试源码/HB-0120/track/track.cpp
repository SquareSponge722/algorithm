#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
typedef  long long ll;

const int maxn = 1000;
int n,m;
int sum;
typedef struct{
    int a;
    int b;
    int len;
}Road;

Road r[maxn];

int main(void)
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin>>r[i].a>>r[i].b>>r[i].len;
        sum+=r[i].len;
    }
    cout << sum;
    return 0;
}

