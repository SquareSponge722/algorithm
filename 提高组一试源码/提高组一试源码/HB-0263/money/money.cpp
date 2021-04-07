#include<cstdio>
#include<bitset>
using std::bitset;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int a[105],n;
int ppc[1<<13];
namespace _
{
void work()
{
    for(int i=0;i<n;++i)
        a[i]=read();
    if(n==1||a[0]%a[1]==0||a[1]%a[0]==0)
        puts("1");
    else
        puts("2");
    return;
}
}
namespace __
{
bitset<2000> ori;
bitset<2000> now;
bool check(int x)
{
    now.reset();
    now[0]=1;
    for(int i=0;i<n;++i)
        if((x>>i)&1)
        {
            int up=1000/a[i]+1;
            for(int j=1;j<=up;++j)
                now|=now<<a[i];
        }
    for(int i=0;i<1000;++i)
        if(ori[i]!=now[i])
            return false;
    return true;
}
void work()
{
    ori.reset();
    ori[0]=1;
    int ans=n;
    for(int i=0;i<n;++i)
    {
        a[i]=read();
        int up=1000/a[i]+1;
        for(int j=1;j<=up;++j)
            ori|=ori<<a[i];
    }
    for(int i=1;i<(1<<n);++i)
        if(check(i))
            ans=ans<ppc[i]?ans:ppc[i];
    printf("%d\n",ans);
}
}


int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    for(int i=1;i<(1<<13);++i)
        ppc[i]=ppc[i>>1]+(i&1);
    int T;
    T=read();
    while(T--)
    {
        n=read();
        if(n<=2)
            _::work();
        else
            __::work();
    }
    return 0;
}

