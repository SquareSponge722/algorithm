#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m,i,j,c=0;
string a,b;
int main()
 {
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	cin>>n>>m;
 	for(i=0;i<1;i++)
 	{cin>>a>>b;
 	cout<<a[0]<<endl<<b[0]<<endl;
 	}	
 	for(i=0;i<m;i++)
 	{cin>>a[i]>>b[i];
    if(a[i]==b[0])b[0]=b[i];
 	else if(b[i]==b[0])b[0]=a[i];
 	else if(a[i]!=b[0]||b[i]!=b[0])b[0]=b[i];
 	cout<<b[0]<<endl;
 	if(b[m-1]>a[m-1]&&b[m-1]==n||a[m-1]>b[m-1]&&a[m-1]==n)break;
	 }
	return 0;   
 }       
