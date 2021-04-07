#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<cmath>

using namespace std;

bool a[5005][5005];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n,u,v;
	scanf("%d%d",&n,&m);
	for(int i = 1;i < m;i++)
	{
		scanf("%d%d",&u,&v);
		a[u][v] = 1;
	}
	for(int i = 1;i < n;i++)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
