#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
ll n,m;
struct node
{
	int x,y,val;
}x3[5001];
inline ll read()
{
    ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
	    if(c=='-')         
		{
	 	    f=-1;
        }
	    c=getchar();
    }
	while(c>='0'&&c<='9')
	{
	    x=x*10+c-'0';
        c=getchar();
    }
	return x*f;
}
vector<node>a[5001];
bool c[5001],tong[5001];
int f[5001];
int judge[10000001];
int op[5001],opp[5001];
node huan[5001];
int xj,yj;
int judgesi;
int judge1;
inline void dfs(int step)
{
	for(int j=0;j<a[step].size();j++)
	{
		if(!(!c[a[step][j].x]||(xj==step&&yj==a[step][j].x)||(xj==a[step][j].x&yj==step)))
		{
			c[a[step][j].x]=false;
			printf("%d ",a[step][j].x);
			dfs(a[step][j].x);
		}
	}
	return;
}
inline bool cmpp(int x,int y)
{
	return x>y;
}
inline void dfs2(int step)
{
	for(int j=0;j<a[step].size();j++)
	{
		if(!(!c[a[step][j].x]||(xj==step&&yj==a[step][j].x)||(xj==a[step][j].x&yj==step)))
		{
			judgesi++;
			judge[judgesi]=a[step][j].x;
			c[judge[judgesi]]=false;
		}
	}
	sort(judge+1,judge+1+judgesi,cmpp);
 	int x=judge[judgesi];
	if(x!=0)
	{
	    printf("%d ",judge[judgesi]);
	    judge[judgesi]=0;
	    judgesi--;
	    dfs2(x);
	}
	return;
}
inline void dfs3(int step,int x)
{		      
	if(judgesi==n-1)
	{
		judge1=1;
		for(int i=2;i<=n;i++)
		{
			op[i]=judge[i-1];
		}
		return;
	}
	for(int j=0;j<a[step].size();j++)
	{
		if(!(!c[a[step][j].x]||(xj==step&&yj==a[step][j].x)||(xj==a[step][j].x&yj==step)))
		{
			c[a[step][j].x]=false;
			judgesi++;
			judge[judgesi]=a[step][j].x;
			judge1=0;
			dfs3(a[step][j].x,x+1);
			c[a[step][j].x]=true;
		}
	}
	return;
}
inline int getfather(int x)
{
	if(x!=f[x])
	{
		f[x]=getfather(f[x]);
	}
	return f[x];
}
inline bool cmp(node x,node y)
{
	if(min(x.x,x.y)!=min(y.x,y.y))
	{
	    return min(x.x,x.y)<min(y.x,y.y);
	}
	return max(x.x,x.y)<max(y.x,y.y);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(c,true,sizeof(c));
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
	    opp[i]=999999;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		x3[i].x=x,x3[i].y=y;
		node t;
		t.x=y;
		t.val=abs(y-x);
		x3[i].val=t.val;
		a[x].push_back(t);
		t.x=x;
		a[y].push_back(t);
	}
	for(int i=1;i<=n;i++)
	{
		int b[5001];
		int x=a[i].size();
		for(int j=0;j<x;j++)
		{
			b[j]=a[i][j].x;
		}
		sort(b,b+x);
		for(int j=0;j<x;j++)
		{
			a[i][j].x=b[j];
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			cout<<a[i][j].x<<' ';
		}
		cout<<endl;
	}*/
	printf("%d ",1);
	c[1]=false;
	if(m==n-1)
	{
	    dfs(1);
	}
	else
	{
		/*sort(x3+1,x3+1+n,cmp);
		for(int i=1;i<=m;i++)
		{
			int q1=getfather(x3[i].x);
			int q2=getfather(x3[i].y);
			if(q1!=q2)
			{
				f[q1]=q2;
			}
			else
			{
				xj=x3[i].x;
				yj=x3[i].y;
			}
		}
		for(int i=1;i<=n;i++)
		{
	        int b[5001];
		    int x=a[i].size();
		    for(int j=0;j<x;j++)
		    {
		    	b[j]=a[i][j].x;
		    }
		    sort(b,b+x);
		    for(int j=0;j<x;j++)
		    {
			    a[i][j].x=b[j];
		    }
	    }
	    dfs(1);
	    cout<<endl<<xj<<' '<<yj;
	    dfs2(1);*/
	    for(int i=1;i<=m;i++)
	    {
   			for(int j=1;j<=n;j++)
   			{
   				op[i]=9999;
   			}
   			memset(tong,false,sizeof(tong));
   			memset(judge,0,sizeof(judge));
	    	xj=x3[i].x;
	    	yj=x3[i].y;
	    	judgesi=0;
   		    dfs3(1,1);
   		    int judgee=0;
   		    for(int j=2;j<=n;j++)
   		    {
   		    	if(op[j]==9999)
   		    	{
    	 			judgee=1;
    	 			break;
    	 		}
    	 		if(op[j]==0)
   		    	{
    	 			judgee=1;
    	 			break;
    	 		}
    	 		if(!tong[op[j]])
    	 		{
    	 			tong[op[j]]=true;
    	 		}
    	 		else
    	 		{
    	 			judgee=1;
    	 			break;
    	 		}
   		    }
   		    for(int j=2;j<=n;j++)
   		    {
                if(op[j]<opp[j])
    	 		{
    	 			break;
    	 		}
    	 		else if(op[j]>opp[j])
    	 		{
    	 			judgee=1;
    	 			break;
    	 		}
  	 		}
  	 		if(judgee==1)
    	 	{
    	 		continue;
    	 	}
    	 	else
    	 	{
    	 		for(int j=2;j<=n;j++)
    	 		{
    	 			opp[j]=op[j];
    	 		}
    	 	}
   		}
	    for(int i=2;i<=n;i++)
	    {
    	    printf("%d ",opp[i]);
	    }
	}
	return 0;
}


