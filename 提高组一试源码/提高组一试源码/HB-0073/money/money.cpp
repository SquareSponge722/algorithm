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
const int MX=110;
const int inf=99999999;
ll a[MX],t,maxn,n;
bool b[MX],bs[25010];
bool flag;
void work1()
{
    if(a[1]<a[2]) swap(a[1],a[2]);
    if(a[1]%a[2]==0) fout<<1;
    else fout<<2;
}
void work2()
{
    sort(a+1,a+n+1);
    ///FOR(i,1,n) fout<<a[i]<<" ";fout<<endl;
    ll tt=maxn/a[1],t1,t2,ans=1;
    FOR(i,0,tt) bs[a[1]*i]=1;
    FOR(i,2,n)
    {
        if(bs[a[i]]) continue;
        else
        {
            ans++;
            t1=maxn/a[i];
            FOR(j,1,maxn) if(bs[j])
            {
                FOR(k1,1,t1)
                {
                    t2=(maxn-k1*a[i])/j;
                    FOR(k2,0,t2) bs[a[i]*k1+j*k2]=1;
                }
            }
            ///fout<<i<<endl;fout<<endl;
            ///FOR(i,1,maxn) fout<<bs[i]<<" ";fout<<endl;
        }
    }
    fout<<ans;
}
int main()
{
    fin.open("money.in");
    fout.open("money.out");
    fin>>t;while(t--)
    {
        fin>>n;flag=0;maxn=0;
        FOR(i,1,n)
        {
            fin>>a[i];
            if(a[i]==1) flag=1;
            maxn=max(a[i],maxn);
        }
        if(n==1||flag) fout<<1;
        else if(n==2) work1();
        else
        {
            memset(b,0,sizeof(b));
            memset(bs,0,sizeof(bs));
            work2();
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
