#include <bits/stdc++.h>

using namespace std;
int d[10100]={0};



int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,i,s,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	cin>>d[i];
    }
    for(i=1;i<=n;i++)
    {
    	if(d[i]>d[i+1])
	     s=d[i];
	    else
	     s=d[i+1];
	
	}
   for(int j=1;j<=105000;j++)
	{
	
    for(i=1;i<=n;i++)
    {	
		if(d[i]>0)
    	{
		d[i]=d[i]-1;
		if(d[i+1]==0)
		ans++;
	
	    }
		}
    }

        
	
cout<<ans;
fclose;

return 0;
	
	
}
