#include<iostream>
#include<cstdio>
using namespace std;
const int mx=100010;
int n,a[mx];
long long ans=0;
void zxy()
{
    int mina=99999;
    bool b=0;
    for (int i=1;i<=n;i++)
    {
        int st,en;
        if (a[i]>0)
        {
            b=1;
            st=i;
            mina=a[i];
            while (a[i]>0)
            {
                mina=min(mina,a[i]);
                i++;
            }
            en=i;
            for (int j=st;j<=en;j++) a[j]=a[j]-mina;
            ans=ans+mina;
        }
    }
    if (b==1) zxy();
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    zxy();
    cout<<ans;
    return 0;
}
