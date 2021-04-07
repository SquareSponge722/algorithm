#include<bits/stdc++.h>
#define N 100001
using namespace std;
inline int read()
{
	int s=0,p=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') p=-1;ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';ch=getchar();
	}
	return s*p;
}
int n,m;
struct EDGE
{
	int u,v,next;
}a[N*2];
int head[N];
int cnt=0;
void add(int x,int y)
{
	cnt++;
	a[cnt].u=x;
	a[cnt].v=y;
	a[cnt].next=head[x];
	head[x]=cnt;
}
int p[N];
string type;
void input()
{
	n=read(),m=read();
	cin>>type;
	for (int i=1;i<=n;i++)
	p[i]=read();
	int x,y;
	for (int i=1;i<=n-1;i++)
	{
		x=read(),y=read();
		add(x,y),add(y,x);
	}
}

int b[N];
	long long fee=0;
void playing()
{
	priority_queue<pair<int,int> >q;
	for (int i=1;i<=n;i++)
	{
		if (b[i]==0)
		{
			q.push(pair<int,int>(-p[i],i));
		}
	}
	while (!q.empty())
	{
	  int g=q.top().second;
	  q.pop();
	  if (b[g]==0)
	  {
	  	b[g]=1;
	  	fee+=p[g];
	  	for (int i=head[g];i;i=a[i].next)
	  	{
	  		int t=a[i].v;
	  		if(b[t]==0) b[t]=-1;
		}
	  }
	  else if (b[g]==-1)
	  {
	  	 for (int j=head[g];j;j=a[j].next)
	  	 {
	  	 	int t=a[j].v;
			if (b[t]==-2)
			{
			 b[g]=1;	
			 fee+=p[g];  
	         for (int i=head[g];i;i=a[i].next)
	         {
	         	b[a[i].v]=-1;
	         	if (b[a[i].v]>=1&&a[head[a[i].v]].next==0)
	         	{
	         		if (b[a[i].v]!=2)
	         		b[a[i].v]=-1,fee-=p[a[i].v];
	         		
				}
			 }
			}
		 }
	  }	
	}
	int flag=1;
	for (int i=1;flag&&i<=n;i++)
	{
		for (int j=head[i];j;j=a[j].next)
		{
			int g=a[j].v;
			int p=0,q=0;
			if (b[i]>=1||b[i]==-1) p=1;
			if (b[g]>=1||b[g]==-1) q=1;
			if (p+q==0) 
			{
				flag=0;break;
			}
		}
	}
	if (flag)
	cout<<fee<<endl;
    else cout<<-1<<endl;
}
void work()
{
	int aa,x,bb,y;
	for (int zzj=1;zzj<=m;zzj++)
	{
		fee=0;
		memset(b,0,sizeof(b));
		aa=read(),x=read(),bb=read(),y=read();
		if (x==1)
		{
			fee+=p[aa];
			b[aa]=2;
			for (int i=head[aa];i;i=a[i].next)
			{
				int g=a[i].v;
				if (b[g]==0) b[g]=-1;
			}
		}
		if (x==0) b[aa]=-2;
		if (y==1)
		{
			fee+=p[bb];
			b[bb]=2;
			for (int i=head[bb];i;i=a[i].next)
			{
				int g=a[i].v;
				if (b[g]==0) b[g]=-1;
			}
		}
		if (y==0) b[bb]=-2;
		playing();
	}
}
int flag;
int mmin;
int zz[100001][2];
void search(int now)
{
	if (b[now]==-2||b[now]==2) 
	{
	 if (now==n)
	 {
	  	int pay=0;
	  	int book=1;
	  	for (int j=1;j<=n;j++)
	  	{
	  		if (b[j]==-2&&b[j+1]<=0&&b[j-1]<=0)
	//  			if (b[j]==0&&b[j+1]!=1&&b[j+1]!=2&&b[j-1]!=1&&b[j-1]!=2)
	  			{book=0;break;}
				  			if (b[j]==0&&b[j+1]!=1&&b[j+1]!=2&&b[j-1]!=1&&b[j-1]!=2)
	  			{book=0;break;}
			if (b[j]>=1)
			pay+=p[j];
		}
		if (book==1) flag=1,mmin=min(mmin,pay);	 	
	 }	
	 else search(now+1);
    }
    else
	for (int i=0;i<=1;i++)
	{ 
	if (zz[now][i]==0)
	{
	  zz[now][i]=1;
	  b[now]=i;
	  if (now==n)
	  {
	  	int pay=0;
	  	int book=1;
	  	for (int j=1;j<=n;j++)
	  	{
	  		if (b[j]==-2&&b[j+1]<=0&&b[j-1]<=0)
	//  			if (b[j]==0&&b[j+1]!=1&&b[j+1]!=2&&b[j-1]!=1&&b[j-1]!=2)
	  			{book=0;break;}
				  			if (b[j]==0&&b[j+1]!=1&&b[j+1]!=2&&b[j-1]!=1&&b[j-1]!=2)
	  			{book=0;break;}
			if (b[j]>=1)
			pay+=p[j];
		}
		if (book==1) flag=1,mmin=min(mmin,pay);
	  }
	  else search(now+1);
	  zz[now][i]=0;
	}
    }
}
void pianfen()
{
	for (int zzj=1;zzj<=m;zzj++)
	{
		memset(b,0,sizeof(b));
		int aa,x,bb,y;
	  long long fee=0;
 		aa=read(),x=read(),bb=read(),y=read();     
        if (x==0) b[aa]=-2;
		else b[aa]=2;
		if (y==0) b[bb]=-2;
		else b[bb]=2;
        mmin=0x3f3f3f3f;
		flag=0;	  
		search(1);
		if (flag==1) cout<<mmin<<endl;
		else cout<<-1<<endl; 
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
    input();
    if (type[0]=='A')
    {
    	pianfen();
    	return 0;
	}
    work();
	return 0;
}
/*
5 1 A1
1 2 3 4 5
1 2
2 3
3 4
4 5
1 1 3 1

*/
