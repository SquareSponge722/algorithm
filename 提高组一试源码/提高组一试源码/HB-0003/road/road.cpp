#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[100001];
	int n;
	freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
	int s;
	cin>>n;
	
	for(s=1; s<=n; s++) {
		cin>>a[s];
	}
	
	int sum=0;
	int f,l;
	int q,p,d;
	int x=1,y;
	while(x!=0) 
	{
		x=0;
		for(y=1; y<=n; y++) 
		{
			if(a[y]!=0) 
			{
				x++;
			}
		}
		for(q=1; q<=n; q++) 
		{
			if(a[q]!=0) {
				
				f=q;
				break;
			}
		}
		for(p=f; p<=n; p++) 
		{
			if(a[p]==0) 
			{
				l=p-1;
				break;
			}
		}
		if(l<=f)
		{
			if(a[f+1]!=0)
			{
				l=n;
			}
			if(a[f+1]==0)
			{
				l=f;
			}
		
		}
	for(d=f;d<=l;d++)
	{
		a[d]=a[d]-1;
	}
	sum++;
		
	}
	sum=sum-1;
   cout<<sum;
        return 0;
}

