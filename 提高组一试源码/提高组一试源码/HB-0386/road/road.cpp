#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int i,n,s;
string a; 
int main()
 {
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	cin>>n>>a;
 	for(i=0;i<n;i++)
 	{
	 if(a[i]>'0'||a[i]<='0'&&a[i-1]<='0'&&a[i+1]>'0'||a[i+1]<='0'&&a[i]<='0'&&a[i-1]>='0')
	 {s+=1;
	 for(i=0;i<n;i++)
	 a[i]-=1;
	 }
     else if(a[i]<=0&&a[i-1]>0&&a[i+1]>0)
	 {
	 s+=2;
	 for(i=0;i<n;i++)
	 a[i]-='1';
     }
	 else if(a[i]<=0&&i==n)break;           
    }  
 	cout<<s;	
	return 0;
}
