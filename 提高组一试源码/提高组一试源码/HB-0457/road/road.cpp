#include <iostream>
#include <cstdio>
using namespace std;
bool com(long a[100000],int n){
	int s;
	for (int i=0;i<=n;i++){
	   if(a[i]<a[i-1])s=a[i];
	    else s=a[1]; 
		return s;	
	}
}

bool re(int n,long a[100000],int x){
	int d;
	long b[100000];
	for(;;){
	int g=0;
	int t=0;
	int s,d;
    for(int i=t;i<=n;i++){
		a[i]-=s;
		if (a[i]==0)
		b[g++]=i;
	}
	x=x-s;
	s=com(a,n);
	d++;
    for(int i=1;i<=g;i++){
    	if(b[i]==0&&b[i-1]){
    		n=i;
   	    }
   	    if(b[i]&&b[i-1]==0)
   	       t=i;    
	}
	if (g==n)break;
}
	return d;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,d,s;
	long x=10000;
	long a[100000];
	cin>>n;
	for (int i=1;i<=n;i++){
	   cin >>m;
	   m=a[i];
}
	 	for (int i=0;i<=n;i++){
		 if(a[i]<x)x=a[i];	
	}
	s=com(a,n);
    d=re(n,a,x);
    cout<<d;
	return 0;
}
