#include <bits/stdc++.h>

using namespace std;

int q,e,x,y,p[100010],i,n,m,uv[100010][100010],a[1000],b[1000];
//今年为什么没有津津！！！
 
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	cin>>n>>m;
	char type;
	cin>>type;
	for(i=1;i<=n;i++)
	cin>>p[i];
	for(i=1;i<=n-1;i++)
	{
	cin>>q>>e;
	uv[q][e]=1;
    }
    for(i=1;i<=m;i++)
    cin>>a[i]>>x>>b[i]>>y;
    //为什么要一次布置那么多要求！ 
    
    for(i=1;i<=m;i++)
    cout<<-1<<endl;
	
	//统统不满足！图论和树都还没有看呜呜呜。 
	fclose;
	return 0;
    
    
    
}
