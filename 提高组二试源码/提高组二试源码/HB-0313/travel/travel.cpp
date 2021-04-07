#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n,m;
int panduan (int a[],int b[])
{
for (int i=1;i<=n;n++)
{if (a[i]<b[i])
	{return 1;
	break; 
	}
	if(a[i]>b[i])
	{return 0;
	break;
	}
	return 2;
}}


int main() {
	int a[501][501],b[6000];
		for (int i=1;i<=n;i++)

	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	a[i][j]=0;
	b[1]=1;
	freopen ("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{int a0=0,b0=0;
	cin>>a0>>b0;
	if (a0>b0)
	{a[b0][a0]=1;
}
	if(b0>a0){
	a[a0][b0]=1;
	}
	}
	int k,kj;
	int can=1;
	int lu=1;
	for(int j=2;j<=n;j++)
	{
	
	lu=can;
	can=1;
	for (int i=1;i<=m;i++)
	{
	if(a[i][lu]==1)
	{can=i;
	break;
	}
	if(a[lu][i]==1)
	{can=i;
	break;}	
	}
	for (int i=1;i<=m;i++)
	{
	if(a[i][k]==1)
	{kj=i;
	break;
	}
	if(a[k][i]==1)
	{kj=i;
	break;}	
	}
	
	/*for (int i=1;i<=m;i++)
	{if(a[lu][i]==1)
	{
	if (a[lu][i]<a[lu][can])
		can=i;}
	}*/
	
	
	if(kj>can)	
	{b[j]=can;
	for (int i=1;i<=can;i++)
	{a[i][lu]=0;
	a[lu][i]=0;
	}}
	if(kj<can)
	{b[j]=kj;
	for (int i=1;i<=kj;i++)
	{a[i][k]=0;
	a[k][i]=0;
	}
	}k=b[j-1];
	}
	for (int i=1;i<=n;i++)
	{cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
