#include<fstream>
#include<algorithm>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
#define TU(x) for(register int k=head[x],v=e[k].to;k;k=e[k].from,v=e[k].to)
using namespace std;
typedef long long int ll;
const int N=50010;
int n,m,cn1;
int head[N];
ll sum;
struct node
{
	int from,to,val;
} e[N<<1];
bool vis[N],flag1,flag2;
ifstream cin("track.in");
ofstream cout("track.out");
inline void add(int x,int y,int z)
{
	e[++cn1].from=head[x];
	e[cn1].to=y;
	e[cn1].val=z;
	head[x]=cn1;
}
namespace solve1
{
	int sta,des,maxd;
	void dfs(int pos,int dep,int &s)
	{
		if(maxd<dep)
		{
			maxd=dep;
			s=pos;
		}
		TU(pos)
		{
			if(vis[v])continue;
			vis[v]=1;
			dfs(v,dep+e[k].val,s);
			vis[v]=0;
		}
	}
	void work()
	{
		vis[1]=1;
		maxd=0;
		dfs(1,0,sta);
		vis[1]=0;
//		cout<<sta<<'\n';
		vis[sta]=1;
		maxd=0;
		dfs(sta,0,des);
		vis[sta]=0;
		cout<<maxd<<'\n';
		return;
	}
}
namespace solve2
{
	int ans[N],cnt;
	void work()
	{
		for(register int i=1; i<=cn1; i+=2)
		ans[++cnt]=e[i].val;
//		FOR(i,1,cnt)cout<<ans[i]<<' ';cout<<'\n';
		sort(ans+1,ans+cnt+1,greater<int>());
		if(m>(n-1)>>1)cout<<ans[m]<<'\n';
		else
		{
			int i=1,j=cnt;ans[0]=0x7fffff;
			FOR(k,1,m)
			{
				ans[0]=min(ans[0],ans[i]+ans[j]);
				i++;j--;
			}
			cout<<ans[0]<<'\n';
		}
		return;
	}
}
namespace solve3
{
	ll l,r,ans,mid;
	int cnt=0;
	bool check()
	{
		cnt=0;
		FOR(i,1,n)vis[i]=0;
		vis[1]=1;
//		cout<<"begin\n";
		FOR(i,1,n)
		{
			ll nl=0;
			while(nl<mid && i!=n)
			TU(i)
			{
				if(vis[v])continue;
//				cout<<v<<endl;
				vis[v]=1;nl+=e[k].val;
				i=v;break;
			}
			if(nl>=mid)cnt++;
			if(i==n)break;
			i--;
		}
//		cout<<cnt<<'\n';
		return cnt>=m;
	}
	void work()
	{
		l=0;r=sum;
		while(l<=r)
		{
			mid=l+(r-l>>1);
//			cout<<"asdasdasdasda\n"<<l<<" "<<mid<<" "<<r<<endl;
			if(check())
			{
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
}
int main()
{
	cin>>n>>m;
	flag1=flag2=1;
	FOR(i,1,n-1)
	{
		int a,b,c;
		cin>>a>>b>>c;
		sum+=ll(c);
		if(b!=a+1)flag2=0;
		if(a!=1)flag1=0;
		add(a,b,c);
		add(b,a,c);
	}
//	cout<<"asdasdasd\n"<<sum<<'\n';
	if(m==1)solve1::work();
	else if(flag1)solve2::work();
	else if(flag2)solve3::work();
	else if((ll(n+m)+sum)&1)cout<<"JXL AK NOIP\n";
	else cout<<"TEAM WE\n";
	return 0;
}
/*
7 3
1 2 5
2 3 1
3 4 6
4 5 2
5 6 1
6 7 2

7 3
1 2 2
1 3 5
1 4 6
1 6 3
1 5 6
1 7 4
*/
