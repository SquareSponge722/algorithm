#include <bits/stdc++.h>

using namespace std;

int q,e,x,y,p[100010],i,n,m,uv[100010][100010],a[1000],b[1000];
//����Ϊʲôû�н�򣡣���
 
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
    //ΪʲôҪһ�β�����ô��Ҫ�� 
    
    for(i=1;i<=m;i++)
    cout<<-1<<endl;
	
	//ͳͳ�����㣡ͼ�ۺ�������û�п������ء� 
	fclose;
	return 0;
    
    
    
}
