#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,T,a[101],t,l,ans,minx,k;
bool bb,b[101];
void solve2()
{
    if(a[1]%a[2])printf("2\n");
    else printf("1\n");
}
void solve3()
{
    bool bb=1;
    for(int i=1; i*a[2]<=a[3]&&bb; i++)
        if((a[3]-i*a[2])%a[1]==0)bb=0;
    if(!bb)printf("2\n");
    else printf("3\n");
}
int gcd(int x,int y)
{
    return x?gcd(y%x,x):y;
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        l=0;
        memset(b,0,sizeof(b));
        for(int i=1; i<=n; ++i)scanf("%d",&a[i]),b[i]=1;
        sort(a+1,a+n+1);
        for(int i=n; i>1; --i)
            for(int j=1; j<i; ++j)
                if(a[i]%a[j]==0)b[i]=0;
        for(int i=2; i<=n; ++i)
        {
            t=i;
            while(!b[t-1]&&b[t]&&t>1)
            {
                b[t-1]=1;
                a[t-1]=a[t];
                b[t]=0;
                t--;
            }
        }
        while(b[++l]);
        l--;

        if(l==1)printf("1\n");
        else if(l==2)solve2();
        else if(l==3)solve3();
        else
        {
            for(int i=1; i<l-1; ++i)
                if(b[i])
                    for(int j=i+1; j<l; ++j)
                        if(b[j])
                        {
                            k=gcd(a[i],a[j]);
                            minx=(a[i]/k-1)*(a[j]/k-1);
                            for(int w=j+1; w<=l; ++w)
                                if(b[w]%k==0&&a[w]>=minx)b[w]=0;
                        }
            for(int i=1; i<l-1; ++i)
                if(b[i])
                    for(int j=i+1; j<l; ++j)
                        if(b[j])
                            for(int w=j+1; w<=l; ++w)
                                if(b[w])
                                {
                                    bb=1;
                                    for(int p=1; p*a[j]<=a[w]&&bb; p++)
                                        if((a[w]-p*a[j])%a[i]==0)bb=0;
                                    if(!bb)b[w]=0;
                                }
            ans=0;
            for(int i=1; i<=n; ++i)if(b[i])ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}
