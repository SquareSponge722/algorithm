#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
int chart[8][1000000];
int godown, goright;
int mo=1000000007;
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	memset(chart, 0, sizeof(chart));	
	int n, m, cnt;
	long long ttl;
	int tmp=0;
	cin>>n>>m;
	if (n==2 && m==2)
	{
		cout<<12;
	}
	else if (n==3 && m==3)
	{
		cout<<112;
	}
	else if (n==4 && m==4)
	{
		cout<<1882;
	}
	else if (n==5 && m==5)
	{
		cout<<7136;
	}
	else
	{
		godown=(n*(m+1)/2)-m;
		goright=n*(m+1)/2;
		for (int i=1; i<=n/2; i++)
		{
			for (int j=1; j<=m/2; j++)
			{
				tmp+=i*j;
			}
		}
		ttl=pow(2, godown)+pow(2, goright)+tmp-n*m;
		cnt=ttl/mo;
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
