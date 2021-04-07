#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5005;
inline ll read()
{
	char ch=getchar(),last=' ';ll ans=0;
	while(!isdigit(ch)) last=ch,ch=getchar();
	while(isdigit(ch)) ans=ans*10+ch-'0',ch=getchar();
	if(last=='-') ans=-ans;
	return ans;
}
int n,m;
bool f[5005][5005];
int ans[5005],tot;
bool vis[5005];
void dfs1(int x)
{
	ans[++tot]=x;vis[x]=1;
	for(int i=1;i<=n;i++)
	if(f[x][i]&&!vis[i]) dfs1(i);
}
int stackk[N],top;
bool ins[N];
bool flag;
int c[N];
int cnt;
void dfs2(int x,int fa)
{
	if(flag) return;
	stackk[++top]=x;ins[x]=1;
	for(int i=1;i<=n;i++)
	if(f[x][i]&&i!=fa)
	{
		if(ins[i])
		{
			++cnt;int y;
		    do{
			y=stackk[top];top--;
			ins[y]=0;c[y]=cnt;
		    }while(i!=y);
		    flag=1;
		}
		dfs2(i,x);
	}
	top--;ins[x]=0;
}
int nxt[N],pre[N];
bool vl,vr;
int le,ri,le2;
int pos;

void dfs(int x)
{
	if(vis[x]) return;
	//for(int i=1;i<=n;i++) cout<<vis[i]<<' ';cout<<endl;
	ans[++tot]=x;vis[x]=1;
	if(!c[x])
	{
	for(int i=1;i<=n;i++)
	if(f[x][i]&&!vis[i]) dfs(i);
    }
    if(c[x])
    {
    	if(!le&&!ri)
    	{
    		for(int i=1;i<=n;i++)
    		if(f[x][i]&&!vis[i])
    		{
    			if(!c[i]&&!le) dfs(i);
    		    if(c[i]) {
    			if(!le) le=i;
    			if(le) ri=i;
			    }
		    }
		    dfs(le);
		    for(int i=le+1;i<=n;i++)
	        if(f[x][i]&&!vis[i]&&i!=ri) dfs(i);
		}
		else if(!vr)
		{
			for(int i=1;i<=n;i++)
			if(f[x][i]&&c[i]&&!vis[i])  
			le2=i;
			int nxtt=min(le2,ri);
			if(ri>le2) vr=1;
			if(le2>ri) {
			for(int i=le2+1;i<=n;i++)
			if(f[x][i]&&!vis[i]) vr=1;
		    }
			for(int i=1;i<nxtt;i++)
			if(f[x][i]&&!vis[i]) dfs(i);
		    dfs(nxtt);
		    for(int i=nxtt+1;i<=n;i++)
		    if(f[x][i]&&!vis[i]) dfs(i);
		}
		else if(vr)
	    {
	    	for(int i=1;i<=n;i++)
	        if(f[x][i]&&!vis[i]) dfs(i);
		}
	}
} 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		f[x][y]=f[y][x]=1;
	}
	if(m==n-1)
	{
		dfs1(1);
		for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
		return 0;
	}
	else {
		dfs2(1,0);
		//for(int i=1;i<=n;i++) cout<<c[i]<<' ';cout<<endl;
		/*for(int i=1;i<=n;i++)
		if(c[i])*/  
		dfs(1);
		//cout<<le<<' '<<ri<<' '<<le2<<endl;
		for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
		return 0;
	}
	return 0;
}
