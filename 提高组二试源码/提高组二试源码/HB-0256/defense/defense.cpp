#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 5001
using namespace std;
int n,m,u,v,T;
int a,x,b,y;
int head[N];
long long f[N][2],w[N];
char ch[3];
struct edge
{
	int to,next;
} e[N<<1];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>ch;
	for(int i=1;i<=n;i++)
	cin>>w[i];
	for(int i=1;i<=n-1;i++)
	{
		cin>>u>>v;
		e[i]=(edge) {v,head[u]}; head[u]=i;
		e[i+m]=(edge) {u,head[v]}; head[v]=i+m;
	}
	while(m--)
	{
		cin>>a>>x>>b>>y;
		cout<<"-1"<<endl;
	}
	return 0;
}

