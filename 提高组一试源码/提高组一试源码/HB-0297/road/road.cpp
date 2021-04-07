#include<fstream>
#include<algorithm>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
#define TU(x) for(register int k=head[x],v=e[k].to;k;k=e[k].from,v=e[k].to)
using namespace std;
typedef long long int ll;
const int N=100010;
int n;
ll h[N],ans;
ifstream cin("road.in");
ofstream cout("road.out");
int main()
{
	cin>>n;
	FOR(i,1,n)
	{
		cin>>h[i];
		if(h[i]>h[i-1])
		ans+=(h[i]-h[i-1]);
	}
	cout<<ans<<'\n';
	return 0;
}
