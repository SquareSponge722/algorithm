#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int n,m,x,y,tot,road,p;
string a[1100];//每个数字对应的城市能到的地方
bool b[1100];//是否来过这里；
int f[1100];//第一次来这里的路径
string s;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>x>>y;
        a[x]+=y+48;
        a[y]+=x+48;
    }
    //for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    //if(a[3][3]==0) cout<<1;
    s+=49;//从第一个开始
    tot=1;
    m=1;
    b[1]=1;
    while(tot!=n)
    {
        if((a[m][1]==0)&&(a[m][0]!=0)&&(b[a[m][0]-48]!=1))
        {
            s+=a[m];
            b[a[m][0]-48]=1;
            f[a[m][0]-48]=a[m][0]-48;
            m=a[m][0]-48;
            tot++;
            //cout<<m<<' ';
        }
        if((a[m][1])!=0)
        {
            road=2000;
            p=0;
            while(a[m][p]!=0)
            {

                if(b[a[m][p]-48]!=1)
                {
                    //cout<<p<<' '<<a[m][p]<<' '<<road<<' ';
                    road=min(road,(a[m][p]-48));
                    //cout<<road<<' ';

                }
                p++;

            }
            //cout<<a[m][p]-48;
            if(road!=2000)
            {
                b[road]=1;
                f[road]=m;
                s+=road+48;
                m=road;
                tot++;
                //cout<<m<<' ';
            }
            if(road==2000)
            {
                m=f[m];
            }
        }
    }
    for(int i=0; i<=n-1; i++) cout<<s[i]<<' ';
    return 0;
}
