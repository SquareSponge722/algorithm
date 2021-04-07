#include<iostream>
#include<cstdio>
#include<cmath>
int a[100001];
int c[100001];
using namespace std;
int main()
{
	int n,d=0;
	scanf("%d",&n);
	for(int j=1;j<=n;++j)
	   {scanf("%d",&a[j]);}
    for(int i=1;i<n;++i)
    {
    	if(a[i]<a[i+1])c[i]=a[i+1]-a[i];
    	if(a[i]==a[i+1])c[i]=0;
    	if(a[i]>a[i+1])c[i]=a[i]-a[i+1];
	}
	for(int i=1;i<n;++i)
	   {d+=c[i];}
	   printf("%d",d);
	   return 0;
}
