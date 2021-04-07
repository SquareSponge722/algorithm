#include<iostream>
using namespace std;
int i,n,b,k,c,m,v,l,zong,a[100005];
int main ()
{   
    b=0;
    zong=0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
   	cin>>k;
	for(i=1;i<=k;i++)
	{
	 cin>>a[i];
	}
	while(a[100005]==0)
	{   v=0x7fffffff/3;
	    l=0;	
		i=1;
		while(a[i]==0)
        i++;
        n=i;
        while(a[n]!=0)
        n++;
        n=n-1;
        for(m=i;m<=n;m++)
         if(a[m]<v) {v=a[m];}
        for(m=i;m<=n;m++)
          a[m]=a[m]-v;
          zong=zong+v;
        for(i=1;i<=k;i++)
        {if(a[i]==0) {l++;}}
		if(l==k)  break;
	}
	cout<<zong<<endl;
	return 0;
}
