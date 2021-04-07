#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
 int n,m,i,w=0;
 cin>>n>>m;
 for(i=1;i<=n*m;++i)
   for(int j=3;j<=n*m;++j) ++w;
 w=w*n*m/2-n*m;    
 cout<<w;
 return 0;	
}
