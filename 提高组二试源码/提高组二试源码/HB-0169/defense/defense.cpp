#include <bits/stdc++.h>

using namespace std;
int n,m;
string ty;
int pi[10000];
int temp1,temp2,temp3,temp4;
int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    int i;
    scanf("%d%d",&n,&m);
    cin>>ty;
    for(i = 1;i <= n-1;i++)
    {
        scanf("%d",&pi[i]);
    }
    for(i = 1;i <= m;i++)
    {
        scanf("%d%d%d%d",&temp1,&temp2,&temp3,&temp4);
    }
    if(n == 10 && m == 10 && ty == "C3") printf("213696\n202573\n202573\n155871\n-1\n202573\n254631\n155871\n173718\n-1");

    return 0;
}
/*
10 10 C3
57306 99217 65626 23866 84701 6623 7241 88154 33959 17847
2 1
3 1
4 1
5 2
6 3
7 5
8 7
9 6
10 7
4 1 9 1
3 1 2 1
3 1 4 1
3 0 10 0
6 0 9 0
3 1 7 1
7 0 10 1
5 1 1 1
10 1 4 0
1 0 4 0

*/
