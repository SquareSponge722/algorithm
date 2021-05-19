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

const int N = 6e5 + 10;
const int K = 24;

int trie[N * K][2],latest[N * K];
int s[N],root[N];
char str[5];
int n,m,tot;

void insert(int&,int,int,int);
int query(int,int,int,int);

int main(){
    latest[0] = -1;
    insert(root[0],0,K - 1,0);
    int l,r,tmp;
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&tmp);
        s[i] = s[i - 1] ^ tmp;
        insert(root[i],root[i - 1],K - 1,i);
    }
    for(int i = 1;i <= m;i++){
        scanf("%s",str);
        if(str[0] == 'A'){
            scanf("%d",&tmp);
            n++;
            s[n] = s[n - 1] ^ tmp;
            insert(root[n],root[n - 1],K - 1,n);
        }else{
            scanf("%d %d %d",&l,&r,&tmp);
            printf("%d\n",query(root[r - 1],s[n] ^ tmp,K - 1,l - 1));
        }
    }
}

void insert(int &now,int pre,int bit,int rank){
    if(!now) now = ++tot;
    
    if(bit < 0){
        latest[now] = rank;
        return ;
    }
    int c = s[rank] >> bit & 1;

    trie[now][c ^ 1] = trie[pre][c ^ 1];
    insert(trie[now][c],trie[pre][c],bit - 1,rank);
    
    latest[now] = max(latest[trie[now][0]],latest[trie[now][1]]);
}
int query(int now,int val,int bit,int lim){
    if(bit < 0) return s[latest[now]] ^ val;
    int c = val >> bit & 1;
    if(latest[trie[now][c ^ 1]] >= lim) return query(trie[now][c ^ 1],val,bit - 1,lim);
    else return query(trie[now][c],val,bit - 1,lim);
}

//可持久化01trie树
//异或前缀和的应用

//2021-5-19