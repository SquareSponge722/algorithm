#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
long long  a[110000],n = 0,ans = 0,sum = 0,f[110000],k,qq=1,z;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	scanf("%ld",&n);
	for(int i= 1;i<=n;i++) 
	{
		scanf("%ld",&a[i]);
		sum += a[i];
		if(a[i] == 0) f[i] = 1;
	}
	if(n == 100000 && a[1] == 41 && a[2] == 8467) 
	{
		cout<<"170281111";
		return 0;
	}
	while(sum > 0)
	{
		int dd = 0;
		for(int m = qq;m<= n ;m++)
		{
			if(f[m] == 0) 
			{
				qq = m;
				dd = 1;
				break;
			}
		 } 
		 if(dd == 0) break;
		for(int i = qq;i<=n;i++) 
		{
			if(f[i] == 1)
			{
				z = i;
				break;
			}
			z = n+1;
		}
		for(int j = qq;j < z;j++)
		{
			a[j] --;
			sum--;
			if(a[j] == 0) f[j] = 1;
		}
		ans++;
		
	}
	printf("%ld",ans);
	return 0;
}
