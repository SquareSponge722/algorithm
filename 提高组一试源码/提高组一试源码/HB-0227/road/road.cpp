#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#define N 100000+100
using namespace std;
int n,ans,flag,minv=N;
int a[N];
//priority_queue <int>q;
int main()
 {
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++)
	 cin>>a[i];
	 for(int i=1;i<=n;i++)
	 minv=min(minv,a[i]);
	 for(int i=1;i<=n;i++)
	 a[i]-=minv;
	 ans+=minv;
 	for(int i=1;i<=n;i++)
 	{
 		while(a[i])
 		{
 			flag=0;
		 for(int j=i;j<=n;j++)
 		  {
			if(a[j]>0){a[j]--;flag=1;}
			else break;
		  }
		  if(flag==1)ans++;
		 }
	 }
	 cout<<ans;
	return 0;
}