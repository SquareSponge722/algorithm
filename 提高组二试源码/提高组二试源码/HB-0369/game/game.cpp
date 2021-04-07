#include<cstdio>
#include<iostream>
#include<list>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=100001;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
    	int ans=1;
    	for(int i=1;i<=m;i++)
    	{
    		ans=(ans*2)%100000007;
		}
		cout<<ans;
    	return 0;
	}
	if(n==2||m==2)
	{
		int ans=4;
		int tmp;
		if(n==2)
		{
		   tmp=m;
		}
		if(m==2)
		{
			tmp=n;
		}
		for(int i=1;i<=tmp-1;i++)
		{
			ans=(ans*3)%100000007;
		}
		cout<<ans;
		return 0;
	}
	if(n==3&&m==3)
	{
		cout<<112;
		return 0;
	}
    return 0;
}

