#include<iostream>
#include<cstdio>
long long p[5005],t[5005],d[5005];
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n,i,j,q;
	bool f[q];
	f[1]=1;
	for(i=2;i<=n;i++)
	{
	f[i]=0;
	d[i]=n;}
	cin>>n>>m;
	d[1]=1;
    for(i=1;i<=m;i++)
	   {
	   cin>>p[i];
	   cin>>t[i];}
	   
    for(i=1;i<=n-1;i++)
	  {
	  	for(j=1;j<=m;j++)
	  	{
		  
		  if(p[j]==d[i]&&f[t[j]]==0)
	    	{
			d[i+1]=t[j];
	    	f[t[j]]=1;
	    	break;
            }
	      else
	     {
		  if(t[j]==d[i]&&f[p[j]]==0)
		   {
		     d[i+1]=p[j];
		     f[p[j]]=1;
		     break;
		   }
	     }
        }
      }
    for(i=1;i<=n;i++)
	cout<<d[i]<<" ";
	return 0;
   }
