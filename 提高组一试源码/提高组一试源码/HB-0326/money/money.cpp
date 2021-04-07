#include<iostream>
#include<cstdio>
using namespace std;
int a[25][110],T,n[25];
bool money(int k,int p)
{
	int temp;
	for(int i=1;a[p][i]<=k;i++)
	    {
	    	if(a[p][i]==0)
	    	   continue;
	    	if(k%a[p][i]==0)
	    	   return true;
	    	else
	    	  {
			    temp=k%a[p][i];
			    if(temp==1)
			       continue;
			    else
				   return money(temp,p);
			  }
		}
	return false;
}
int ans(int p)
{
	int temp;
	for(int i=n[p];i>0;i--)
	    for(int j=1;j<i-1;j++)
	        if(a[p][j]>a[p][j+1])
	          {
	          	temp=a[p][j+1];
	          	a[p][j+1]=a[p][j];
	          	a[p][j]=temp;
			  }
    if(a[p][1]==1)
       return 1;
    int j=n[p];
    for(int i=2;i<=n[p];i++)
        {
        	temp=a[p][i];
        	if(money(temp,p))
        	  {
			   j--;
			   a[p][i]=0;
		      }
		}
	return j;
}
int main()
{
	FILE *fin,*fout;
	fin=fopen("money.in","rb");
	fout=fopen("money.out","wb");
	fscanf(fin,"%d",&T);
	for(int i=1;i<=T;i++)
	    {
	    	fscanf(fin,"%d",&n[i]);
	    	for(int j=1;j<=n[i];j++)
				fscanf(fin,"%d",&a[i][j]);
		}
	for(int i=1;i<=T;i++)
		    fprintf(fout,"%d\n",ans(i));
	return 0;
}
