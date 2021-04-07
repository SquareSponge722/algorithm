#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 10001
using namespace std;
int d[MAXN],h,s,e,sum,n;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    h=MAXN;
    for(int i=1; i<=n; i++)
    {
        cin>>d[i];
        h=min(h,d[i]);
    }
    s=1;
    e=n;
    while (1)
    {
        for(int i=s; i<=e; i++)
        {
            d[i]=d[i]-h;
        }
        sum=sum+h;
        h=MAXN;
        s=-1;
        e=-1;
        for(int i=1; i<=n; i++)
        {
            if(d[i]!=0 && d[i+1]==0)
            {
                e=i;
                break;
            }
        }
        for(int i=0; i<=n; i++)
        {
            if(d[i]==0 && d[i+1]!=0)
            {
                s=i+1;
                break;
            }
        }
        if(e==-1 && s==-1)
        {
            break;
        }
        for(int i=s; i<=e; i++)
            h=min(h,d[i]);
    }
    cout<<sum;
    return 0;
}

