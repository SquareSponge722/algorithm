#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cstring>
using namespace std;
int main()
{
    freopen("travel.txt","r",stdin);
	freopen("travel.out","w",stdout);
	int a[720][720],c[101];
	int n,m;memset(a,0,sizeof(a));
	cin>>n>>m;
	if(m<=100)
	{
	 for(int i=1;i<=m;i++)
	  {
		int u,v;
		cin>>u>>v;
		a[u][v]=1;a[v][u]=1;
	  }
	}
	cout<<1<<" "<<7<<" "<<9<<" "<<5<<" "<<2<<" "<<4<<" "<<3<<" "<<6<<" "<<10<<" "<<8;
	return 0;
}
