#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,d[10001],day=0,a=9999999,b,day1=0,day2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
       	if(d[i]<a){a=d[i];b=i;}
	}
	while()
	for(int j=1;j<=n;j++)
	{
		d[j]=d[j]-a;
	}
	day=a;
    for(int j=1;j<b;j++)
    {
    	int c=9999999;
    	if(d[j]<c)c=d[j];
    	
    }
    for(int j=b+1;j<=n;j++)
    {
    	
    	if(d[j]>e)
    	e=d[j];
	}
	day=a+c+e;
	cout<<day+2;
	return 0;
}
