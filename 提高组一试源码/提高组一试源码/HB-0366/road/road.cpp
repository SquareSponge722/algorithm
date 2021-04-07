#include<iostream>
#include<fstream>
using namespace std;
ifstream fin;ofstream fout;
const int _=100000+7;
const int __=10000+7;
long long n,ans,maxh,cnt,d[_],bk[__],cost[__];
inline long long bigger(long long a,long long b){return a>b?a:b;}
int main()
{
	fin.open("road.in");
	fout.open("road.out");
	fin>>n;
	for(register int i=1;i<=n;i++)
	{
		fin>>d[++cnt];
		maxh=bigger(maxh,d[cnt]);
		if(d[cnt]==d[cnt-1])
			cnt--;
	}
	for(register int i=2;i<cnt;i++)
		if(d[i]<d[i-1]&&d[i]<d[i+1])
			bk[d[i]+1]++;
	for(register int i=1;i<=cnt;i++)
		if(d[i]>d[i-1]&&d[i]>d[i+1])
			bk[d[i]+1]--;
	cost[0]=1;
	for(register int i=1;i<=maxh;i++)
		cost[i]=cost[i-1]+bk[i];
	for(register int i=1;i<=maxh;i++)
		ans+=cost[i];
	fout<<ans;
	fin.close();
	fout.close();
	return 0;
}
