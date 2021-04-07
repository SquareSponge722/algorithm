#include<bits/stdc++.h>
using namespace std;
int main()
{   
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int L=1,R,n,i,d[100001],D=0;
	bool flag;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>d[i];
	do
	{   
	    D++;
	    flag=1;
    	for(i=1;i<=n;i++)
	    {
		    if(d[i]==0)
		    L=i+1;
		    else break;
	    }
	    for(i=L;i<=n;i++)
	    {
		    if(d[i]!=0)
		    R=i;
		    else break;
	    }
	    for(i=L;i<=R;i++)
	    d[i]--;
	    for(i=1;i<=n;i++)
	    {
	    	if(d[i]!=0)
	    	flag=0;
		}
    }
	while(flag!=1);
	cout<<D<<endl;
	return 0;
}
