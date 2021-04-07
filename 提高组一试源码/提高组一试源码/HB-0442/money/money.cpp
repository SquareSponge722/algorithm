#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mn=25005;
int t;
int n,a[mn];
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);
        if(n==2)
        {
            if(a[2]%a[1]==0)cout<<1<<endl;
            else cout<<2<<endl;
        }
        if(n==3)
        {
            if(a[3]%a[1]==0&&a[2]%a[1]==0)cout<<1<<endl;
            else if(a[3]%a[1]==0||a[3]%a[2]==0||a[2]%a[1]==0)
                cout<<2<<endl;
            else if(a[3]%a[1]!=0||a[3]%a[2]!=0||a[2]%a[1]!=0)
            {
                if(a[1]+1==a[2]&&a[1]+2==a[3])cout<<3<<endl;
                else if((a[3]-a[2])>=a[1]&&(a[3]-a[2])%a[1]==0)cout<<2<<endl;
                else if(a[3]>=(a[1]+a[2])&&a[3]%(a[1]+a[2]==0))cout<<2<<endl;
                else if((a[3]-a[1])>=a[2]&&(a[3]-a[1])%a[2]==0)cout<<2<<endl;
                else cout<<3<<endl;
            }
        }
    }
    return 0;
}
