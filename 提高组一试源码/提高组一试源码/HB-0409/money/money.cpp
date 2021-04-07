#include<bits/stdc++.h>
using namespace std;
int main()
{
	int W,W1,m,C,T,n,i,a[101];
	bool flag;
	cin>>T;
	cin>>n;
	for(int t=1;t<=T;t++)
	{
		flag=1;
		for(i=1;i<=n;i++)
	    cin>>a[i];
	    for(i=1;i<n;i++)
	    for(i=1;i<n;i++)
	    {
	    	if(a[i]>a[i+1])
	    	{
	    		C=a[i+1];
	    		a[i+1]=a[i];
	    		a[i]=C;
			}
		}
		for(i=2;i<=n;i++)
			if(a[i]%a[1]!=0)
			{
			W1=a[i];
			flag=0;
			break;
		}	
		W=W1*a[1]-W1-a[1];
		for(i=3;i<=n;i++)
		{
			m=i-1;
			if(W<=a[i])
			{
			m=i;
			break;
		    }
		}
		if(flag==1) m=1;
		cout<<m<<endl;
    }
return 0;
}
