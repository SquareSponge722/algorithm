#include<bits/stdc++.h>
using namespace std;
int t,n,t1,t2;
int a[1000];
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int ans=0;
        cin>>n;
       /* for(int k=0; k<=n; k++)
            for(int h=0; h<=99999; h++)
            {
                f[k][h]=0;
                f[k][0]=1;
            }*/
        for(int j=1; j<=n; j++)
        {
            cin>>a[j];
            if(a[j]==1)
            {
                cout<<1;
                return 0;
            }
        }
        /*for(int k=1; k<=n; k++)
        {
            for(int h=1; h<=99999; h++)
            {
                for(int m=0; m<=99; m++)
                {
                    t2=f[k-1][h-a[k]*m];
                    if(t2==1)break;
                }
                f[k][h]=t2;
            }
        }
        for(int q=1; q<=2; q++)
            for(int s=1; s<=50; s++)
            }*/
        sort(a+1,a+n+1);
        for(int h=1; h<n; h++)
        {
        	if(a[h]==0)continue;
            for(int m=h+1; m<=n; m++)
            {
            	if(a[m]==0)continue;
                if(a[m]%a[h]==0)a[m]=0;
                for(int p=m+1; p<=n; p++)
                {
                    if(a[p]=a[m]+a[h])a[p]=0;
                }
            }
        }
        for(int k=1; k<=n; k++)
        {
            if(a[k]!=0)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
2
4
3 19 10 6
5
11 29 13 19 17

*/
