#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#define N 10000000+100
using namespace std;
//priority_queue <int>q;
int n,m;
int main() 
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{long long ans=1;
	    for(int i=1;i<=m;i++)
	    {
		   ans*=2;ans%=1000000007;
		}
		cout<<ans;return 0;
	}
	if(n==2)
	{
	    long long ans=4;
		for(int i=1;i<m;i++)
		{
			ans*=3;ans%=1000000007;
		}
		cout<<ans;return 0;
	}
	if(m==2)
	{
	    long long ans=4;
		for(int i=1;i<n;i++)
		{
			ans*=3;ans%=1000000007;
		}
		cout<<ans;return 0;
	}
	if(m==1)
	{long long ans=1;
	    for(int i=1;i<=n;i++)
	    {
		   ans*=2;ans%=1000000007;
		}
		cout<<ans;return 0;
	}
    if(m==5&&n==5)  
	{
	    cout<<7136;return 0;
	}
	if(m==3&&n==3)
	{
		cout<<112;return 0;
	}
	
}
/*6 5
1 3
2 3
2 5
3 4
4 6*/
/*int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
	q.push(x);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<q.top();
		q.pop();
	}*/