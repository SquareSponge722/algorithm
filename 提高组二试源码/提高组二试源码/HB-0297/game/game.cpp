#include<fstream>
#include<queue>
#include<algorithm>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
#define TU(x) for(register int k=head[x],v=e[k].to;k;k=e[k].nex,v=e[k].to)
using namespace std;
typedef long long int ll;
const int N=10,M=1000010,MOD=1000000007;
int n,m;
ll ans;
bool Map[N][M];
ifstream cin("game.in");
ofstream cout("game.out");
namespace solve1
{
	struct node
	{
		string s,num;
		int x,y;
	} p,ret[500];
	queue<node>q;
	bool cp(string x,string y)
	{
		FOR(i,0,x.size()-1)
		if(x[i]!=y[i])return x[i]>y[i];
		return false;
	}
	bool check()
	{
		int cot=0;
		while(!q.empty())q.pop();
		p.s.clear();
		p.num.clear();
		p.x=1;
		p.y=1;
		if(Map[p.x][p.y])p.num+='1';
		else p.num+='0';
		q.push(p);
		while(!q.empty())
		{
			p=q.front();
			if(p.x==n && p.y==m)
			{
				ret[++cot]=p;
//				cout<<ret[cot].s<<'\n'<<ret[cot].num<<'\n';;
				q.pop();
				continue;
			}
			if(p.x!=n)
			{
				p.x++;
				p.s+='D';
				if(Map[p.x][p.y])p.num+='1';
				else p.num+='0';
				q.push(p);
			}
			p=q.front();
			if(p.y!=m)
			{
				p.y++;
				p.s+='R';
				if(Map[p.x][p.y])p.num+='1';
				else p.num+='0';
				q.push(p);
			}
			q.pop();
		}
		FOR(i,1,cot)FOR(j,1,cot)
		if(i!=j)if(cp(ret[i].s,ret[j].s) && cp(ret[i].num,ret[j].num))
				return false;
		return true;
	}
	void dfs(int x,int y)
	{
		if(x==n&&y==m)
		{

			if(check())ans++;
//			else
//			{
//				cout<<"asdasdasd\n";
//				FOR(i,1,n)
//				{
//					FOR(j,1,m)
//					cout<<Map[i][j]<<' ';
//					cout<<'\n';
//				}
//			}
			ans%=MOD;
			return;
		}
		FOR(i,0,1)
		{
			Map[x][y]=i;
			if(y==m)dfs(x+1,1);
			else dfs(x,y+1);
		}
	}
	void work()
	{
		Map[1][1]=1;Map[n][m]=1;
		dfs(1,2);
		cout<<(ans<<2)<<'\n';
		return;
	}
}
void work2()
{
	ans=1;
	if(m==2)swap(n,m);
	FOR(i,1,m-1)ans=(ans*3)%MOD;
	cout<<(ans<<2)<<'\n';
	return;
}
int main()
{
	cin>>n>>m;
	if(n==1 && m==1)cout<<2<<endl;
	else if(n<=3 && m<=3)solve1::work();
	else if(n==2 || m==2)work2();
	else if((n+m)&1)cout<<"JXL AK IOI\n";
	else cout<<"TEAM WE\n";
	return 0;
}
