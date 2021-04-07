#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[110],i,n,t,l,b,j,k;
long long v,m;
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        l=n;
        for(i=1; i<=n; i++)cin>>a[i];
        sort(a+1,a+n+1);
        ///for(i=1; i<=n; i++)cout<<a[i];
        for(i=2; i<=n; i++)
        {
            b=1;
            for(j=1; j<=i-1; j++)
            {

                for(k=1; k<=j; k++)
                {
                    int t1=a[i],t2=a[j],t3=a[k];
                    if(t1%t3==0 || t1%t2==0)
                    {
                        b=0;
                        break;
                    }
                    if(t2==t3)break;
                    while(t1)
                    {
                        t1-=t2;
                        if(t1%t3==0)
                        {
                            b=0;
                            break;
                        }
                    }
                    if(b==0)break;
                }
                if(b==0)break;
            }
            if(!b)l--;
        }
        cout<<l<<endl;;
    }
    return 0;
}

