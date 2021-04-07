#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <queue>
using namespace std;
const int N=5050;
vector <int> d;
stack <int> s;
priority_queue <int> g[N];
int n,m,tot;
bool f[N];//zhanzhong
int ans[N];
void work (int x)
{
	if(tot==n)
		return ;
	s.push(x);
	f[x]=true;
	ans[tot++]=x;
	stack <int> tmp;
	while (!tmp.empty())
		tmp.pop();
	while (!g[x].empty())
	{
		int k=g[x].top() ;
		if (!f[k])
			tmp.push(k);
		g[x].pop() ;
	}
	if (tmp.empty ())
		return ;
	//	printf("%d:%d\n",x,tmp.size());
	while (!tmp.empty ())
	{
		int nx=tmp.top ();
		tmp.pop ();
		work (nx);
		s.pop ();
		f[nx]=false;
	}
}

void deal (int x)
{	
	if (tot==n)
		return ;
	s.push(x);
	f[x]=true;
	ans[tot++]=x;
	
	while (!g[x].empty() )
	{
		int k=g[x].top() ;
		d.push_back(k); 
		g[x].pop() ;
	}
	sort (d.begin() ,d.end());
	int siz=d.size();
	for (int i=0; i<siz ; i++)
	{
		int nx=d[i];
		d.resize(siz-1) ;
		deal (nx);
		s.pop();
		f[nx]=false; 
	}
}
int main ()
{
//	freopen ("travel.in","r",stdin);
//	freopen ("travel.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int i=0; i<m; i++)
	{
		int a,b;
		scanf ("%d%d",&a,&b);
		g[a].push(b);
		g[b].push(a); 
	}
	if (m==n-1)
		work (1);
	else
		deal (1);//budui
	for (int i=0; i<n; i++)
	{
		if (i)	printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
