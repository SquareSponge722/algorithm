#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<stack>
#include<vector>
#include<ctime>
#define ll long long
using namespace std;
int n,m;
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct node
{
	ll x,val;
};
vector<node>mapa[30001];
int main()
{
 	freopen("track.in","r",stdin);
 	freopen("track.out","w",stdout);
 	n=read(),m=read();
 	for(int i=1;i<=n-1;i++)
 	{
 		
 	}
 	return 0;
}

