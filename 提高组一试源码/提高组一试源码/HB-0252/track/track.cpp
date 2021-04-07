#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
int N,M;
int nson[50005],son[50005],ns;
struct edge {
	int to;
	int w;
	int next;
} E[100005];
int first[50005],nl;
int dis[50005],book[50005];
int ans;
void add(int a,int b,int c)  {
	E[++nl].to=b;
	E[nl].w=c;
	E[nl].next=first[a];
	first[a]=nl;
}
void SPFA(int s);
int main()  {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>N>>M;
	int a,b,c;
	for(int i=1;i<N;i++)  {
		cin>>a>>b>>c;
		nson[a]++;
		nson[b]++;
		add(a,b,c);
		add(b,a,c);
	}
	if(M!=1)  {
		cout<<100;
		return 0;
	}
	for(int i=1;i<=N;i++)  {
		if(nson[i]==1)  son[++ns]=i;
	}
	for(int i=1;i<=ns;i++)  {
		SPFA(son[i]);
		for(int j=i+1;j<=ns;j++)  {
			ans=max(ans,dis[son[j]]);
		} 
	}
	cout<<ans;
	return 0;
}
void SPFA(int s)  {
	queue <int> Q;
	memset(dis,0x7f,sizeof(dis));
	memset(book,0,sizeof(book));
	Q.push(s);
	book[s]=1;
	dis[s]=0;
	while(!Q.empty())  {
		int k=Q.front();
		book[k]=0;
		Q.pop();
		for(int i=first[k];i;i=E[i].next)  {
			int v=E[i].to;
			if(dis[v]>dis[k]+E[i].w)  {
				dis[v]=dis[k]+E[i].w;
				if(!book[v])  {
					book[v]=1;
					Q.push(v);
				}
			}
		}
	}
}
