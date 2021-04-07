#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[101];
int sea,k;
bool flag;

void js(int p,int q)
{
	if (q==0||(!flag) ) return;
	else
	{
		if(p%a[q]==0)
		{
			k--; flag=0; return;
		}
		else
		{
			p/=a[q];
			js(p,q-1);
		
		while(flag&&p<=sea)
		{
			p+=a[q];
			js(p,q-1);
		}
		
	   }
    } 
}


int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n,t,i,j;
	scanf("%d",&t);
	while(t--)
	{
	   scanf("%d",&n);
	     k=n;
	   for( i=1;i<=n;i++)
	   scanf("%d",&a[i]);
	   sort( a+1 , a+n+1);
	   for( i=n;i>1;i--)
	  {
		 sea=a[i];flag=1;
		for( j=i-1;j>=1;j--)
		{
			js(a[i],j);
			if(!flag) break;
		}
	  }
	  printf("%d\n",k);
    } 
	return 0;
		
}
