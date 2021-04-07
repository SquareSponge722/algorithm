#include<bits/stdc++.h>
using namespace std;
int T;
int ans;
int a[105],b[105];
bool tmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>T;
    while(T)
    {
        T--;
        ans=0;
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        sort(a+1,a+n+1,tmp);
        for(int i=1; i<=n-1; i++)
        {
            for(int j=i+1; j<=n; j++)
                a[i]%=a[j];
            if(a[i]!=0)ans++;
        }
        ans++;
        cout<<ans<<endl;
    }
    return 0;
}
