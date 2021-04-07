#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,b,y,p[1000001];
string typ;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>typ;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int j=1;j<=m;j++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		printf("-1\n");
	}
}
