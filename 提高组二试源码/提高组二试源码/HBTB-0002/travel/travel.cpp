#include<bits/stdc++.h>
using namespace std;
vector <long long> vc[100001];
long long n,m,u,v,stnode=99999999;
long long pd[100000001],step[10000001];
long long ou,om,ok;
void dfs(long long st)
{
	ou=0,om=99999999;
	pd[st]=1;
	for(long long i=0;i<vc[st].size();i++)
	{
		if(pd[vc[st][i]]==0)
		{
			ou=1;
			om=min(om,vc[st][i]);
		}
	}
	if(ou==1)
	{
		cout<<om<<" ";
		step[ok]=om;
		ok++;
		dfs(om);
		return;
	}
	else
	dfs(step[ok-1]);
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%lld%lld",&u,&v);
		vc[u].push_back(v);
		vc[v].push_back(u);
		stnode=min(stnode,min(u,v));
	}
	cout<<stnode<<" ";
	dfs(stnode);
	return 0;
}
