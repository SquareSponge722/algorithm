#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=100005;
int n,d[maxn],maxd=0,mind=10000,ans=0;
inline int read()
{
    int x=0,f=1;
    char ch;
    while(ch<'0'||ch>'9')
    {
        ch=getchar();
        if(ch=='-')f=-1;
    }
    while(ch>='0'&&ch<='9')
        x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*f;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    memset(d,0,sizeof(d));
    for(int i=1; i<=n; i++)
    {
        d[i]=read();
        if(d[i]>maxd)maxd=d[i];
        else if(d[i]<mind)mind=d[i];
    }
    for(int i=mind; i<=maxd; i++)
        for(int j=1;j<=n;j++)
            if(d[j]>=i&&d[j-1]<i)ans++;
    cout<<ans<<endl;
    return 0;
}
