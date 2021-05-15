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

const int N = 26;

struct tire{
    tire* next[N];
    int id,cnt;
    tire(){
        memset(next,0,sizeof(next));
        cnt = 0;
        id = -1;
    }
}root;

int p,q;
char str[N];

void insert(tire*,const char*,int,int);
int search(const tire*,const char*);

int main(){
    int len;
    scanf("%d",&p);
    while(p--){
        scanf("%s",str);
        len = strlen(str);
        for(int i = 0;i < len;i++) insert(&root,str,i,p);
    }
    scanf("%d",&q);
    while(q--){
        scanf("%s",str);
        printf("%d\n",search(&root,str));
    }
    return 0;
}

void insert(tire* pre,const char* s,int st,int id){
    for(int i = st;s[i] != '\0';i++){
        int index = s[i] - 'a';
        if(pre->next[index] == NULL) pre->next[index] = new tire();
        pre = pre->next[index];
        if(pre->id != id){ //去重
            pre->id = id;
            pre->cnt++;
        }
    }
}
int search(const tire* pre,const char* s){
    for(int i = 0;s[i] != '\0';i++){
        int index = s[i] - 'a';
        if(pre->next[index] == NULL) return 0;
        pre = pre->next[index];
    }
    return pre->cnt;
}

//hdu 2846 Repository
//2021-5-8