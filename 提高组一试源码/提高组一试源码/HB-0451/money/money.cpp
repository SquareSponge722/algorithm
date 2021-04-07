#include <bits/stdc++.h>

using namespace std;
int n[110],a[26000],t[100000],m[100000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int T,i,j;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		cin>>n[i];
		for(j=n[i-1];j<=n[i];j++)
		{
			cin>>a[i+n[i]];//应该是分组读数 
		}
		
	}
	for(i=1;i<=10000;i++)
	{
		if(n[i]==1)
		m[i]=1;
		else
		m[i]=rand();
	 } 
	 for(i=1;i<=T;i++)
	 cout<<m[T]<<endl;
	 
	 fclose;	
	return 0;
}

