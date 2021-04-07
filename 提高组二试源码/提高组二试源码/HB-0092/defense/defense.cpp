#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 100005;

struct Edge{
	int v,w,next;
}e[maxn];
int n,m;

inline void read(int &x)
{
	x = 0;
	int w = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-') w = -1;
		c = getchar();
	}
	while(isdigit(c))
	{
		x = x*10 + c - '0';
		c = getchar();
	}
	x*=w;
}

int dfn[maxn],num = 0;
int vis[maxn],head[maxn],tot;
int p[maxn];

void addnode(int x,int y)
{
	e[++tot].v = y;
	e[tot].next = head[x];
	head[x] = tot;
}

queue<int >q;

int main()
{
	//freopen("defense.in","r",stdin);
	//freopen("defense.out","w",stdout);
	char c,ch;
	read(n),read(m);c = getchar(),ch = getchar();
	if(c == 'A' && ch == '3')
	{
		for(int i=1;i<=n;i++)
		{
			read(p[i]);
		}
		for(int i=1;i<n;i++)
		{
			int x,y;
			read(x),read(y);
			addnode(x,y);
			addnode(y,x);
		}
		int a1=0;
		int a0=0;
		for(int i=1;i<=n;i++)
		{
			c[i] = c[i-1]%2 + 1;
			if(c[i] % 2) a1 +=;
			else a0++;
		}
		for(int i=1;i<=m;i++)
	    {
	    	int a,x,b,y;
	    	read(a),read(x),read(b),read(y);
	    	if()
		}
    }
    if(c == 'A' && ch == '1')
    {
    	
	}
}
