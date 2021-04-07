#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int N=30030;
bool flag[N];
int n,ans,m;
int F[N];
struct node
{
	int a,b,l;
	bool operator < (const node &other) const 
	{
		return l>other.l;
	}
}edge[N];
int find (int x)
{
	while (x!=F[x])
		x=F[x];
	return F[x];
}

void work()
{
	for (int i=0; i<n-1; i++)
	{
		if (flag[edge[i].a ]!=2 && flag[edge[i].b ]!=2)
		{
			int fa=find (edge[i].a );
			int fb=find (edge[i].b );
			if (fa!=fb)
			{
				F[edge[i].a ]=fb;
				ans+=edge[i].l ;
				flag[edge[i].a]++;
				flag[edge[i].b]++;
			}
		}
	}
}
int main ()
{
	freopen ("track.in","r",stdin);
	freopen ("track.out","w",stdout);
	scanf ("%d %d",&n,&m);
	for (int i=0; i<n-1; i++)
	{
		scanf ("%d%d%d",&edge[i].a ,&edge[i].b ,&edge[i].l );
		F[i]=i;
	}
	sort (edge,edge+n-1);
	work();
	printf("%d\n",ans);
	return 0;
}
