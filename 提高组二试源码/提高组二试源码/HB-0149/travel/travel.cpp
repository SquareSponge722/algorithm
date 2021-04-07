#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	int n,m,k,x,a[5001],b[5001],c[50001];
	cin>>n>>m;
	for(int i=1;i<=(2*m);i++)
	{
	cin>>a[i];  
	for(int h=1;h<=n;h++)
	{
	b[h]=a[i];
	if(c[h]=b[h]&&b[x]<c[h])
	cout<<b[h];
	else cout<<c[h];  
    }   
	}
    return 0;
 } 
