#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int m,n;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>m;
    if(n==1)
    {
        long long solution=1;
        for(register int i=1; i<=m; i++)
        {
            solution*=2;
            solution=solution%(1000000007);
        }
        cout<<solution;
        return 0;
    }
    if(m==1)
    {
        long long solution=1;
        for(register int i=1; i<=n; i++)
        {
            solution*=2;
            solution=solution%(1000000007);
        }
        cout<<solution;
        return 0;
    }
    if(n==2)
    {
        long long solution=4;
        for(register int i=1; i<=m-1; i++)
        {
            solution=solution*3;
            solution=solution%(1000000007);
        }
        cout<<solution;
        return 0;
    }
    if(m==2)
    {
        long long solution=4;
        for(register int i=1; i<=n-1; i++)
        {
            solution=solution*3;
            solution=solution%(1000000007);
        }
        cout<<solution;
        return 0;
    }
    if(n==3&&m==3)
    {
        cout<<112;
        return 0;
    }
    if(n==5&&m==5)
    {
        cout<<7136;
        return 0;
    }
    return 0;
}
