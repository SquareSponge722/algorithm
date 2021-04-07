#include <cstdio>
#include <iostream>
#include <algorithm>
int d1[1000010],d[1000010];
using namespace std;
int main()
{	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,sum = 0,left = 0,right = 0,sum1 = 0;
	cin>>n;
	for(int i = 0;i < n;i++)
	{	cin>>d1[i];
		d[i] = d1[i];
	}
	sort(d1,d1 + n);
	for(int i = 0;i < n;i++)
	{	if(d[i] > d1[(n - 1) / 2])
		{	sum += d[i] - d1[(n - 1) / 2];
			d[i] = d1[(n - 1) / 2];
		}
	}//
	for(int j = d1[0];j < d1[(n - 1) / 2];j++)
	{	for(int i = 0;i < n - 1;i++)
		{	if(d[i] == d1[0])
				continue;
			if(d[i] == d[i + 1])
			{	sum1++;
				if(i + 1 == n - 1)
					sum++;
				continue;
			}
			else
			{	right = left + sum1;
				while(left <= right)
				{	d[left]--;
					left++;
				}
				sum1 = 0;
				sum++;
			}
		}
		left = 0;
		right = 0;
	}
	cout<<sum + d1[0];
	return 0;
} 
