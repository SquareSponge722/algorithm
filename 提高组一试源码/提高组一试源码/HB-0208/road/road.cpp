#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100010;
int head,tail;
int f[maxn];
int n;
int ans=0;
bool b=true;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>f[i];
    f[n+1]=0;
    while(b==true)
    {
        for(int i=1; i<=n; i++)
        {
            if(f[i]>0)
            {
                head=i;
                break;
            }
        }
        for(int j=head; j<=n+1; j++)
        {
            if(f[j]==0)
            {
                tail=j-1;
                break;
            }
        }
        for(int i=head; i<=tail; i++)
        {
            f[i]--;
        }
        ans++;
        b=false;
        for(int i=1; i<=n; i++)
        {
            if(f[i]!=0) b=true;
        }
    }
    cout<<ans;
    return 0;
}
