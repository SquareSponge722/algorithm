#include<bits/stdc++.h>
const int maxn=1e5+10;
using namespace std;

int n,a[maxn];
int ans;

inline int read()
{
    int tmp=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) tmp=(tmp<<1)+(tmp<<3)+ch-'0',ch=getchar();
    return tmp;
}

void work(int l,int r)
{
    if(l>r) return;
    if(l==r)
    {
        ans+=a[l],a[l]=0;
        return;
    }
    int mi=INT_MAX,now=l;
    for(int i=l;i<=r;i++) mi=min(mi,a[i]);
    ans+=mi;
    for(int i=l;i<=r;i++)
    {
        a[i]-=mi;
        if(!a[i]) work(now,i-1),now=i+1;
        if(a[i] && i==r) work(now,i);
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    work(1,n);
    printf("%d",ans);
    return 0;
}
