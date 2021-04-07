#include <cstdio>
#include <cctype>
#include <set>
const int N=5e4+10;
int head[N],to[N<<1],Next[N<<1],edge[N<<1],cnt;
void add(int u,int v,int w)
{
    to[++cnt]=v,edge[cnt]=w,Next[cnt]=head[u],head[u]=cnt;
}
int n,m,ans;
int read()
{
    int x=0;char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) {x=x*10+c-'0';c=getchar();}
    return x;
}
int dfs(int now,int fa,int len)
{
    std::multiset <int > dis;
    for(int i=head[now];i;i=Next[i])
    {
        int v=to[i];
        if(v==fa) continue;
        int d=edge[i]+dfs(v,now,len);
        if(d>=len) ++ans;
        else dis.insert(d);
    }
    if(dis.empty()) return 0;
    std::set <int>::iterator l=dis.begin();
    std::set <int>::iterator r;
    while(l!=dis.end())
    {
        r=dis.lower_bound(len-*l);
        if(r!=dis.end())
        {
            int dl=*l,dr=*r;
            if(dl==dr)
            {
                int ct=dis.count(dl);
                if(ct>1)
                {
                    ans+=ct>>1;
                    dis.erase(dl);
                    if(ct&1) dis.insert(dl);
                    l=dis.lower_bound(dl);
                }
                else
                    l++;
            }
            else
            {
                dis.erase(dis.find(dl));
                dis.erase(dis.find(dr));
                l=dis.lower_bound(dl);
                ++ans;
            }
        }
        else
            l++;
    }
    if(dis.empty()) return 0;
    else {r=dis.end();r--;return *r;}
}
bool check(int len)
{
    ans=0;
    dfs(1,0,len);
    return ans>=m;
}
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    n=read(),m=read();
    int l=1,r=0;
    for(int u,v,w,i=1;i<n;i++)
    {
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
        r+=w;
    }
    r/=m;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}