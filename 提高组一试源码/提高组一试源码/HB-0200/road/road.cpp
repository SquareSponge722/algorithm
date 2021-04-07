#include<iostream>
#include<cstdio>
using namespace std;

int n;
int d[100010];
long long ans = 0,sum = 0;
bool tmp = 0,bj = 1;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	scanf("%d",&n);

	for(int i=1; i<=n; i++)
		scanf("%d",&d[i]);

	while( bj )
		{
			for(int j=1; j<=n; j++)
				{
					if(d[j] != 0)d[j]--,tmp = 1;
					else if(tmp)
						{
							ans++,tmp = 0;
							continue;
						}
					else
						continue;
				}

			if(tmp)
				ans++,tmp = 0;

			for(int i=1; i<=n; i++)
				if( !d[i] )sum++;
				else break;

			if(sum == n)bj = 0;
			else sum = 0;
		}

	cout<<ans<<"\n";
	return 0;
}
