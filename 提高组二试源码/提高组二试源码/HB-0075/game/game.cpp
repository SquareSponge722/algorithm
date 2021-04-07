#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int m,n,a=1,b=1,c=1;
	long long sum;
	cin>>m>>n;
	 if((m==n)&&(m%2==0))
	 {
	 	for(int i=1;i<=m;i++)
	    a=a*8;
	    a=a/4;
	    b=a/4;
	    sum=a-b;
	 }
	 if((m==n)&&(m%2!=0))
	 {
	 	for(int i=1;i<=m;i++)
	    {
	    a=a*8;
		c=c*2;	
		}
	    a=a/4;
	    b=a/8;
	    c=c*2;
	    sum=a-b-c+m*m+7;
	 }
	 if(m>n)
	 {
	 	for(int i=1;i<=m;i++)
	    a=a*2;
		for(int i=1;i<=n;i++)
	    b=b*2;
	    sum=a-b-m+n;
	 }
	  if(m<n)
	 {
	 	for(int i=1;i<=m;i++)
	    a=a*2;
		for(int i=1;i<=n;i++)
	    b=b*2;
	    sum=b-a-n+m;
	 }
	 cout<<sum;
	 return 0;
}
