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
int a[50001];
int b[50001];
int l[50001];
int ans=0;
priority_queue<int>q;
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool bb=true;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i]>>b[i]>>l[i];
        if(a[i]!=1)
        {
            bb=false;
        }
    }
    if(bb)
    {
        for(int i=1;i<=n-1;i++)
        {
            q.push(l[i]);
        }
        for(int i=1;i<=m;i++)
        {
            ans+=q.top();
            q.pop();
        }
        cout<<ans;
    }
    return 0;
}

