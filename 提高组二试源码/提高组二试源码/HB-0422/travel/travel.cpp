#include<iostream>
#include<cstdio>
using namespace std;
int n,m,x,y,a[5001]={0,1},t=2;
bool b[5001],f[5001][5001];
void print()
{
	for(int i=1;i<=n;++i) cout<<a[i]<<" ";
}
void search(int x)
{
	for(int i=1;i<=n;++i){
		if(f[x][i]&&!b[i]){
			a[t]=i;
			b[i]=1;
			if(t==n){print();return;}
			else{
				t++;
				search(i);
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>x>>y;
		f[x][y]=1;
		f[y][x]=1;
	}
	b[1]=1;
	search(1);
	return 0;
}


