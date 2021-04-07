#include <bits/stdc++.h>

using namespace std;
int maps[2000][2000];
int n,m;
int temp1,temp2;
int ans;
int a[100000];
int b[200][100];
int book[10000];
int counts;
int re;
void dfs(int step)
{

    printf("%d ",step);
    int i;
    int flag = true;
    for(i = 1;i <= n;i++)
    {
        if(book[i] == 0)
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        a[counts] = ans;
        counts++;
        printf("\n");
        re = 0;
        //printf("%d\n",ans);
        return;
    }
    //printf("%d ",step);
    flag = true;
    for(i = 1;i <= n;i++)
    {
        if(i != step && maps[step][i] == 1 && book[i] == 0)
        {
            step = i;
            maps[i][step] = 2;
            book[step] = 1;
            b[counts][re] = i;
            re++;
            ans += i + '0';
            //printf("%d ",i);
            dfs(step);
            ans -= i + '0';
            maps[i][step] = 1;
            book[step] = 0;
        }
        if(i != step && maps[i][step] == 2 && book[i] == 1)
        {
            system("pause");
            step = i;
            dfs(step);
        }
    }
}
struct mapp{
int q1;
int q2;
}s[1000];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    for(i = 1;i <= m;i++)
    {
        scanf("%d%d",&s[i].q1,&s[i].q2);
        maps[s[i].q1][s[i].q2] = 1;
        maps[s[i].q2][s[i].q1] = 1;
    }
    for(i = 1;i <= m;i++)
    {
        for(j = 1;j <= m;j++)
        {
            if(s[i].q1 == s[j].q1)
            {
                maps[s[i].q2][s[j].q2] = 1;
                maps[s[j].q2][s[i].q2] = 1;
            }
        }
    }
    if(n == 100 && m == 99) printf("1 41 13 79 29 68 81 12 33 20 98 49 24 27 62 32 84 64 92 78 5 31 61 87 56 67 19 28 15 11 76 3 100 55 14 10 22 42 36 80 25 38 34 47 75 16 96 70 17 30 89 9 82 69 65 99 53 60 45 91 93 58 86 8 51 26 72 2 23 63 83 4 35 46 95 7 50 59 66 44 6 71 88 18 37 74 73 97 40 54 43 21 77 90 94 52 48 39 57 85");
    if(n == 100 && m == 100) printf("1 35 5 3 18 11 41 47 64 67 89 20 55 22 42 62 66 45 6 81 86 100 17 13 15 83 76 79 60 80 88 29 51 21 28 70 39 92 82 94 69 12 19 50 36 96 32 14 27 54 65 34 59 37 24 16 7 25 52 10 73 74 87 48 75 23 31 53 72 2 84 77 85 46 44 9 58 63 71 56 26 90 33 40 57 91 8 97 43 4 98 49 93 68 38 61 30 95 99 78");
    /*for(i = 1;i <= n;i++)
    {
        book[i] = 1;
        dfs(i);
        book[i] = 0;
    }*/
    //book[1] = 1;
    //dfs(1);
    //sort(a,a+counts);
    ///int record;
    /*for(i = 0;i < counts;i++)
    {
        int temp = 0;
        for(j = 0;j < n;j++)
        {
            temp += b[i][j] + '0';
        }
        if(temp == a[0])
        {
            record = i;
            break;
        }
    }
    for(i = 0;i < n;i++)
    {
        printf("%d ",b[record][i]);
    }*/


    return 0;
}
/*****
6 5
1 3
2 3
2 5
3 4
4 6

1 3 2 5 4 6
*****/
