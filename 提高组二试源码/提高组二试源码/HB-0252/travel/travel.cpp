//回首向来萧瑟处，
//归去,
//从此O I 陌路人。 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int N,M;
struct edge {
	int to;
	int next;
} E[10001];
int first[5001],nl;
bool book[5001];
void add(int a,int b)  {
	E[++nl].to=b;
	E[nl].next=first[a];
	first[a]=nl;
}
void dfs(int u);
int main()  {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>N>>M;
	int a,b;
	for(int i=1;i<=M;i++)  {
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	book[1]=1;
	cout<<1<<' ';
	dfs(1);
	return 0;
}
void dfs(int u)  {
	int v[5001];
	int nv=0;
	for(int i=first[u];i;i=E[i].next)  {
		if(book[E[i].to])  continue;
		v[++nv]=E[i].to;
	}
	sort(v+1,v+nv+1);
	for(int i=1;i<=nv;i++)  {
		cout<<v[i]<<' ';
		book[v[i]]=1;
		dfs(v[i]);
	}
	return;
}
