#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t,n,sum,ans,tot,x;
const int mm=26000;
int a[1100];
bool c[1100];
int b[110];
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>n;
        ans=n;//直接算他为n
        for(int j=1; j<=1000; j++) c[j]=0;
        for(int j=1; j<=1000; j++) a[j]=0;
        c[0]=1;//初值
        for(int j=1; j<=n; j++) cin>>a[j];
        for(int j=1; j<=n; j++)
        {
            for(int k=a[j]; k<=1000; k++)
            {
                c[k]=c[k-a[j]]||c[k];
            }
        }
        for(int j=0; j<=1000; j++) if(c[j]==1) sum++;
        sort(a+1,a+1+n);
        for(int j=n; j>=2; j--)
        {
            for(int k=j-1; k>=1; k--)
            {
                if(a[j]%a[k]==0) a[j]=0;
            }
        }
        //for(int k=0; k<=1000; k++) cout<<a[k];
        for(int j=1; j<=1000; j++) c[j]=0;
        for(int j=1; j<=n-1; j++)
        {
            if(a[j]==0) x++;
            if(a[j]!=0)
            {
                for(int k=a[j]; k<=1000; k++)
                {
                    c[k]=c[k-a[j]]||c[k];
                }
            }
            tot=0;
             for(int k=0; k<=1000; k++) if(c[k]==1) tot++;
             if(tot==sum)
             {
                 ans=j-x;
                 break;
             }
             // for(int k=0; k<=1000; k++) cout<<c[k]; cout<<endl;
        }
         b[i]=ans;
    }
    for(int i=1;i<=t;i++) cout<<b[i]<<endl;
    return 0;
}
