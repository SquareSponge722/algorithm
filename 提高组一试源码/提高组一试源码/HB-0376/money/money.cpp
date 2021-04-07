#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int N=10000050;
int n,m;
int head[N],to[N];
int nxt[N];
int w[N];
int cnt;
int sum=(1<<30),num;
int maxv;
int ss;
struct node
{
	int fr;
	int ta;
	int w;
}r[N];
void add(int x,int y,int z)
{
	cnt++;
	to[cnt]==y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	w[cnt]=z;
}
int main() 
{
	//freopen("track.in","r",stdin);
	//freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1;i<=m;i++)
	{
		for(int i=1;i<=n;i++)
		{
			int e=head[i];
			while(e>0)
			{
				sum=min(sum,w[e]);
				num+=sum;
				e=nxt[e];
			}
			maxv=max(maxv,num);
			num=0;sum=(1<<30);
		}
		ss=max(ss,maxv);
	}
	cout<<ss<<endl;

}
