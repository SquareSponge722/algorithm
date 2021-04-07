#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
int a[100010];
int x=10001;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdin);
    cin>>n;
    for(int i=0; i<=n-1; i++)
    {
        cin>>a[i];
        if(a[i]<x) x=a[i];
    }
    for(int i=n; i<=100010; i++)
        a[i]=0;
    for(int i=1; i<=x; i++)
    {
        for(int j=0; j<=n-1; j++)
            a[j]--;
        ans++;
    }
    for(int t=0; t<=10001; t++)
    {
        for(int i=0; i<=n-1; i++)
        {
            if(a[i]==0&&a[i-1]>0)
            {
                for(int j=0; j<=i-1; j++)
                    a[j]--;
                ans++;
            }
            else if(a[i]==0&&a[i+1]>0)
            {
                for(int j=i+1; j<=n; j++)
                    if(a[j]==0)
                    {
                        for(int k=i+1; k<=j-1; k++)
                            a[k]--;
                        ans++;
                    }
            }
        }
    }
    cout<<ans;
    return 0;
}
