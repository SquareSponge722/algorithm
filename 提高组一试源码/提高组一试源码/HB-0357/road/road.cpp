#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100];
	int n,i
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
    for(m=1;m<=n;m++)
    {
    	if(a[m]==0)
    	{
		    num++;
			c[num]=m;
		}
	}
	c[0]=a[1];
	c[num+1]=a[n];
	min=a[1];
	for(b=0;b<=num;b++)
{
	
	for(k=c[b];k<c[b+1];k++)
	{
		if(a[k]<a[k+1])
		{
		   min=a[k];
		   x=k;
	    }
	}
	
	for(k=c[b];k<c[b+1];k++)
	{
	    a[k]-=x;
	    if(a[k]<a[k-1])
    }
	
    
}
	
	
    
	
	
	
}
