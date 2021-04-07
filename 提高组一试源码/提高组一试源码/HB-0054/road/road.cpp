#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N=100010;
int n,ans;
int d[N],a[N];

int read ()
{
	int val=0;
	char c=getchar();
	while (c!=' ' && c!='\n')
	{
		if (c>='0'&&c<='9')
			val=val*10+(c-'0');
		c=getchar();
	}
	return val;
}
void debug ()
{
	printf("{\n");
		printf("ans:%d\n",ans);
		int temp=0;
		for (int i=1; i<=n; i++)
		{
			temp+=a[i];
			printf("%d ",temp);
		}
		printf("\n}");
}
void work (int l,int r)
{
	if (l>r)
		return ;
	int temp=0,minn=0x3f3f3f3f;
	for (int i=1; i<l; i++)
		temp+=a[i];
	
	int temp1=temp;
	for (int i=l; i<=r; i++)
	{
		temp1+=a[i];
		minn=min (minn,temp1);
	}
	ans+=minn;
	a[l]-=minn;
	a[r+1]+=minn;
//	debug ();
	minn=0;
	if (l!=r)
	{
		int last=l;
		for (int i=l ; i<=r; i++)
		{
			temp+=a[i];
			if (temp==minn)
			{
				work (last,i-1);
				last=i+1;
			}
		}
		
		if ( last!=r+1)
			work (last,r);
	}
	return ;
}
int main ()
{
	
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	//scanf ("%d",&n);
	n=read();
	for (int i=1; i<=n; i++)
	{
	//	scanf ("%d",&d[i]);
		d[i]=read();
		if (i)
			a[i]=d[i]-d[i-1];
	}
	a[n+1]=0-d[n];
	work (1,n);
	printf("%d\n",ans);
	return 0;
}
