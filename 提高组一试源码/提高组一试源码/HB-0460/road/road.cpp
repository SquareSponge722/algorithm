#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a[100007];
	 long n,head,tail,k=0,mins=10000;
	bool ssk;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=mins)
		{
			mins=a[i];
		}
	}
	
	while(ssk==false){
		ssk=true;
		mins=10000;
	for(int i=0;i<=n+1;i++)
	{
		if(a[i]!=0)
		{
			head=i;
			break;
		}
		
	}
	for(int j=head;j<=n+1;j++)
	{
		if(a[j]==0)
		{
			tail=j-1;
			break;
		}
	}
	if((head>=1)&&(head<=n)&&(tail>=1)&&(tail<=n))
	{
	
	for(int i=head;i<=tail;i++)
	{
	  if(a[i]<=mins)
	  {
	  	mins=a[i];
	  }
	}
	for(int i=head;i<=tail;i++)
	{
	  a[i]-=mins;
	}
	k+=mins;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
		ssk=false;
	}
}
cout<<k<<endl;
return 0;
}
