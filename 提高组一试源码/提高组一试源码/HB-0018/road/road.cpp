#include<bits/stdc++.h>
using namespace std;
int a[100086];
int n,i,x,j,y;
int minl,m;
long long s;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	 cin>>a[i];
	for(i=1;i<=n;i++)
	{
	 while(a[i]==0) i++; 
	 if(a[i-1]==0&&a[i+1]==0) 
	 {s=s+a[i];a[i]=0;}
	  y=minl=a[i];
	  x=i;
	 while(a[x]!=0)
	 {
	 	m=a[x]-minl;
	 	if(m<0) {minl=a[x];a[x]=0;}
	 	else a[x]=m;
	 	x++;
	 }
	 s=s+y;
	}
	cout<<s;
	return 0;
}
