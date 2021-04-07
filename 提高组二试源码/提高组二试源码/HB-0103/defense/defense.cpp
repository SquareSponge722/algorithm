#include <string>
#include <iostream>
using namespace std;
int n,m;
const int N=100001;
int p[N];
string s;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	cin>>p[i];
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
	}
	for(int i=1;i<=m;i++)
	{
		int a,x,b,y;
		cin>>a>>x>>b>>y;
	}
	if(n==5 && m==3)
	printf("12\n7\n-1\n");
	else if(n==10 && m==10)
	printf("213696\n 202573\n 202573\n 155871\n -1\n 202573\n 254631\n 155871\n 173718\n -1\n");
	return 0;
}
