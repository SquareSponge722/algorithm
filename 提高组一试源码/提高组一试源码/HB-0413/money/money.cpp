#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[110];
int k[110];
int m,cnt;
bool cancalc[1500],canuse[110];
int gcd(int k1,int k2)
{
    if(k1%k2==0)return k2;
    else return gcd(k2,k1%k2);
}
void calc(int counting,int x)
{
    if(x>=1001)return ;
    cancalc[x]=true;
    if(counting==cnt+1)return ;
    ///cout<<a[k[counting]]<<endl;
    ///system("pause");
    for(int j=0; j<=1100/a[k[counting]]; j++)
    {
        calc(counting+1,x+j*a[k[counting]]);
    }
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>t;
    for(int ii=1; ii<=t; ii++)
    {
        memset(a,0,sizeof(a));
        memset(canuse,true,sizeof(canuse));
        m=0;
        cin>>n;
        for(int i=1; i<=n; i++)cin>>a[i];
        sort(a+1,a+n+1);
        ///for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
        if(a[1]==1)cout<<1;
        else
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=i-1; j++)
                {
                    if(gcd(a[i],a[j])==a[j])canuse[i]=false;
                }
            }
            ///for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
            for(int i=1; i<=n; i++)
            {
                if(canuse[i]==true){m++;k[m]=i;}
            }
            ///for(int i=1;i<=m;i++)cout<<a[k[i]]<<endl;
            if(m==1)cout<<1;
            else
            {
                cnt=0;
                bool flag=true;
                do
                {   cnt++;
                    memset(cancalc,0,sizeof(cancalc));
                    calc(1,0);
                    ///system("pause");
                    ///for(int z=1;z<=1200;z++){if(cancalc[z]==true)cout<<1;else cout<<0;}cout<<endl;
                    ///system("pause");
                    for(int i=cnt+1; i<=m; i++)
                    {
                        if(cancalc[a[k[i]]]==true)
                        {
                            for(int j=i; j<=m; j++)
                                k[j]=k[j+1];
                            m--;i--;
                        }
                    }
                    ///cout<<m<<' '<<cnt<<endl;
                    ///for(int i=1;i<=m;i++)cout<<a[k[i]]<<endl;
                }
                while(cnt<m);
                cout<<m;
            }
        }
        cout<<endl;
    }
    return 0;
}
