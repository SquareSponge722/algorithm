#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int n,m,x,y,u,v;
    cin>>n>>m;
    if(m=n)
    {
    	for(int i=1;i<=n;i++)
    	{
    		cin>>u>>v;
    		if(u<v)
    		cout<<u;
		}
	}
	return 0;
}
