#include<bits/stdc++.h>
const int maxn=110;
const int maxw=25010;
using namespace std;

int T;
int n,a[maxn];
int mx,ans;
bool f[maxw];

void init()
{
    ans=0;
    memset(f,false,sizeof(f));
}

inline int read()
{
    int tmp=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) tmp=(tmp<<1)+(tmp<<3)+ch-'0',ch=getchar();
    return tmp;
}

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    T=read();
    for(int t=1;t<=T;t++)
    {
        init();
        n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        sort(a+1,a+n+1);mx=a[n];
        f[0]=true;
        for(int i=1;i<=n;i++)
        {
            if(f[a[i]]) continue;
            ans++;
            for(int j=a[i];j<=mx;j++)
            if(f[j-a[i]]) f[j]=true;
        }
        printf("%d\n",ans);
    }
    return 0;
}
