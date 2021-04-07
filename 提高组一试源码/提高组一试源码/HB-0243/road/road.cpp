#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int mm=100010;
int n;
int d[mm];
int ans;
//int minn=100000;
int solve(int l,int r)
{
    int sans=0;
    int minn=100100;
    int ll=l;
    if(l>r)return 0;
    if(l==r)return d[l];
    for(int i=l;i<=r;i++)
    {
        minn=min(d[i],minn);
    }
    sans+=minn;
    //cout<<minn<<endl;
    for(int i=l;i<=r;i++)
    {
        d[i]-=minn;
        if(d[i]==0)
        {
            sans+=solve(ll,i-1);
            ll=i+1;
        }

        //for(int j=l;j<=r;j++)cout<<d[j]<<' ';
        //cout<<endl;
        //cout<<"("<<l<<','<<r<<")"<<"   "<<sans<<endl;
    }
    if(d[r]!=0)sans+=solve(ll,r);
    return sans;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
    }
    ans=solve(1,n);
    cout<<ans;
    return 0;
}
