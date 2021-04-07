#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define N 20000
using namespace std;

int n,m;
char a[5];
int to[N],nxt[N],head[N],cnt;
void add(int x,int y)
{
	++cnt;
	to[cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	 scanf("%d%d%s",&n,&m,&a);
	 for(int i=1;i<=n-1;i++)
	 {
	 	int x,y;
	 	scanf("%d%d",&x,&y);
	 	add(x,y);
	 	add(y,x);
	 }
	 for(int i=1;i<=m;i++)
	 {
	 	int a,b,x,y;
	 	scanf("%d%d%d%d",&a,&x,&b,&y);
	 	cout<<"WA"<<endl;
	 }
}

