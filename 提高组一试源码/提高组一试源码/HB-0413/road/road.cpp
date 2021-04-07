#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,d[10010];
int time;
int deep;
int length;
void filling(int countt)
{
    int ks,ke;
    length=0;
    for(int i=1;i<=n;i++)length+=d[i];
    ///cout<<length<<endl;
        if(length==0)
            return ;
    for(int i=1;i<=n;i++)
        if(d[i]!=0)
        {ks=i;break;}
        ///cout<<ks<<endl;
    for(int i=ks;i<=n+1;i++)
        if(d[i]==0){ke=i-1;break;}
        ///cout<<ke<<endl;
    for(int i=ks;i<=ke;i++)
            d[i]--;
    time++;
    filling(countt+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
        cin>>d[i];
    time=0;
    filling(0);
    cout<<time;
    return 0;
}
