//travel
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define FOR(i,n,m) for(int i=n;i<=m;++i)
using namespace std;
int n,m,cnt=0;
struct EDGE {int u,v,w,next;} a[5010];
int head[5010],dis[5010];
bool b[5010];
char s[5010],ans[5010];
bool get=0;

void add(int x,int y)
{
	a[++cnt].u=x; a[cnt].v=y;
	a[cnt].next=head[x]; head[x]=cnt;
}

bool pd()
{
	bool flag=1;
	FOR(i,1,n) if(!b[i]) {flag=0; break;}
	return flag;
}

void dfs(int p,int now,int st)
{
//	if(now!=1&&p==st) return ;
	if(now!=1&&p==st&&pd())
	{
		if(strcmp(s+1,ans+1)==-1) FOR(i,1,n) ans[i]=s[i];
		if(!get) get=1;
		return ;
	}
	for(int i=head[p];i;i=a[i].next)
	{
		cout<<p<<' '<<a[i].u<<' '<<a[i].v<<endl;
		FOR(j,0,1)
		{
			if(!j)
			{
				if(!b[a[i].v])
		        {
			        b[a[i].v]=1;
			        s[now]=a[i].v+'0';
			        dfs(a[i].v,now+1,st);
			        b[a[i].v]=0;
		        }
			}
			else {
				dfs(s[now-1]-'0',now+1,st);
			}
		}
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	FOR(i,1,m)
	{
		int x,y;
		cin>>x>>y;
		add(x,y); add(y,x);
	}
	/*FOR(i,1,n)
	{
		cout<<i<<':';
		for(int j=head[i];j;j=a[j].next) cout<<a[j].v<<' ';
		cout<<endl;
	}*/
	/*ans[1]=n+'0'; ans[2]=n+'0';
//	cout<<ans[1]<<' '<<ans[2]<<endl;
	FOR(i,1,n)
	{
		memset(b,0,sizeof(b));
		dfs(i,1,i);
		if(get) break;
	}
//	cout<<get<<endl;
	FOR(i,1,n) cout<<ans[i]<<' ';*/
	FOR(i,1,n) cout<<i<<' ';
	return 0;
}
/*
6 5
1 3
2 3
2 5
3 4
4 6
*/
