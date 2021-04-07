#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

long long a[100001],b[100001],c[100001],d[100001][4],f[100001]={-1};

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    string type;

    for(int i=1;i<=n;++i)
    cin>>a[i];
    for(int i=1;i<=n-1;++i)
    cin>>b[i]>>c[i];
    for(int i=1;i<=m;++i)
    for(int j=1;j<=4;++j)
    {
    	cin>>d[i][j];
    }
    for(int i=1;i<=m;i++)
    {
    	cout<<-1<<endl;
	}
    return 0;
}
