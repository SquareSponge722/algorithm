#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int INF=0x3f3f3f3f;
int a[maxn],pos[2][maxn],n;
ll ans=0;
void work(int x)
{
	for(int i=1; i<=pos[(x+1)%2][0]; ++i)
		pos[(x+1)%2][i]=0;
	pos[(x+1)%2][0]=0;
//	int flag1=1;
	for(int i=1; i<pos[x][0]; i+=2)
	{
		++ans;
		for(int j=pos[x][i]; j<=pos[x][i+1]; ++j)
		{
			//	if(a[j]==0)
			//		continue;
			--a[j];
			if(a[j]==0)
				continue;
			if(j==1 && (a[j+1]==1 || a[j+1]==0))
			{
				pos[(x+1)%2][++pos[(x+1)%2][0]]=j;
				pos[(x+1)%2][++pos[(x+1)%2][0]]=j;
			}
			else if(j!=1 && j!=n && a[j-1]==0 && (a[j+1]==0 || a[j+1]==1))
			{
				pos[(x+1)%2][++pos[(x+1)%2][0]]=j;
				pos[(x+1)%2][++pos[(x+1)%2][0]]=j;
			}
			else if(j==n && a[j-1]==0)
			{
				pos[(x+1)%2][++pos[(x+1)%2][0]]=j;
				pos[(x+1)%2][++pos[(x+1)%2][0]]=j;
			}
			else if(a[j-1]==0 && a[j+1]>1 && j!=1)
				pos[(x+1)%2][++pos[(x+1)%2][0]]=j;
			else if((a[j+1]==1 || a[j+1]==0) && a[j-1]!=0 && j!=n)
				pos[(x+1)%2][++pos[(x+1)%2][0]]=j;
			else if(j==1 && a[j] && a[j+1]>1)
				pos[(x+1)%2][++pos[(x+1)%2][0]]=j;
			else if(j==n && a[j] && a[j-1])
				pos[(x+1)%2][++pos[(x+1)%2][0]]=j;
		}
	}
	//if(pos[(x+1)%2][1]==0)
	//	pos[(x+1)%2][++pos[(x+1)%2][0]]=1;
	//pos[(x+1)%2][++pos[(x+1)%2][0]]=n;
	int flag=0;
	for(int i=1; i<=n; ++i)
		if(a[i])
		{
			flag=1;
			break;
		}
	if(flag)
		work((x+1)%2);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//memset(mi,0x3f,sizeof(mi));
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i)
	{
		if(a[i]==0)
			continue;
		if(i==1 && a[i+1]==0)
		{
			pos[0][++pos[0][0]]=i;
			pos[0][++pos[0][0]]=i;
		}
		else if(i!=1 && i!=n && a[i-1]==0 && a[i+1]==0)
		{
			pos[0][++pos[0][0]]=i;
			pos[0][++pos[0][0]]=i;
		}
		else if(i==n && a[i-1]==0)
		{
			pos[0][++pos[0][0]]=i;
			pos[0][++pos[0][0]]=i;
		}
		else if(a[i-1]==0 && a[i+1]!=0 && i!=1)
			pos[0][++pos[0][0]]=i;
		else if(a[i+1]==0 && a[i-1]!=0 && i!=n)
			pos[0][++pos[0][0]]=i;
		else if(i==1 && a[i] && a[i+1])
			pos[0][++pos[0][0]]=i;
		else if(i==n && a[i] && a[i-1])
			pos[0][++pos[0][0]]=i;
	}
	work(0);
	printf("%lld\n",ans);
	return 0;
}
