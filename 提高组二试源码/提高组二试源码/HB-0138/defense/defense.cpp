#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
using namespace std;
typedef long long LL;
const LL MAXN=1e5+5;
LL n,m,type2,p[MAXN];
LL cnt,top[MAXN],to[MAXN<<1],nex[MAXN<<1];
char type1;
inline LL read()
{
    LL re=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) re=(re<<3)+(re<<1)+ch-'0',ch=getchar();
    return re;
}
inline char readc()
{
    char ch=getchar();
    while(!isalpha(ch)) ch=getchar();
    return ch;
}
namespace SP1
{
    LL cost[2005];
    bool vis[15];
    bool judge(LL now)
    {
        for(LL i=0;i<n;i++)
            if(now&(1<<i)) vis[i+1]=true;
            else vis[i+1]=false;
        for(LL i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            bool flag=false;
            for(LL j=top[i];j;j=nex[j])
                if(vis[to[j]])
                {
                    flag=true;
                    break;
                }
            if(!flag) return false;
        }
        return true;
    }
    void mian()
    {
        for(LL i=0;i<(1<<n);i++)
            for(LL j=0;j<n;j++)
                if(i&(1<<j)) cost[i]+=p[j+1];
        for(LL i=0;i<(1<<n);i++) if(!judge(i)) cost[i]=LLONG_MAX;
        while(m--)
        {
            LL x=1<<(read()-1),xx=read(),y=1<<(read()-1),yy=read(),ans=LLONG_MAX;
            if(!xx&&!yy)
            {
                for(LL i=0;i<(1<<n);i++)
                {
                    if((i&x)||(i&y)) continue;
                    ans=min(ans,cost[i]);
                }
            }
            else if(!xx&&yy)
            {
                for(LL i=0;i<(1<<n);i++)
                {
                    if((i&x)||!(i&y)) continue;
                    ans=min(ans,cost[i]);
                }
            }
            else if(xx&&!yy)
            {
                for(LL i=0;i<(1<<n);i++)
                {
                    if(!(i&x)||(i&y)) continue;
                    ans=min(ans,cost[i]);
                }
            }
            else if(xx&&yy)
            {
                for(LL i=0;i<(1<<n);i++)
                {
                    if(!(i&x)||!(i&y)) continue;
                    ans=min(ans,cost[i]);
                }
            }
            printf("%lld\n",ans==LLONG_MAX?-1:ans);
        }
    }
}
int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    n=read(),m=read(),type1=readc(),type2=read();
    for(LL i=1;i<=n;i++) p[i]=read();
    for(LL i=1;i<n;i++)
    {
        LL x=read(),y=read();
        to[++cnt]=y,nex[cnt]=top[x],top[x]=cnt;
        to[++cnt]=x,nex[cnt]=top[y],top[y]=cnt;
    }
    if(n<=10&&m<=10) SP1::mian();
    return 0;
}
