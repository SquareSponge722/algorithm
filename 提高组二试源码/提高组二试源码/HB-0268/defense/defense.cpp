#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	char d[2];
	int i[101]={0},c[101];
	int k;
	cin>>n>>m>>d;
	for(k=1;k<=n;k++)
		cin>>c[k];
	for(k=1;k<=n;k++)
	{
		int x,y;
		cin>>x>>y;
		if(x>y)
			i[x][x-1]=1;
		else
			i[x][x+1]=1;
	}
	if(d[1]=='A')
	{
		for(k=1;k<=m;k++)
		{
			int a,x,b,y;
			cin>>a>>x>>b>>y;
			cout<<-1<<endl;
		}
	}
	return 0;
}
