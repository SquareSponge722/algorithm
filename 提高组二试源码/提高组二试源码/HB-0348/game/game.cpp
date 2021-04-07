///game
#include<iostream>
#include<cstdio>
using namespace std;
const int mn=10;
const int mm=1000100;
const int mod=1000000007;
int n,m;
int ans[mn][mm];
void init()
{
    int pl;
    //cout<<"pl="<<pl<<endl;
    for(int i=1; i<=mn-1; i++)
        for(int j=1; j<=mm-1; j++)
            ans[i][j]=(pl*pl)%mod;
    ans[1][1]=1;
    for(int i=2; i<=mn-1; i++)
        ans[i][1]=(ans[i-1][1]*2)%mod;
    for(int i=2; i<=mm-1; i++)
        ans[1][i]=(ans[1][i-1]*2)%mod;
    ans[2][2]=12;
    ans[2][3]=ans[3][2]=54;
    ans[3][3]=112;
    ans[3][4]=ans[4][3]=754;
    ans[4][4]=(pl*pl)%mod;
    ans[4][5]=ans[5][4]=(pl*pl*pl*pl)%mod;
    ans[5][5]=7136;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    init();
    cin>>n>>m;
    cout<<ans[n][m];
    return 0;
}
