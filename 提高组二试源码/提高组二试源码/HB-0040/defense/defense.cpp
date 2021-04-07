#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int a[1000000];
int b[1000000];
int c[1000000];
int main()
{
 int n,m,u,v,a,x,b,y,cost;
 char type;
 cin>>n>>m>>type;
 for(int i=1;i<=n-1;++i) cin>>u>>v;
 for(int i=1;i<=m;i++) cin>>a>>x>>b>>y;
 if(x==0&&y==0) cout<<-1<<endl;
 cout<<cost<<endl;
 return 0;
}
