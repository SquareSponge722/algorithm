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

int n,k;
string str;

int main(){
    cin >> n >> k;
    cin >> str;
    str = str + str;
    n += n;

    vector <int> z(n);
    for(int i = 1,l = 0,r = 0;i < n;i++){
        if(i <= r) z[i] = min(z[i - l],r - i + 1);
        while(i + z[i] < n && str[z[i]] == str[z[i] + i]) ++z[i];
        if(i + z[i] - 1 > r){
            r = i + z[i] - 1;
            l = i;
        }
    }

    int len = n;
    for(int i = 1;i < n;i++){
        if(i + z[i] < n && str[i + z[i]] > str[z[i]]){
            len = i;
            break;
        }
    }

    for(int i = 0;i < k;i++) putchar(str[i % len]);
    printf("\n");

    return 0;
}

//Z函数 Z[i] 表示 字符串str 从0 与 从i 开始的最大相同前缀的长度
//如果 Z[i] >= i 那么 str[i...i + Z[i] - 1] 为 str[0...i - 1] 的重复串

//http://codeforces.com/contest/1537/problem/E2
//2021-6-20