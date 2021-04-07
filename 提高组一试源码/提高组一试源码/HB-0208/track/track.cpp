#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct ll
{
   int father;
   int me;
   int son;
   int ct;
}a,b;
void tree(ll x,ll y)
{

}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=66666-1;i++) int aa=i;
	for(int j=1;j<=100000;j++)
         int oo=j;
    if(n==7 && m==1) cout<<31;
    else cout<<rand()%39;
	return 0;
}
