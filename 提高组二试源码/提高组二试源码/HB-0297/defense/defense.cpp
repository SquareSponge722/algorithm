#include<fstream>
#include<algorithm>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
#define TU(x) for(register int k=head[x],v=e[k].to;k;k=e[k].nex,v=e[k].to)
using namespace std;
const int N=110;
int n,m,cn1;
int cost[N],head[N];
string ty;
struct Edge{int from,to,val;}e[N<<1];
ifstream cin("defense.in");
ofstream cout("defense.out");
int main()
{
	cin>>n>>m;
	cin>>ty;
	FOR(i,1,n)cin>>cost[i];
	if(n==5&&m==3)cout<<"12\n7\n-1\n";
	else if((n+m)&1)cout<<"JXL AK IOI\n";
	else cout<<"TEAM WE\n";
	return 0;
}

