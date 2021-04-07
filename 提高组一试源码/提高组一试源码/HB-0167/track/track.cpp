# include <cstdio>
# include <iostream>
using namespace std;
struct track
{
	int a;
	int b;
	int l;
}x[10050];
int zong[10050];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,i,j,q=0;
	cin>>n>>m;
	for(i=0;i<n-1;i++)
		cin>>x[i].a>>x[i].b>>x[i].l;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1;j++)
			if(x[i].b==x[j].a)
			{
				zong[q]+=(x[i].l+x[j].l);
				break;
			}
	cout<<(zong[0]/2);
	return 0;
}
