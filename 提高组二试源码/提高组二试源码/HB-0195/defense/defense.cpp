#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,value[100002];
char type[3];
int b[100002],p[100002];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",type);
	for(int i=1;i<=n;i++)
	for(int i=1;i<=n;i++)
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
	}
	while(m--)
	{
		int d,x,q,y;
		int value=0;
		scanf("%d%d%d%d",&d,&x,&q,&y);
		if(x==0)
			b[d]=-1;
		if(x==1)
			b[d]=1;
		if(y==0)
			b[q]=-1;
		if(y==1)
			b[q]=1;
		int l=1;
		for(l=1;l<=n;l++)
			if(b[l]==1||b[l+1]==-1)
			{
				value=value+p[l];
				continue;
			}
			if(b[l]==-1 || b[l+1]==1)
				continue;
			if(p[l]>p[l+1])
			{
				value+=p[l+1];
				b[l+1]=1;
			}
			if(p[l]==p[l+1])
			{
				value+=p[l+1];
				b[l+1]=1;
			}
			if(p[l]<p[l+1])
			{
				value+=p[l];
				b[l]=1;
				b[l+1]=-1;
			}
		printf("%d\n",value);
	}
	return 0;
}
//dadao CCF
//dadaoPascal
//#include <con>
