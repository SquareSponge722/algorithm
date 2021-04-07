#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int n,sum=0,maxa=0,sum1=0,a[1010015],b[1010015],c;


int main()
 {
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
 		b[i]=1;
	}
	b[0]=1;
	for(;;)
	{
		int ll=0,rr=0;
		c=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0&&b[i]!=0)
			{
				sum1++;
				b[i]=0;
			}
			if(sum1==n)
			{
				cout<<sum;
				return 0;
			}
			if(a[i]!=0&&ll==0)
			{
				ll=i;
				c=1;
			}
			
			if(a[i]==0&&ll!=0)
			{
				rr=i-1;
			}
			if(c==1&&a[i]!=0)
			{
				a[i]--;
			}
			if(i==n&&rr==0)
			{
				sum++;
				break;
			}
			if(ll!=0&&rr!=0)
			{
				sum++;
				break;
			}	
		}
	}
 	cout<<sum;
	return 0;
 }
