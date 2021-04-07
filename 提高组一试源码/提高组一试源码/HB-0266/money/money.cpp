#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int a[101],T,n,k,b[25100],ans;
vector<int> c[101];
int cutoff()
{
         for(int i=1;i<=n;i++)
         {
		     for(int j=1;j<=k;j++)
		     {
		     	for(int k=i+1;k<=n;k++)
		     	{
		     	int mark=a[i]*j;
		         b[mark]--;
		         b[mark+a[k]]--;
			}
			 }
		}
		for(int i=1;i<=a[n];i++)
		{
			if(b[i]>0)
			{
				cout<<i<<" "<<endl;
            }
		}
		
}
int main()
{
	freopen("money.in","r",stdin);
	freoepn("money.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
	/*		memset(b,1,sizeof(b));
			for(int j=1;j<=n;j++)
			b[a[j]]++;
			sort(a+1,a+n+1);
			k=a[n]/a[1];
	     	cout<<cutoff()<<endl;
			T--;
			*/
		sort(a+1,a+n+1);
				k=a[n]/a[1];
		if(n==2)
		{
		if(a[3]%a[1]==0) cout<<1<<endl;
		else cout<<2<<endl;
	}
	else if(n==3)
	{
		if(a[3]%a[1]==0||a[1]*i+a[2]==a[3]||(a[3]-a[2])%a[1]==0||(a[3]-a[1])%a[2]==0)//É¸µô3 
		{
			if(a[2]%a[1]==0) {cout<<1<<endl; }
			else {cout<<2<<endl; } 
        }
	 else if(a[2]%a[1]==0) //É¸µô2 
		{
			if(a[3]%a[1]==0) cout<<1<<endl;
			else cout<<2<<endl;	  		
		 } 
		 else cout<<3<<endl;
}
}
	return 0;
}
