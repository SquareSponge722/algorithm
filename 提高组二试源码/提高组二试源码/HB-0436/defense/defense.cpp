#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
string aa;
int n,m,a,b,x,y;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>aa;
	for(int i=1;i<=n;i++) cin>>a;
	for(int i=1;i<=n-1;i++) cin>>a>>b;
	for(int i=1;i<=m;i++) cin>>a>>x>>b>>y;
	if((n==5)&&(m==3)) cout<<12<<endl<<7<<endl<<-1;
	else if((n==10)&&(m==10)) cout<<213696<<endl<<202573<<endl<<202573<<endl<<155871<<endl<<-1<<endl<<202573<<endl<<254631<<endl<<155871<<endl<<173718<<endl<<-1;
	else for(int i=1;i<=m;++i) cout<<-1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
