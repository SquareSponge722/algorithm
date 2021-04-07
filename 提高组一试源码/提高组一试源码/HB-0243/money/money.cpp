#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}
const int nn=150;
int t;
int n;
int a[nn];
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; i++)cin>>a[i];
        if(n==2)
        {
            int lit=min(a[1],a[2]);
            int big=max(a[1],a[2]);
            //int temp=a[1]*a[2]-a[1]-a[2]+1;
            if(big%lit==0)cout<<1<<endl;
            else cout<<2;
        }
        else if(n==3)
        {
            int ans=n;
            sort(a+1,a+n+1);
            //for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
            int temp=a[1];
            for(int i=2; i<=n; i++)
            {
                if(a[i]==0)continue;
                if(a[i]%temp==0)
                {
                    a[i]=0;
                    ans--;
                }
            }
            int gcd12=0;
            //while(gcd12!=1)
            //cout<<ans<<endl;
            if(ans!=1)
                for(int i=1; i<=n; i++)
                {

                    int temp2=0;
                    if(a[i]!=0)
                    {
                        temp2=a[i];
                        gcd12=gcd(temp,temp2);
                        for(int j=i+1; j<=n; j++)
                        {
                            if(a[j]%gcd12==0&&a[j]!=0)
                            {
                                int tt=a[j]/gcd12;
                                if(temp*temp2/gcd12/gcd12-temp/gcd12-temp2/gcd12<tt)
                                {
                                    a[j]=0;
                                    ans--;
                                }

                            }
                        }
                        if(gcd12==1)break;
                    }
                }
            cout<<ans<<endl;
        }
        else
        {
            int ans=n;
            sort(a+1,a+n+1);
            //for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
            int temp=a[1];
            for(int i=2; i<=n; i++)
            {
                if(a[i]==0)continue;
                if(a[i]%temp==0)
                {
                    a[i]=0;
                    ans--;
                }
            }
            int gcd12=0;
            //while(gcd12!=1)
            //cout<<ans<<endl;
            if(ans!=1)
                for(int j=1; j<=3; j++)
                for(int i=1; i<=n; i++)
                {

                    int temp2=0;
                    if(a[i]!=0)
                    {
                        temp2=a[i];
                        a[i]=0;
                        gcd12=gcd(temp,temp2);
                        for(int j=i+1; j<=n; j++)
                        {
                            if(a[j]%gcd12==0&&a[j]!=0)
                            {
                                int tt=a[j]/gcd12;
                                if(temp*temp2/gcd12/gcd12-temp/gcd12-temp2/gcd12<tt)
                                {
                                    a[j]=0;
                                    ans--;
                                }

                            }
                        }
                        if(gcd12==1)break;
                    }
                }
            cout<<ans<<endl;
        }

    }

    return 0;
}
