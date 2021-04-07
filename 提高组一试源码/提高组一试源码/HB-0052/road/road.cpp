 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <algorithm>
 #include <cstring>
 #include <cmath>
 int a[1000];
 using namespace std;
 int main()
 {	
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if(n==1)cout<<a[1];
	if(n==2)
	{
		k=max(a[1],a[2]);
		cout<<k;
	}
	if(n==3)
	{
		m=max(a[1],a[2]);
		if(m>a[3])cout<<m;
		else cout<<a[3];
	}
	if(n==4)
	{
		m=max(a[1],a[2]);
		k=max(a[3],a[4]);
		if(m>k)cout<<m;
		else cout<<k;
	}
 	return 0;
 } 
