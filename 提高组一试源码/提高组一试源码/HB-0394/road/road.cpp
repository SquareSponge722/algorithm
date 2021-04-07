#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define N 100010
using namespace std;
int m,a[N],sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		while(a[i]>0)
		{
			sum++;
			int k=i;
			while(a[k]>0)
			{
				a[k]--;
				k++;
			}
		}
	}
	cout<<sum;
}
