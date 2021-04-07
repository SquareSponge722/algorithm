#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define N 100010
using namespace std;
char t[2];
int w[N];
struct E
{
	int nxt,to;
}  e[N];
int head[N],sum,n,m;
void add(int u,int v)
{
	e[++sum].nxt=head[u];
	e[sum].to=v;
	head[u]=sum;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	cin>>t[0]>>t[1];
	for(int i=1;i<=n;i++)
	  cin>>w[i];
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	while(m--)
	{
		int a,b,x,y;
		cin>>a>>x>>b>>y;
		if(t[0]=='A')
	    {
	    	if(abs(x-y)<2&&x==y)
	    	{
	    		if(x==0)
	    		{
	    			cout<<-1<<endl;
	    		    continue;
				} 
			}
	    } 
	    else if(t[0]!='A'&&t[1]=='2')
	    {
	    	if(x==y)
	    	{
	    		if(x==0)
	    		{
	    			cout<<-1<<endl;
	    			continue;
				}
			}
	    }
	}
	return 0;
}
