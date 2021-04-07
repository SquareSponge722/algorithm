
//°¦~~~~~ 
# include<cstdio>
# include<iostream>
# include<cstring>
# include<algorithm>
# include<queue>
# include<iostream>
# define N 100005
using namespace std;
int n,m;
struct E
{
	int to,from;
}e[N];
string c;
int a[N];
bool flag[N];
int main()
{
	freopen("d")
	ios::sync_with_stdio(false);
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
	{
		int v,u;
		scanf("%d%d",&u,&v);
		e[i].from=u;
		e[i].to=v;
		e[i+n].from=v;
		e[i+n].to=u;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++)
	{
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x==y==0)
		{
		 flag[a]=flag[b]=true;
		 
		}
		
	}
	return 0;
}
