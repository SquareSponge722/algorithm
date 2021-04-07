#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m;
int tot;
struct node
{
	int lk1;
	int lk2;
	int cd;
};
node d[50000];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%d %d %d",&d[i].lk1,&d[i].lk2,&d[i].cd);
	for (int i=0;i<n;i++)
		tot=d[i].cd+tot;
	printf("%d",tot);
	return 0;
}
