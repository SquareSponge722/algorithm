#include<iostream>
#include<algorithm>
using namespace std;
int n,b,v,t,i,j,k,c,a[105];
int main()
{   freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
	cin>>t;
	v=1;
	while(v<=t)
	{
		cin>>n;
		b=n;
		for(i=1;i<=n;i++)
		cin>>a[i];
	    sort(a+1,a+n+1);
	  for(i=n;i>=3;i--)
	    for(k=n-1;k>=2;k--)
	      for(j=n-2;j>=1;j--)
	         if(a[i]==a[k]+a[j]) b=b-1;
	    for(k=n;k>=2;k--)
	     {c=0;
		  for(i=1;i<k;i++) 
	 	  {   c=a[i]+c;
	 	     if((a[k]%a[i]==0)&&(i!=k)) b=b-1;
			 if((k>=4)&&(i>=3))
			  {if(a[k]==c) b=b-1;}
		  }
		}
     cout<<b<<endl;
	 v++;
 	}
 return 0;
}


