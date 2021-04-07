#include<iostream>
#include<cstdio>
using namespace std;
int d[100000]= {0};
int nn;
long long day=0;
void tc(int l,int r)
{
    if(l>r)return;
    for (int i=l; i<=r; i++)
    {
        if(d[i]==0)
        {
            tc(l,i-1);
            tc(i+1,r);
            return;
        }
    }
    int minn=9999999;
    for(int i=l;i<=r;i++)
        if(d[i]<minn)minn=d[i];
    for(int i=l;i<=r;i++)
        d[i]-=minn;
    day+=minn;
    tc(l,r);
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>d[i];
    tc(1,n);
    cout<<day;
    return 0;
}
