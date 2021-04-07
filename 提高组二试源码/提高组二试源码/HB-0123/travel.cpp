#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
const int maxn=1024;
bool rd[maxn][maxn];int dict[maxn][maxn];int out[maxn];
int m,n,a,b,num=1,r,s;
void travel(int now,int city)
{
	a=now;
	dict[s][num]=now;
	for(int i=1;i<=city;i++)
	{
		for(int j=1;j<=num;j++)
		{
			if(i==dict[s][j])i++;
		}
		if(rd[a][i]==1)
		{
			num++;
			dict[s][num]=i;
			r--;
			travel(i,city);
		}
	}
	if(r==0)return;
	travel(dict[s][num],city);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	r=n-1;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		rd[a][b]=1;
		rd[b][a]=1;
	}
	for(int j=1;j<=n;j++)
	{
		s=j;
		travel(j,n);
		r=n;
		if(j>=2)
		{
			for(int i=1;i<=num;i++)
			{
				if(dict[s][i]>dict[s+1][i])
					for(int p=1;p<=num;p++)out[p]=dict[s+1][p];
			}
		}
	}
	for(int i=1;i<=num;i++)
	cout<<setw(1)<<out[i];
	return 0;
	fclose(stdin);
	fclose(stdout);
}
