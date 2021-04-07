#include<bits/stdc++.h>
using namespace std;
int a[100050];
int n;
long long minn,ans=0,en,sum=0;

void find(int ia[],int st)
{
	    sum++;
	    int pp=st;
	    minn=ia[st];
	    while(ia[st])
	  	{
	  		if(ia[st]<minn)
	  		minn=ia[st];
	  		st++;
		}
		st--;
		for(int o=pp;o<=st;o++)
		ia[o]-=minn;
		ans+=minn;
		en=st;
		for(int o=pp;o<=st;o++)
		{
			if(ia[o])
			find(ia,o);
		}
		return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n;
    a[0]=0;
    a[n+1]=0;
    minn=999999;
    for(int k=1;k<=n;k++)
    {
     cin>>a[k];	
     if(a[k]<minn)
     minn=a[k];
	}
	if(minn)
	  	{
	  	 for(int u=1;u<=n;u++)
		   a[u]-=minn;	
		   ans+=minn;
		}
	int flag;
	for(int d=1;d<=n;d++)
	  {
	  	if(a[d])
	  	{
	  	flag=d;
	  	find(a,flag);
	  	d=en;
	  	sum=0;
	    }
	  }
	  cout<<ans;
    return 0;
}

