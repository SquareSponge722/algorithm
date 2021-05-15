

//单点修改，区间查询
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

const int N = 1e6 + 10;

int n,q;

long long tre[N];

void add(int,int);
long long fin(int);

inline int lowbit(int k){
    return k & (-k);
}

int main(){
    int x,y,z;
    scanf("%d %d",&n,&q);
    for(int i = 1;i <= n;i++){
        scanf("%d",&x);
        add(i,x);
    }
    while(q--){
        scanf("%d %d %d",&x,&y,&z);
        if(x == 1) add(y,z);
        else printf("%lld\n",fin(z) - fin(y - 1));
    }
    return 0;
}

void add(int pos,int val){
    for(int i = pos;i <= n;i += lowbit(i))
        tre[i] += (long long)val;
}
long long fin(int pos){
    long long sum = 0;
    for(int i = pos;i > 0;i -= lowbit(i))
        sum += tre[i];
    return sum;
}


/*
//区间修改，单点查询
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

const int N = 1e6 + 10;

int n,q;

long long tre[N];

void add(int,int);
long long fin(int);

inline int lowbit(int k){
    return k & (-k);
}

int main(){
    int x,y,z,w;
    int pre = 0;
    scanf("%d %d",&n,&q);
    for(int i = 1;i <= n;i++){
        scanf("%d",&x);
        add(i,x - pre);
        pre = x;
    }
    while(q--){
        scanf("%d",&x);
        if(x == 1){
            scanf("%d %d %d",&y,&z,&w);
            add(y,w);
            add(z + 1,-w);
        }else{
            scanf("%d",&y);
            printf("%lld\n",fin(y));
        }
    }
    return 0;
}

void add(int pos,int val){
    for(int i = pos;i <= n;i += lowbit(i))
        tre[i] += (long long)val;
}
long long fin(int pos){
    long long sum = 0;
    for(int i = pos;i > 0;i -= lowbit(i))
        sum += tre[i];
    return sum;
}
*/

/*
//区间修改，区间查询
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

const int N = 1e6 + 10;

int n,q;

long long tre1[N],tre2[N];

void add(int,int);
void rangeAdd(int,int,int);
long long fin(int);
long long rangeFin(int,int);

inline int lowbit(int k){
    return k & (-k);
}

int main(){
    int x,y,z,w;
    scanf("%d %d",&n,&q);
    for(int i = 1;i <= n;i++){
        scanf("%d",&x);
        rangeAdd(i,i,x);
    }
    while(q--){
        scanf("%d",&x);
        if(x == 1){
            scanf("%d %d %d",&y,&z,&w);
            rangeAdd(y,z,w);
        }else{
            scanf("%d %d",&y,&z);
            printf("%lld\n",rangeFin(y,z));
        }
    }
    return 0;
}

void add(int pos,int val){
    for(int i = pos;i <= n;i += lowbit(i))
        tre1[i] += (long long)val,tre2[i] += (long long)val * (long long)pos;
}
void rangeAdd(int l,int r,int val){
    add(l,val);
    add(r + 1,-val);
}
long long fin(int pos){
    long long sum = 0;
    for(int i = pos;i > 0;i -= lowbit(i))
        sum += (long long)(pos + 1) * tre1[i] - tre2[i];
    return sum;
}
long long rangeFin(int l,int r){
    return fin(r) - fin(l - 1);
}
*/

