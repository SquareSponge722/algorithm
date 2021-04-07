#include<iostream>
#include<string.h>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<cstdio>
#define IN inline
#define re register
using namespace std;
const int N=105;
int T,n,a[N],b[N];
bool ch[N];
map<int,bool>M;

IN int read()
{
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}
    while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    while(ch>='0'&&ch<='9');
    return f*x;
}

void solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(a[i]%a[j]==0)a[i]=9999999;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(a[i]!=9999999)b[++cnt]=a[i];
    sort(b+1,b+1+cnt);int ans=cnt;
    for(int i=1;i<=cnt;i++)ch[i]=1;
    int MAX=a[1]*a[2]-a[1]-a[2];
    for(int i=cnt;i>=1;i--)
    {
        if(a[i]>MAX)ans--,ch[i]=0;
        else break;
    }
    
    for(int i=0;i<=a[2];i++)
    {
        for(int j=0;j<=a[i];j++)
            M[i*a[1]+j*a[2]]=1;
    }
    for(int i=1;i<=cnt;i++)
    {
        if(!ch[i])continue;
        if(M.count(a[i]))
        {ch[i]=0;ans--;}
    }
    cout<<ans<<"\n";
}

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);    
    T=read();
    while(T--)
    {
        memset(a,0,sizeof(a));
        n=read();
        for(int i=1;i<=n;i++)
            a[i]=read();
        if(n==1){cout<<"1\n";continue;}
        if(n==2)
        {   
            if(a[1]%a[2]==0||a[2]%a[1]==0)
                cout<<"1\n";
            else cout<<"2\n";
            continue;
        }
        solve();
    }
    return 0;
}