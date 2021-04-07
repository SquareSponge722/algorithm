#include<bits/stdc++.h>
using namespace std;
const int MM=100005;
int n;
int ans;
int a[MM],b[MM];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=a[i]-a[i-1];
        if(b[i]>0) ans+=b[i];
    }
    cout<<ans;
    return 0;
}
