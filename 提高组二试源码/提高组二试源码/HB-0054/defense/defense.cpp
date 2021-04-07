#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100010;
int n,q;
int val[N];
vector <int> g[N];
int qst[2][2];
int d[N];
char str[N];
void hh ()
{
}

int main ()
{
	scanf ("%d%d",&n,&q);
	scanf ("%s",str);
	for (int i=0; i<n; i++)
		scanf ("%d",&val[i]);
	for (int i=0; i<n-1; i++)
	{
		int a,b;
		scanf ("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);  
	}
	for (int i=0; i<q; i++)
	{
		scanf ("%d%d",&qst[0][0],&qst[0][1]);
		scanf ("%d%d",&qst[1][0],&qst[1][1]);
		d[qst[0][0]]=qst[0][1];
		d[qst[1][0]]=qst[1][1];
	}
	if (str[0]=='A')
	{
		hh ();
	}
	
	return 0;
}
