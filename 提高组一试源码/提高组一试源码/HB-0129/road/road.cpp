#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,temp=0,n,x,y;
	cin>>n;
	int d[10001]={0};
	int c[10001]={0};
	for(i=1;i<=n;i++)
	{
	cin>>d[i];
	c[i]=d[i];
    }
    for(i=1;i<=n;i++)
    {
    	  if(c[i]>c[i+1])
    	  {
    	  	y=c[i+1];
    	  	c[i+1]=c[i];
    	  	c[i]=c[i+1];
		  }
    
	}
	if(d[n]!=c[n]&&d[n-1]!=c[n])
    {
     	for(i=1;i<=n;i++)  
	   {
		if(d[i]>d[i+1]) 
		{
		x=d[i]-d[i+1];
		temp=temp+x;
	    }
	   }
	}
	else                 
	{
		for(i=1;i<=n-2;i++)
		if(d[i]>d[i+1]) 
		{
		x=d[i]-d[i+1];
		temp=temp+x;
	    }
	    temp=temp+c[n];
		
	}
	cout<<temp;
	return 0;
}
