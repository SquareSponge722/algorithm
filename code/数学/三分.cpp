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

const int N = 310;
const double eps = 1e-8;

int t,n;
double x[N],y[N],vx[N],vy[N];

double calc(double);

int main(){
    scanf("%d",&t);
    for(int cas = 1;cas <= t;cas++){
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%lf %lf %lf %lf",&x[i],&y[i],&vx[i],&vy[i]);
        
        double l = 0,r = 1e8,midl,midr;
        while(r - l > eps){
            midl = (l + r) / 2;
            midr = (midl + r) / 2;
            if(calc(midl) >= calc(midr)) l = midl;
            else r = midr;
        }

        printf("Case #%d: %.2lf %.2lf\n",cas,l,calc(l));
    }
    return 0;
}

double calc(double k){
    double ans = 0,a,b,c,d;
    for(int i = 0;i < n;i++)
        for(int j = i + 1;j < n;j++){
            a = x[i] + vx[i] * k;
            b = y[i] + vy[i] * k;
            c = x[j] + vx[j] * k;
            d = y[j] + vy[j] * k;
            ans = max(ans,sqrt((a - c) * (a - c) + (b - d) * (b - d)));
        }
    return ans;
}

//The Moving Points
//2021-5-15