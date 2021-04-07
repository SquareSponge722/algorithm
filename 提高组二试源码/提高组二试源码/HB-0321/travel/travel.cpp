#include<iostream>
#include<cstdio>
using namespace std;
int n,m,i,a[5050],b[5050],tt,t[5050];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(i=1; i<=m; i++)
    {
        cin>>a[i]>>b[i];
        t[a[i]]++,t[b[i]]++;
    }
    ///for(i=1;i<=n;i++)cout<<t[i]<<' ';
    ///cout<<endl;
    if(m==n-1)
    {
        cout<<1<<' ';
        t[1]=0;
        for(i=1; i<=m; i++)
        {
            if(1==a[i]) tt=b[i];
            if(1==b[i])tt=a[i];

        }


        int mm=n-1;
        ///cout<<endl;
        while(mm--)
        {
            cout<<tt<<' ';
            t[tt]=0;
            int ttt=tt;
            for(i=1; i<=m; i++)
            {

                if(a[i]==ttt && t[b[i]])
                {
                    ttt=b[i];
                    break;
                    ///cout<<a[i]<<' '<<b[i]<<endl;
                }
                if(b[i]==ttt && t[a[i]])
                {
                    ttt=a[i];
                    break;
                    ///cout<<b[i]<<' '<<a[i]<<endl;
                }

            }
            tt=ttt;
            ///for(i=1;i<=n;i++)cout<<t[i]<<' ';
            ///cout<<endl;
        }
    }
    if(m==n)
    {
        cout<<1<<' ';
        t[1]=0;
        int mi=m+1;
        for(i=1; i<=m; i++)
        {
            if(1==a[i] && mi>b[i]) mi=b[i];
            if(1==b[i] && mi>a[i]) mi=a[i];

        }
        tt=mi;
        int mm=n-1;
        while(mm--)
        {
            cout<<tt<<' ';
            t[tt]=0;
            int ttt=tt;
            for(i=1; i<=m; i++)
            {

                if(a[i]==ttt && t[b[i]])
                {
                    ttt=b[i];
                    break;
                   /// cout<<a[i]<<' '<<b[i]<<endl;
                }
                if(b[i]==ttt && t[a[i]])
                {
                    ttt=a[i];
                    break;
                    ///cout<<b[i]<<' '<<a[i]<<endl;
                }

            }
            tt=ttt;
            ///for(i=1;i<=n;i++)cout<<t[i]<<' ';
            ///cout<<endl;
        }
    }
    return 0;
}
/*
4 3
1 3
3 4
2 4
*/
/*
3 3
1 3
2 3
2 1
*/
