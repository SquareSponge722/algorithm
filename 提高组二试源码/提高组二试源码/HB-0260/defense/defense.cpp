#include<iostream>
#include<cstdio>
using namespace std;
const int mx=10000;
int cnt,pp[mx],p[mx];
int n,m;
int r;
int ans;
int main()
{

    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    string c;
    cin>>n>>r>>c;
    for(int i=1; i<=n; i++)
    {
        cin>>p[i];
    }

    for(int i=1; i<=n-1; i++)
    {
        int a,b;
        cin>>a>>b;
    }
    for(int i=1; i<=r; i++)
    {
        int a,x,b,y;
        cin>>a>>x>>b>>y;
        if(a>b)swap(a,b),swap(x,y);

        if(x==y==0&&a+1==b)
        {
            cout<<-1<<endl;
            continue;
        }
       if(x==0)
        {
            for(int i=a-1; i>=1; i-=2)
            {
                ans+=p[i];
            }
        }
        if(x==1)
        {
            for(int i=a; i>=1; i-=2)
            {
                ans+=p[i];
            }
        }
        if(y==0)
        {
            for(int i=b+1; i<=n; i+=2)
                ans+=p[i];
        }
        if(y==1)
        {
            for(int i=b; i<=n; i+=2)
                ans+=p[i];
        }
        if(x==1&&y==0)
        {
            for(int i=a+2; i<=b-1; i+=2)
                ans+=p[i];
        }
        if(x==0&&y==1)
        {
            for(int i=b-1; i>=a+1; i-=2)
            {
                ans+=p[i];
            }
        }
        if(x==0&&y==0)
        {
            for(int i=a+1;i<=b-1;i+=2)
                ans+=p[i];
        }
        if(ans==0)cout<<-1<<endl;
        else cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
