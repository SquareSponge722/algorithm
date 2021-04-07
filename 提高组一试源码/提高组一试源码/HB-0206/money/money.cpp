#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,a[105],ans;
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
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int t=read();
    while(t--)
    {
        ans=0;
        n=read();
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            a[i]=read();
        if(n==1)cout<<1<<endl;
        else if(n==2)
        {
            if(a[2]%a[1]==0||a[1]%a[2]==0)cout<<1<<endl;
            else cout<<2<<endl;
            continue;
        }
        sort(a+1,a+n+1);
        int tmp,nex;
        for(int i=1;i<=n;i++)
            if(a[i]%a[1]!=0)
        {
            nex=a[i];
            tmp=a[1]*a[i]-a[1]-a[i];
            break;
        }
        for(int i=2;i<=n;i++)
            if(a[i]>=tmp&&a[i]!=nex)a[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)continue;
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]==0)continue;
                else if(a[j]%a[i]==0)a[j]=0;
            }
        }
        for(int i=1;i<=n;i++)if(a[i]!=0)ans++;
        cout<<ans<<endl;
    }
    return 0;
}
