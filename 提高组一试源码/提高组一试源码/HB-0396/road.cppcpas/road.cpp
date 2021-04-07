#include <iostream>
#include <cstdio>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   iostream<cstdio>

#include <cmath>
using namespace std;
int ans=a7xffffff,a[100100],n;

	
}
long long depth(int l,int r)
{int sum;
	for(int i;i<=r;i++)
	sum+=a[i];    
	return sum;
}
void dealt(int l,int r)
{
	for(int i=1;i<=r;i++)
	{if(a[i]<0) break;
	}
	a[i]=1;
}
void dfs(int l,int r,int sum)
{
	if(sum==0)(ans=min(ans,sum);)
	for(int j=l+1;j<=n;j++)
	{
		
		
		dealt(l,j);
		dfs(i,j,sum+1);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	dfs(l,1,0);
	cout<<ans;
return 0;	
	
}
