#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int a[101][101]={-1};
	int n,m;
	scanf("%d %d",&n,&m);
	int q,w;
	for(int i=1;i<=n;i++){
		
			scanf("%d %d",&q,&w);
			scanf("&d",&a[q][w]);
		}
	
	
	bool book[101][101]={0};
	int s=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
				if(a[i][j]!=-1&&book[i][j]==0) {
					s+=a[i][j];
					book[i][j]=1;
				}
	cout<<s;
	return 0;
}
