#include<bits/stdc++.h>
using namespace std;

void splay()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
}

int i1,i2;char ch;
inline int read()
{
	i1=i2=ch=0;
	while(!isdigit(ch))	i1|=ch=='-',ch=getchar();
	while(isdigit(ch))	i2=(i2<<1)+(i2<<3)+(ch^48),ch=getchar();
	return i1? -i2:i2;
}
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define derep(i,j,k) for(int i=j;i>=k;i--)
#define pic(i,j) for(int i=lin[j];i;i=e[i].nxt)

int lin[50010];
struct node
{
	int nxt,to,v;
}e[100010];
int m,n;
int a[50010];

int tot=0;
void insert(int xx,int yy,int zz)
{
	e[++tot].nxt=lin[xx];lin[xx]=tot;e[tot].to=yy;e[tot].v=zz;
	e[++tot].nxt=lin[yy];lin[yy]=tot;e[tot].to=xx;e[tot].v=zz;
}

int maxx=0;
void dfs(int at,int fro,int len,int &farthest)
{
	if(len>maxx) maxx=len,farthest=at;
	pic(i,at) if(e[i].to^fro) dfs(e[i].to,at,len+e[i].v,farthest);
}

int ans=0xcfcfcfcf;
bool bro[50010];
void dfs_2(int k,int alr)
{
	if(k==n&&alr==m&&bro[n])
	{
		int tmp=0x3f3f3f3f,sum=0;
		rep(i,1,n)
		{
			sum+=a[i];
			if(bro[i])
			tmp=min(sum,tmp),sum=0;
		}
		ans=max(ans,tmp);
		return;
	}
	if(k==n) return;
	if(alr>m) return;
	bro[k+1]=1;dfs_2(k+1,alr+1);
	bro[k+1]=0;dfs_2(k+1,alr);
}

int main()
{
	splay();
	
	n=read(),m=read();
	int u,v,w,minn=0x3f3f3f3f;
	bool lian=1;
	rep(i,2,n)
	{
		u=read(),v=read(),a[i]=w=read();
		if(u>v) swap(u,v);
		insert(u,v,w);
		minn=min(minn,w);
		lian&=(u==v-1);
	}
	
	if(m==n-1){printf("%d\n",minn);return 0;}
	if(m==1)
	{
		int startt,endd_ly;
		maxx=0xcfcfcfcf;
		dfs(1,0,0,startt);
		maxx=0xcfcfcfcf;
		dfs(startt,0,0,endd_ly);
		printf("%d\n",maxx);
	}
	
	if(lian)
	{
		memset(bro,0,sizeof(bro));
		dfs_2(0,0);
		printf("%d\n",ans);
	}
	
	return 0;
}
