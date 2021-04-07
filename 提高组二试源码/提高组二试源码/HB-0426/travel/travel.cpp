#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,h,l,i,x,y,v,g;
int a[5005][5005],zong[5005],z[3][5005],op[5005];	 
void fs(int b)
{
	for(i=1;i<=n;i++)
	 {if(a[b][i]==0)  {
	                       a[b][i]=2;a[i][b]=1;
						   zong[l]=b;l++;
						   fs(i);
						   if(l==n+1)  { 
						               for(int m=1;m<=n;m++)
	                                   zong[m]=z[h][m];
	                                   h++;
                                       if(h==3)  for(int k=1;k<=n;k++)
    {
		if(z[1][k]!=z[2][k]) {v=k;break;}
	}
	    if(z[1][v]>z[2][v]) for(int k=1;k<=n;k++) {z[1][k]=op[k];h=1;}
	else for(int k=1;k<=n;k++) {z[2][k]=op[k];h=1;}
						   }
	                  }
	  if(a[b][i]==1)  {fs(i);}
	 }	 
int main()
{   
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
	cin>>n>>m;
	h=1;l=2;
	for(i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  {a[i][j]=0x7fffffff/3;
	   a[j][i]=0x7fffffff/3;}
	for(i=1;i<=m;i++)
      {  cin>>x>>y;
		 a[x][y]=0;
		 a[y][x]=0;
	  }
	fs(1);
    for(i=1;i<=n;i++) { g=op[i]; cout<<g<<" ";}
	return 0;
}
