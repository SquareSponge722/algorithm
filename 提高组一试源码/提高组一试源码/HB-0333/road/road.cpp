#include<iostream>
#include<string.h>
#include<cstdio>
#include<climits>
#define IN inline
#define re register
using namespace std;
const int N=100005;
int n,a[N],ans;

IN int read()
{
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}
    while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    while(ch>='0'&&ch<='9');
    return f*x;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    for(re int i=1;i<=n;i++)
        a[i]=read();
    int down=0;
    for(re int i=1;i<=n;i++)
    {
        down=min(down,a[i]);
        if(a[i]>=a[i-1]&&a[i]>a[i+1])
            ans+=a[i]-down,down=INT_MAX;
    }
    cout<<ans<<"\n";
    return 0;
}