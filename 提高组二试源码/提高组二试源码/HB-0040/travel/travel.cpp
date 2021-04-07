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
 int n,m,u,v,i;
 cin>>n>>m;
 for(i=1;i<=n;++i) a[i]=i;
 for(i=1;i<=2*n;++i) 
 {
  cin>>b[i];
  if(b[i]!=c[2*n]) c[2*n]=b[i];
 }
 cout<<c[2*n];
 return 0;
}
