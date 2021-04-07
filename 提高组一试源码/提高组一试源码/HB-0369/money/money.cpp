#include<cstdio>
#include<iostream>
#include<algorithm>
#include<list>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<iomanip>
#include<cstdlib>
using namespace std;
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int t;
    cin>>t;
    while(t>0)
    {
        t--;
        int n;
        int a[100001];
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n==2)
        {
            if(a[1]%a[2]==0||a[2]%a[1]==0)
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<2<<endl;
            }
        }
    }
    return 0;
}
