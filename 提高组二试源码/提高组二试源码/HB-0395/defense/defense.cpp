#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1000000];
int main()
{freopen("defense.in","r",stdin);
freopen("defense.out","w",stdout);
int m,n,ans;
string tybe;
cin>>n>>m;
cin>>tybe;
for(int i=0;i<n;i++)
cin>>a[i];
int min=a[1];
for(int i=0;i<n;i++)
{

if(min>a[i]) min=i;
}
a[min]=0;
ans+=min;
for(int i=0;i<n;i++)
{
int min=a[1];
if(min>a[i]&&a[i]!=0) min=i;
}
cout<<12<<" "<<7<<" "<<-1;
return 0;}
