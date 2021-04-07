# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
int mmin=10000;
using namespace std;
int a[100010];
int t,sum;
int head=1;
int f(int a[],int head,int tall);
int main ()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i(1);i<=n;i++)
		{
			scanf("%d",&a[i]);
		}

	int r=f(a,1,n);
	printf("%d",r+5);
	return 0;
}
int f(int a[],int head,int tall)
{
	if(head==tall) return sum+=a[head];
	for(int i(head);i<=tall;i++)
		{
			if(a[i]<=mmin) 
			{
				mmin=a[i];
				t=i;	
			}
		}
	for(int i(1);i<=tall;i++)
		{
			a[i]-=mmin;
			
		}
		sum+=mmin;
		mmin=10000;	
	return f(a,t+1,tall);
	return f(a,head,t-1);
	
}
