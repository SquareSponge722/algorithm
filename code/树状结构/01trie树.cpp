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

int n;
int L[N],R[N],W[N];
vector <pair<int,int>> path[N];

struct Tire{
    static const int maxn = 62 * 1e5;
    int tot,ans,root;
    int pw[32],cnt[maxn],ch[maxn][2];

    int newNode(){
        ++tot;
        cnt[tot] = ch[tot][0] = ch[tot][1] = 0;
        return tot;
    }
    void init(){
        tot = 0;
        root = newNode();
        pw[0] = 1;
        for(int i = 1;i <= 30;i++) pw[i] = (pw[i - 1] << 1);
    }
    void updateL(int w,int l){
        int cur = root;
        for(int i = 29;i >= 0;i--){
            int dw = (w >> i) & 1;
            int dl = (l >> i) & 1;
            if(dl == 1){ //保持选取的数此位和dl都为1
                if(!ch[cur][dw ^ 1]) ch[cur][dw ^ 1] = newNode();
                cur = ch[cur][dw ^ 1];
            }else{ //若此位为1，则选取的数必大于l，因此打上一个cnt标记，后面的位可以任意取
                if(!ch[cur][dw ^ 1]) ch[cur][dw ^ 1] = newNode();
                cnt[ch[cur][dw ^ 1]]++;
                if(!ch[cur][dw]) ch[cur][dw] = newNode(); //同时依然保持选取的数和dl相同
                cur = ch[cur][dw];
            }
        }
        cnt[cur]++;
    }
    void updateR(int w,int r){
        int cur = root;
        for(int i = 29;i >= 0;i--){
            int dw = (w >> i) & 1;
            int dr = (r >> i) & 1;
            if(dr == 0){
                if(!ch[cur][dw]) ch[cur][dw] = newNode();
                cur = ch[cur][dw];
            }else{
                if(!ch[cur][dw]) ch[cur][dw] = newNode();
                cnt[ch[cur][dw]]++;
                if(!ch[cur][dw ^ 1]) ch[cur][dw ^ 1] = newNode();
                cur = ch[cur][dw ^ 1];
            }
        }
        cnt[cur]++;
    }
    void query(int cur,int sum,int dep){
        sum += cnt[cur];
        if(sum == (n << 1)) ans += pw[30 - dep];
        if(ch[cur][0]) query(ch[cur][0],sum,dep + 1);
        if(ch[cur][1]) query(ch[cur][1],sum,dep + 1);
    }
}tire;

void dfs(int,int,int);

int main(){
    int x,y,z;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d %d",&L[i],&R[i]);
    for(int i = 1;i < n;i++){
        scanf("%d %d %d",&x,&y,&z);
        path[x].emplace_back(y,z);
        path[y].emplace_back(x,z);
    }
    dfs(1,0,0);

    tire.init();
    for(int i = 1;i <= n;i++){
        tire.updateL(W[i],L[i]);
        tire.updateR(W[i],R[i]);
    }
    tire.query(tire.root,0,0);
    printf("%d\n",tire.ans);
    return 0;
}

void dfs(int cur,int fa,int val){
    W[cur] = val;
    for(auto son : path[cur]){
        if(son.first == fa) continue;
        dfs(son.first,cur,val ^ son.second);
    }
}

//01trie树的应用
//打标记的思路很灵活

//https://ac.nowcoder.com/acm/contest/11255/E
//2021-7-26