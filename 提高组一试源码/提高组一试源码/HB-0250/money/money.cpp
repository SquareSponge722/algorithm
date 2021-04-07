#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define N 1000000

using namespace std;

long long ooo,n,a[N],flag[105][26000];
//priority_queue<int, vector<int>, greater<int> >q;//Ð¡ÔÚÇ° 

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&ooo);
	for(int oo=1;oo<=ooo;oo++)
	{
		long long maxv=0,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			maxv=max(maxv,a[i]);
		}
		flag[oo][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=maxv;j++)
			{
				if(flag[oo][j])flag[oo][j+a[i]]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(flag[oo][a[i]]<2){
				ans++;
				//cerr<<i<<' '<<a[i]<<endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
