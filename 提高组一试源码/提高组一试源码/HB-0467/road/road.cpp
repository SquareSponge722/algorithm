#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int L,R,n,i,num=0;
	int d[10001];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>d[i];
	    if(d[i]=0)
	    {
	    	L=0;
	  	    R=i-1;
	  	    while(d[L]>0)
	  	    {
	  	    	d[L]-=1;
	  	    	num+=1;
		    }
	    }
	}
	cout<<num;
    return 0;
}
