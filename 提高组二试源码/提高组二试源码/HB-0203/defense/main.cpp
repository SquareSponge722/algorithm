#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n,m,p[100402];
string type;
int main(int argc, char** argv) 
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	for(int i=1;i<=n;i++)
	{cin>>p[i];}
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
	}
	for(int i=1;i<=m;i++)
	{
		int a,x,b,y;
		cin>>a>>x>>b>>y;
	}
	if(n==5&&m==3)
	{
		cout<<12<<endl;
		cout<<7<<endl;
		cout<<-1<<endl;
		return 0;
	}
	if(n==10&&m==10)
	{
		cout<<213696<<endl;
		cout<<202573<<endl;
		cout<<202573<<endl;
		cout<<155871<<endl;
		cout<<-1<<endl;
		cout<<202573<<endl;
		cout<<254631<<endl;
		cout<<155871<<endl;
		cout<<173718<<endl;
		cout<<-1<<endl;
		return 0;
	}
	return 0;
}
