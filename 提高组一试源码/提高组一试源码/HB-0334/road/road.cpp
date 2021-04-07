//#define Debug
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
#ifndef Debug
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
#endif
    long long n,l;
    long long d[100005];
    long long dmin=9999999;
    long long i;
    long long res=0;
    scanf("%lld",&n);
    l=0;
    for(i=1; i<=n; i++)
        scanf("%lld",&d[i]);
    for(i=1; i<=n; i++)
    {
        dmin=min(dmin,d[i]);
    }
    for(i=1; i<=n; i++)
    {
        d[i]-=dmin;
    }
    res+=dmin;
    while(1)
    {
        for(i=1; i<=n; i++)
        {
            if(l==0&&i!=n&&d[i]==0) continue;
            else if(l!=0&&d[i]==0)
            {
                break;
            }
            else if(d[i]!=0)
            {
                l++;
                d[i]--;
            }
            else if(l==0&&d[n]==0)
            {
                //cout<<dmin<<endl;
                cout<<res;
                return 0;
            }
        }
        res++;
        //cout<<res;
        l=0;
        //for(i=1;i<=n;i++) cout<<d[i];
        //cout<<endl;
    }
}
