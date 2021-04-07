#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
define d[10001]
using namespace std;

//freopen("road.in","r",stdin)
//freopen("road.out","w",stdout)
int main() 
{
	int n,max=0,ans=0;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>d[i];
		for(int i=1;i<n;i++)
		{
			if(max<d[i])max=d[i];max--;	
		}
		for(ans=1;max;ans++)
			{
				int count=0;
				for(int i=1;i<=n;i++)
					if(count)continue;
					else break;
			}
	}
	cout<<ans<<endl;
	return 0;
}
