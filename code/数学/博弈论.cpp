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

const int N = 5001;

int t,n,m;
bool win[N][N];

int main(){
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            if(!win[i][j]){
                for(int k = 1;i + k < N;k++)
                    for(int s = 0;j + s * k < N;s++)
                        win[i + k][j + s * k] = 1;
                for(int k = 1;j + k < N;k++)
                    for(int s = 0;i + s * k < N;s++)
                        win[i + s * k][j + k] = 1;
            }

    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        if(win[n][m]) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}

//当前状态能走到必败态说明现在是必胜态，如果没有必败态说明此时必败

//显然win[0][0]是必败态，那么所有可以转移到win[0][0]的状态都是必胜态
//当前为win[i][j]时，则 i j 前所有状态都进行过状态转移
//若win[i][j] 为 0 ，则表明 i j 前所有必败态都无法转移至 i j
//故 i j 为必败态

//https://ac.nowcoder.com/acm/contest/11166/A
//2021-7-18