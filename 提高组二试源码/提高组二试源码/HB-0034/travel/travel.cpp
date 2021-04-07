#include<iostream>
#include<cstdio>
using namespace std;
int a[5250][5250],b[5250],ss[5250],minn[5250];
int i,n,s,e,c=1,m;
void hhh(int i)
{
    int j;
    bool bb=0;
    if(c>=n)
    {
        for(j=1;j<=c;j++)
            if(ss[j]>minn[j])
                bb=1;
        if(bb==0)
        for(j=1;j<=c;j++)
            minn[j]=ss[j];
    }
    else for(j=1;j<=n;j++)
    {
        if(a[i][j]==1&&b[j]==0)
        {
            b[j]=1;
            c++;
            ss[c]=j;
            hhh(j);
            b[j]=0;
        }
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>s>>e;
        a[s][e]=1;
        a[e][s]=1;
        minn[i]=2147483647;
    }
    minn[n]=2147483647;
    ss[1]=1;
    b[1]=1;
    hhh(1);
    for(i=1;i<=n;i++)
        cout<<minn[i]<<" ";
    return 0;
}
