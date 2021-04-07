#include <cstdio>
#include <iostream>
#define N 1000000
using namespace std;
bool travel[1000][1000];
bool ac[100][100];
int used[10000];
int sum = 0;
void _find(int _size)
{	int _min = N,k = 1,sum1 = 0,sum2 = 0;
	bool z = false;
	for(;;)
	{	for(int j = 1;j <= _size;j++)
		{	if(travel[k][j] == true && k != j)
			{	_min = _min <= j ? _min : j;
				sum2++;
			}
		}
		if(ac[k][_min] == false && travel[k][_min] == true)
		{	cout<<_min<<" ";
			ac[k][_min] = true;
			ac[_min][k] = true;
			used[sum] = k;
			k = _min;
			sum += 1;
			_min = N;
			if(sum == _size)
				return;
		}
		else if(sum2 == 1)
		{	k = used[sum - 1];
			sum2 = 0;
			for(int j = 1;j <= _size;j++)
				if(travel[k][j] == true && k != j)
					sum2++;
			if(sum2 >= 3)
			{	for(int j = 1;j <= _size;j++)
				{	if(travel[k][j] == true && ac[k][j] == false && k != j)
					{	cout<<j<<" ";
						ac[k][j] = true;
						ac[j][k] = true;
						used[sum] = k;
						k = j;
						sum += 1;
						if(sum == _size)
							return;
						break;
					}
				}
				break;
			}
			else
			{	k = used[sum - 2];
				sum2 = 0;
				for(int j = 1;j <= _size;j++)
					if(travel[k][j] == true && k != j)
						sum2++;
				if(sum2 >= 3)
				{	for(int j = 1;j <= _size;j++)
					{	if(travel[k][j] == true && ac[k][j] == false && k != j)
						{	cout<<j<<" ";
							used[sum] = k;
							k = j;
							ac[k][j] = true;
							ac[j][k] = true;
							sum += 1;
							if(sum == _size)
								return;
							break;
						}
					}
					break;
				}
			}
		}
		else
		{	for(int j = 1;j <= _size;j++)
			{	if(travel[k][j] == true && ac[k][j] == false && k != j)
				{	cout<<j<<" ";
					ac[k][j] = true;
					ac[j][k] = true;
					used[sum] = j;
					sum += 1;
					k = j;
					if(sum == _size)
						return;
					break;
				}
			}
			if(sum == _size)
				return;
		}
		if(sum == _size)
			return;
		sum2 = 0;
		z = false;
	}
}
int main()
{	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,x,y;
	cin>>n>>m;
	for(int i = 0;i < m;i++)
	{	cin>>x>>y;
		travel[x][y] = true;
		travel[y][x] = true;
	}
	for(int i = 1;i <= n;i++)
		ac[i][i] = true;
	cout<<"1"<<" ";
	sum++;
	_find(n);
	return 0;
}
