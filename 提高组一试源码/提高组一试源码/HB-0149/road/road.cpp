#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("road1.in","r",stdin);
	freopen("road1.out","w",stdout);
	int i,n,day;
	string a;
	a[i]=10001;
	day=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	cin>>a;
    a[i]--;
    day++;
	}
   cout<<day;
   return 0;
}
	

	
	

