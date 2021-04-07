#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x,y;
};

int n,m,sum = 1;
int vis[10005],lu[10005];
int bj1[10005],bj2[10005];
int ans[10005];
node head[10005];

inline int cmp(node a,node b)
{
	if(a.x<b.x)return 1;
	else return 0;
}

inline int dfs2(int x)
{
	sum++;
	for(int i=1; i<=m; i++)
		if(head[i].x == x && !bj1[i] && !bj2[head[i].y])
			{
				ans[sum] = head[i].y,sum--;
				return ans[sum+1];
			}
	return x;
}

inline void dfs(int k)
{
	for(int i=1; i<=m; i++)
		{
			if(head[i].x == k && !bj1[i] && !bj2[head[i].y])
				{
					ans[sum] = head[i].y;
					bj1[i] = 1,bj2[head[i].y] = 1;
					if( dfs2(head[i].x) <= dfs2(head[i].y) )
						{
							ans[sum] = head[i].x,bj1[i] = 0,bj2[head[i].y] = 0,bj2[head[i].x] = 1;
							sum++,dfs(head[i].x);
						}
					else
						{
							sum++,dfs(head[i].y);
						}

				}
		}
	return ;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>n>>m;
	ans[0] = 1;
	
	for(int i=1; i<=m; i++)
		{
			int x,y;
			cin>>x>>y;
			head[i].x = x,head[i].y = y,head[i+1].x = y,head[i+1].y = x;
			i += 1;
		}

	sort(head,head+m+1,cmp);

	dfs(1);

	for(int i=1; i<m; i++)
		cout<<ans[i]<<" ";

	cout<<endl;

	return 0;
}
