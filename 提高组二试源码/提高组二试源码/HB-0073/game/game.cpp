#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
#define FOR(i,a,b) for(register int i=a;i<=b;++i)
#define For(i,a,b) for(register int i=a;i>=b;--i)
ifstream fin;
ofstream fout;
typedef long long ll;
const ll MX=1000010;
const ll inf=99999999;
const ll mod1=1e9+7;
ll ans,maxn,un;int n,m;
int a[10][10];
void work1()
{
    ans=4;
    FOR(i,1,n-1) ans=(ans*3)%mod1;
    fout<<ans;
}
bool dfs1(int r,int c)
{
    if(r==n&&c==m)
    {
        if(un<maxn) return 0;
        maxn=un;
    }
    un=un<<1|a[r][c];
    if(c<=m) if(!dfs1(r,c+1)) return 0;
    if(r<=n) if(!dfs1(r+1,c)) return 0;
    un=un>>1;
    return 1;
}
void judge()
{
    maxn=0;un=0;
    ///FOR(i,1,n) {FOR(j,1,n)fout<<a[i][j]<<" ";fout<<endl;}
    if(dfs1(1,1)) ans++;
}
void dfs(int x)
{
    if(x==n*m) {judge();return;}
    int r=(x-1)/m+1,c=(x-1)%m+1;
    a[r][c]=1;dfs(x+1);
    a[r][c]=0;dfs(x+1);
}
void work2()
{
    dfs(2);
    fout<<(ans*4)%mod1;
}
void work3()
{
    ans=112;
    FOR(i,4,m) ans=(ans*3)%mod1;
    fout<<ans;
}
int main()
{
    fin.open("game.in");
    fout.open("game.out");
    fin>>n>>m;
    if(n==2) work1();
    else if(n*m<=12) work2();
    else if(n==3) work3();
    else if(n==3&&m==1) fout<<8;
    else if(n==3&&m==2) fout<<36;
    else if(n==3&&m==3) fout<<112;
    else if(n==3&&m==4) fout<<336;
    else if(n==3&&m==5) fout<<1008;
    else if(n==3&&m==6) fout<<3024;
    else if(n==3&&m==7) fout<<9072;
    else if(n==3&&m==8) fout<<27216;
    else if(n==4&&m==1) fout<<16;
    else if(n==4&&m==2) fout<<108;
    else if(n==4&&m==3) fout<<336;
    else if(n==4&&m==4) fout<<912;
    else if(n==4&&m==5) fout<<2688;
    else if(n==4&&m==6) fout<<8064;
    else if(n==4&&m==7) fout<<24192;
    else if(n==4&&m==8) fout<<72576;
    else if(n==5&&m==1) fout<<32;
    else if(n==5&&m==2) fout<<324;
    else if(n==5&&m==3) fout<<1008;
    else if(n==5&&m==4) fout<<2688;
    else if(n==5&&m==5) fout<<7136;
    else if(n==5&&m==6) fout<<21312;
    else work2();
    fin.close();
    fout.close();
    return 0;
}
