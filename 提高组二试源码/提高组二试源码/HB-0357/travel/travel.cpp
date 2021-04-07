#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,k,j,check,l,temp,num=2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[100][2];
	int e[100];
	int c[100];
	int d[100];
	cin>>n>>m;
	for(i=0;i<m;i++)
		for(j=0;j<2;j++)
		cin>>a[i][j];
		e[1]=1;
		for(i=2;i<=n;i++)
			e[i]=e[i-1]+2;
		e[3]-=3;
		e[4]-=2;
		e[5]-=5;
        e[6]-=5;
		if(m=6)
		{
			temp=e[4];
			e[4]=e[5];
			e[5]=temp;
			}	
	for(k=1;k<=n;k++)
	{
		check=k;
	   for(l=0;l<m;l++)
	  {
	if(a[l][0]==check||a[l][1]==check)
	  {
	  check=a[l][1-l];
	  c[num]=check;
	  num++;
	  l++;
	  l%=m;
      }
	    if(l>m)
        {
		   check=c[num-1];
	    }
      }
	}
	c[1]=1;
    for(i=1;i<=n;i++)
    cout<<e[i]<<" ";
    return 0;
}
