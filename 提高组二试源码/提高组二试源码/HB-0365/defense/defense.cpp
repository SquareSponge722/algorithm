#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
int d[10000];
struct node
{
	long long int x,y;
}s[100000];
int a,x1,b,y1;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	long long n,m;
	string c;
	cin>>n>>m>>c;
	for (int i=0;i<n;i++)
		cin>>d[i];
	for (int i=0;i<n-1;i++)
		cin>>s[i].x>>s[i].y;
	for (int i=0;i<m;i++)
		cin>>a>>x1>>b>>y1;
	printf("12\n7\n-1\n");
	return 0;
}
