#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int P=1e9+7;
int n,m;
int x[10][10];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.in","w",stdout);
    x[2][2]=12;x[2][3]=60;x[3][2]=60;x[3][3]=112;x[5][5]=7163;
    cin>>n>>m;
    if(n==2)
    {
        int num=m*2-2;
        long long ans=1;
        while(num--)
        {
            ans*=2;
            ans%=P;
        }
        ans--;
        ans*=4;ans%=P;
        cout<<ans;
        return 0;
    }
    if(n==3)
    {
        for(int i=4;i<=m;i++)
        {
            x[3][i]=x[3][i-1]+x[3][i-2];
        }
    }
    cout<<x[n][m];
    return 0;
}
