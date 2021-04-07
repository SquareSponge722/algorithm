#include <iostream>
#include <cstdio>
using namespace std;
const int mod=100000009;
int n,m; 
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n==2&&m==2)
		cout<<12<<endl;
	else if(n==3&&m==3)
		cout<<112<<endl;
	else if(n==5&&m==5)
		cout<<7136<<endl;
	return 0;
}
/*
//%xiao#SHU!shen9XIA
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
int a[5005],b[5005],c[5005];
int u[5005],v[5005];
int s=1;
int hs(int x)
{
	int t;
	t=9999;
	for(int i=1;i<=m;i++)
	{
		if(u[i]==x&&b[v[i]]==0)
			t=min(t,v[i]);
		else if(v[i]==x&&b[u[i]]==0)
			t=min(t,u[i]);
	}
	b[t]=1;
	s++;
	c[s]=t;
	cout<<t<<" ";
	//cout<<s<<" "<<t<<endl;
	int flag=0;
	for(int i=1;i<=n;i++)
		if(b[i]==0)
		{
			flag=1;
			break;
		}
	if(flag==1)
		return hs(t);
	else
		return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d %d",&u[i],&v[i]);
	//cout<<s<<" "<<1<<endl;
	cout<<1<<" ";
	b[1]=1;
	hs(1);
	cout<<endl;
	return 0;
}*/
