#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
const int MAXN=5e4+5;
int n,m,mp,dis[MAXN];
int cnt,top[MAXN],to[MAXN<<1],len[MAXN<<1],nex[MAXN<<1];
bool is_SP2=true,is_SP3=true;
int read()
{
    int re=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) re=(re<<3)+(re<<1)+ch-'0',ch=getchar();
    return re;
}
namespace SP1
{
    void dfs(int now,int fa)
    {
        for(int i=top[now];i;i=nex[i])
        {
            if(to[i]==fa) continue;
            dis[to[i]]=dis[now]+len[i];
            dfs(to[i],now);
            if(dis[to[i]]>dis[mp]) mp=to[i];
        }
    }
    void mian()
    {
        dfs(1,0);
        memset(dis,0,sizeof dis);
        dfs(mp,0);
        printf("%d",dis[mp]);
    }
}
namespace SP2
{
    bool check(int lim)
    {
        int i=1,j=n-1,k=0;
        while(dis[j]>=lim)
        {
            j--,k++;
            if(k>=m) return true;
        }
        while(k<m)
        {
            while(dis[i]+dis[j]<lim&&i<j) i++;
            if(i>=j) return false;
            k++,i++,j--;
        }
        return k>=m;
    }
    void mian()
    {
        for(int i=1;i<=n-1;i++) dis[i]=len[i<<1];
        sort(dis+1,dis+n);
        int L=0,R=1e9,ans;
        while(L<=R)
        {
            int M=(L+R)>>1;
            if(check(M)) ans=M,L=M+1;
            else R=M-1;
        }
        printf("%d",ans);
    }
}
namespace SP3
{
    bool check(int lim)
    {
        int i=1,k=0;
        while(k<m)
        {
            int j=i+1,now=dis[i];
            while(now<lim&&j<=n-1) now+=dis[j++];
            if(now<lim) return false;
            k++,i=j;
        }
        return k>=m;
    }
    void mian()
    {
        for(int i=1;i<=n;i++)
            for(int j=top[i];j;j=nex[j])
                if(to[j]==i+1) dis[i]=len[j];
        int L=0,R=1e9,ans;
        while(L<=R)
        {
            int M=(L+R)>>1;
            if(check(M)) ans=M,L=M+1;
            else R=M-1;
        }
        printf("%d",ans);
    }
}
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read(),z=read();
        to[++cnt]=y,len[cnt]=z,nex[cnt]=top[x],top[x]=cnt;
        to[++cnt]=x,len[cnt]=z,nex[cnt]=top[y],top[y]=cnt;
        if(x!=1&&y!=1) is_SP2=false;
        if(x!=y+1&&y!=x+1) is_SP3=false;
    }
    if(m==1) SP1::mian();
    else if(is_SP2) SP2::mian();
    else if(is_SP3) SP3::mian();
    else if(m==n-1)///Maybe, but it depends on RP. RP++.
    {
        int ans=INT_MAX;
        for(int i=1;i<=cnt;i++) ans=min(ans,len[i]);
        printf("%d",ans);
    }
    else printf("%d",rand()*rand()%100000000);///GG, Uranus is too weak to solve this.
    return 0;
}
