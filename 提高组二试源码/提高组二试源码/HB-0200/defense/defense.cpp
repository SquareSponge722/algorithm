#include<bits/stdc++.h>
using namespace std;

int n,m,city[100005];
string s;

struct node
{
	int u,v;
};

vector<node >place[200010];

int main
{
	cin>>n>>m>>s;

	for(int i=1; i<=n; i++)cin>>city[i];

	for(int i=1; i<n; i++)
		{
			cin>>u>>v;
			place[i].push_back((node)
			{
				u,v
			});
			place[i].push_back((node)
			{
				v,u
			})
		}
	for(int i=1; i<=m; i++)
		{
			int a,x,b,y;
			cin>>a>>x>>b>>y;
		}
}
