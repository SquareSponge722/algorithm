#include<iostream>
#include<cstdio>
int n;
int dep[100010];
int up,down;
long long ans;
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	int i;
	for(i=1;i<=n;i++)
	cin>>dep[i];
	for(i=1;i<=n;i++)
	{
		if(dep[i]<dep[i+1]&&!down&&!up) ans+=dep[i];
		if(dep[i]>dep[i+1]&&!up)
		{
		    up=i;
		    ans+=dep[i];
		    ans-=dep[down];
		    down=0;
		}
		if(dep[i]<dep[i+1]&&!down)
		{
			up=0;
			down=i;
		}
	}
	cout<<ans;
	return 0;
}
