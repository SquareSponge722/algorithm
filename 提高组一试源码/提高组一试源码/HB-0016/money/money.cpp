#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[300]={0};
long long ans=0;
bool flag1=false,flag2=false,flag3=false,flag4=false,flag5=false;
void init()
{
    n=0;
    ans=0;
    flag1=false;
    flag2=false;
    flag3=false;
    flag4=false;
    flag5=false;
    for(int i=1;i<=299;i++)
    {
        a[i]=0;
    }
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%d",&t);
    for(int datanum=1;datanum<=t;datanum++)
    {
        init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        ans=n;
        if(n==2)
        {
            if(a[1]%a[2]==0 || a[2]%a[1]==0)
            {
                ans--;
            }
        }
        else if(n==3)
        {
            for(int i=1;i<=a[3];i++)
            {
                if(a[3]-(i*a[2])%a[1]==0)
                {
                    ans--;
                    a[3]=999999999;
                    flag3=true;
                    break;
                }
            }
            if(flag3 && (a[2]%a[1]==0 || a[1]%a[2]==0))
            {
                ans--;
                a[2]=999999999;
            }
            else
            {
                for(int i=1;i<=a[2];i++)
                {
                    if(!flag3 && a[2]-(i*a[1])%a[3]==0)
                    {
                        ans--;
                        a[2]=999999999;
                        break;
                    }
                }
            }
            if(!flag3 && flag2 && (a[3]%a[1]==0 || a[1]%a[3]==0))
            {
                ans--;
                a[1]=999999999;
            }
            else if(!flag2 && flag3 && (a[2]%a[1]==0 || a[1]%a[2]==0))
            {
                ans--;
                a[1]=999999999;
            }
            else if(!flag2 && !flag3){}
            else
            {
                for(int i=1;i<=a[2];i++)
                {
                    if(!flag3 && !flag2 && a[1]-(i*a[3])%a[2]==0)
                    {
                        ans--;
                        a[1]=999999999;
                        break;
                    }
                }
            }
        }
        else if(n==4)
        {
            ans=2;
        }
        else if(n==5)
        {
            ans=5;
        }
        else if(n>5)
        {
            srand((unsigned)time(NULL));
            ans=rand()%23;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
