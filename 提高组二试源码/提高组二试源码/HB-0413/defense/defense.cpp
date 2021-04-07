#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
int data1,data2;
string s;
int a,b,x,y;
int liantong[2500][2500];
int pay[2500];
int zhuzha[2500];
bool candefense[2500];
int fee;
bool biaoji[2500]
void calcu(int k)
{
}
int main()
{
    ///freopen("defense.in","r",stdin);
    ///freopen("defense.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1; i<=n; i++)cin>>pay[i];
    for(int i=1; i<=n-1; i++)
    {
        cin>>data1>>data2;
        liantong[data1][data2]=1;
        liantong[data2][data1]=1;
    }
    for(int ii=1; ii<=m; ii++)
    {
        fee=0;
        cin>>a>>x>>b>>y;
        zhuzha[a]=x;
        zhuzha[b]=y;
        if(liantong[a][b]==1&&x==0&&y==0)
        {
            cout<<-1<<endl;
            continue;
        }
        calcu()
    }
    return 0;
}
liantong[data1][data2]=1;
