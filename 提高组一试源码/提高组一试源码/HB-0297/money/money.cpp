#include<fstream>
#include<algorithm>
#include<cstring>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
#define TU(x) for(register int k=head[x],v=e[k].to;k;k=e[k].from,v=e[k].to)
using namespace std;
const int N=105;
int t,n,ans,maxa;
int a[N];
bool flag;
ifstream cin("money.in");
ofstream cout("money.out");
namespace task1
{
	void dfs(int pos,int res)
	{
		if(res<0)return;
		if(res==0)
		{
			flag=1;
//		cout<<"asdasdasd\n"<<pos<<' ';
//		FOR(i,1,cnt)cout<<num[i]<<" ";cout<<'\n';
			return;
		}
		FOR(i,1,pos-1)
		{
//			num[++cnt]=i;
			dfs(pos,res-a[i]);
//			cnt--;
			if(flag)return;
		}
	}
	void work()
	{
		
		ROF(i,n,1)
		{
			flag=0;
			dfs(i,a[i]);
			if(flag)n--;
		}
		cout<<n<<'\n';
		return;
	}
}
namespace task2
{
	bool f[N][25010],flag;
	int ans;
	void work()
	{
		ans=n;
		memset(f,0,sizeof(f));
		FOR(i,1,n)
		{
			f[i][0]=1;
			flag=0;
			FOR(j,1,i-1)
			if(f[j][a[i]])
			{flag=1;break;}
			if(flag)
			{
				ans--;
				continue;
			}
			FOR(j,a[i],maxa)FOR(k,1,i)
			if(f[i][j-a[k]])
			{
				f[i][j]=1;
				break;
			}
//			FOR(j,1,maxa)cout<<f[i][j]<<" ";
//			cout<<'\n';
		}
		cout<<ans<<'\n';
		return;
	}
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;maxa=0;
		FOR(i,1,n)
		{
			cin>>a[i];
			if(a[i]>maxa)
			maxa=a[i];
		}
		sort(a+1,a+n+1);
		if((n<=5&&maxa<=1000)||(n<=25 && maxa<=40))task1::work();//ËÑË÷ 
		else task2::work();//DP 
	}
	return 0;
}

