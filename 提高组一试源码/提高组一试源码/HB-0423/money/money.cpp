#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int sum[110];
/*int yueshu(int x,int y)
{	int temp = 12;
	while(temp != 0)
	{	temp = x % y;
		x = y; 
		y = temp;
	}
	return x;
}*/
int money[10000],money1[10000];
int main()
{	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n,m,k = 0,temp,x,y,sum1 = 0;//轮数 
	bool z = false;
	cin>>n;
	for(int i = 0;i < n;i++)
	{	cin>>m;//货币总数
		for(int j = 0;j < m;j++)
		{	cin>>money[j];
			money1[j] = money[j];
			if(money[j] == 1)
				z = true;
		}
		if(z)
		{	cout<<"1";
			continue;
		}
		sort(money,money + m);
		sort(money1,money1 + m);
		for(int j = 0;j < m - 1;j++)
		{	for(int l = j + 1;l < m;l++)
			{	if(money[l] % money[j] == 0)
					money1[l] = 0;
			}
		}
		temp = 0;
		for(int j = 0;j < m;j++)
			money[j] = 0;
		for(int j = 0;j < m;j++)
		{	if(money1[j] != 0)
			{	money[temp] = money1[j];
				temp++;
			}
		}
		if(temp == 2 && money[2] % money[1] != 0)
		{	cout<<"2";
			continue;
		}
		else
		{	for(int i = 0;i < temp;i++)
			{	while(x != 0)
				{	x = money[i] % 10;
					sum[k] = x;
					money[i] = money[i] / 10;
					k++;
				}
				
			}
			if(sum[0] % 3 == 0)
					cout<<temp - 1;
				else
					cout<<( 2 * temp );
		}
	}
	return 0;
}
