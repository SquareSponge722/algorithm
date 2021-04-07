#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
using namespace std;
const int mx=110;
const int mm=100010;
int t,a[mx],n;
bool b[mm];
bool cmp(const int &x,const int &y)
{
    return x<y;
}
void dfs(int sum,int k)
{
    for (int i=1;i<=n;i++)
    {
        if (b[sum+a[i]]==true && k!=1) b[sum+a[i]]=false;///cout<<"*"<<sum+a[i]<<"*"<<endl;
        if (sum+a[i]<=a[n]) dfs(sum+a[i],k+1);
    }
    return;
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>t;
    for (int it=1;it<=t;it++)
    {
        cin>>n;
        for (int i=1;i<=mm-1;i++) b[i]=false;
        for (int i=1;i<=n;i++) cin>>a[i],b[a[i]]=true;
        sort(a+1,a+n+1,cmp);///for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
        if (a[1]==1) cout<<"1"<<endl;
        else if (n==1) cout<<"1"<<endl;
        else if (n==2)
        {
            int maxa,mina;
            maxa=max(a[1],a[2]),mina=min(a[1],a[2]);
            if (maxa%mina==0)
                cout<<"1"<<endl;
            else
                cout<<"2"<<endl;
        }
        else
        {
            dfs(0,1);
            int sum=0;
            for (int i=1;i<=a[n];i++) if (b[i]==true) sum++;
            cout<<sum<<endl;
        }
    }
    return 0;
}
