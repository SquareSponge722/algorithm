#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum=1;
void work(int n,int m)
{
    if(m>=n)
    {
        int x=n;
        while(x>0)
        {
            sum*=x;
            x--;
        }
        sum*=sum;
        m-=n;
        while(m+1>0)
        {
            sum*=(n+1);
            m--;
        }
        cout<<sum;
    }
    else
    {
        int x=m;
        m=n;
        n=x;
        work(n,m);
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>m;
    work(n,m);
    return 0;
}