/*
//二维树状数组：单点修改，区间查询
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

const int N = 5e3 + 10;

int n,m;

long long tre[N][N];

void add(int,int,int);
long long fin(int,int);

inline int lowbit(int k){
    return k & (-k);
}

int main(){
    int x,a,b,c,d;
    scanf("%d %d",&n,&m);
    while(~scanf("%d",&x)){
        if(x == 1){
            scanf("%d %d %d",&a,&b,&c);
            add(a,b,c);
        }else{
            scanf("%d %d %d %d",&a,&b,&c,&d);
            printf("%lld\n",fin(c,d) - fin(a - 1,d) - fin(c,b - 1) + fin(a - 1,b - 1));
        }
    }
    return 0;
}

void add(int x,int y,int val){
    int memy = y;
    for(;x <= n;x += lowbit(x))
        for(y = memy;y <= m;y += lowbit(y))
            tre[x][y] += (long long)val;
}
long long fin(int x,int y){
    long long sum = 0;
    int memy = y;
    for(;x > 0;x -= lowbit(x))
        for(y = memy;y > 0;y -= lowbit(y))
            sum += tre[x][y];
    return sum;
}
*/

/*
//二维树状数组：区间修改，单点查询
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

const int N = 5e3 + 10;

int n,m;

long long tre[N][N];

void add(int,int,int);
void rangeAdd(int,int,int,int,int);
long long fin(int,int);

inline int lowbit(int k){
    return k & (-k);
}

int main(){
    int x,a,b,c,d,w;
    scanf("%d %d",&n,&m);
    while(~scanf("%d",&x)){
        if(x == 1){
            scanf("%d %d %d %d %d",&a,&b,&c,&d,&w);
            rangeAdd(a,b,c,d,w);
        }else{
            scanf("%d %d",&a,&b);
            printf("%lld\n",fin(a,b));
        }
    }
    return 0;
}

void add(int x,int y,int val){
    int memy = y;
    for(;x <= n;x += lowbit(x))
        for(y = memy;y <= m;y += lowbit(y))
            tre[x][y] += (long long)val;
}
void rangeAdd(int a,int b,int c,int d,int val){
    add(a,b,val);
    add(a,d + 1,-val);
    add(c + 1,b,-val);
    add(c + 1,d + 1,val);
}
long long fin(int x,int y){
    long long sum = 0;
    int memy = y;
    for(;x > 0;x -= lowbit(x))
        for(y = memy;y > 0;y -= lowbit(y))
            sum += tre[x][y];
    return sum;
}
*/

/*
//二维树状数组：区间修改，区间查询
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

const int N = 3e3 + 10;

int n,m;

long long tre1[N][N],tre2[N][N],tre3[N][N],tre4[N][N];

void add(long long,long long,long long);
void rangeAdd(long long,long long,long long,long long,long long);
long long fin(long long,long long);
long long rangeFin(long long,long long,long long,long long);

inline int lowbit(int k){
    return k & (-k);
}

int main(){
    long long x,a,b,c,d,w;
    scanf("%d %d",&n,&m);
    while(~scanf("%lld",&x)){
        if(x == 1){
            scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&w);
            rangeAdd(a,b,c,d,w);
        }else{
            scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
            printf("%lld\n",rangeFin(a,b,c,d));
        }
    }
    return 0;
}

void add(long long x,long long y,long long val){
    for(int i = (int)x;i;i += lowbit(i))
        for(int j = (int)y;j;j += lowbit(j)){
            tre1[i][j] += val;
            tre2[i][j] += val * x;
            tre3[i][j] += val * y;
            tre4[i][j] += val * x * y;
        }
}
void rangeAdd(long long a,long long b,long long c,long long d,long long val){
    add(a,b,val);
    add(a,d + 1,-val);
    add(c + 1,b,-val);
    add(c + 1,d + 1,val);
}
long long fin(long long x,long long y){
    long long sum = 0;
    for(int i = (int)x;i;i -= lowbit(i))
        for(int j = (int)y;j;j -= lowbit(j))
            sum += (x + 1) * (y + 1) * tre1[i][j] - (y + 1) * tre2[i][j] - (x + 1) * tre3[i][j] + tre4[i][j];
    return sum;
}
long long rangeFin(long long a,long long b,long long c,long long d){
    return fin(c,d) - fin(c,b - 1) - fin(a - 1,d) + fin(a - 1,b - 1);
}
*/

//2021-5-11