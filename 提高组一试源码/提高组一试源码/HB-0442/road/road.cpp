#include<iostream>
#include<cstdio>
using namespace std;
int n;
int d[100005];
int ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>d[i];
    ans=d[1];
    for(int i=2;i<=n;i++)
    {
        if(d[i]>d[i-1])ans+=d[i]-d[i-1];
    }
    cout<<ans;
    return 0;
}
