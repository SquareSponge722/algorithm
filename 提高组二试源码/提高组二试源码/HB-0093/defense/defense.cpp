#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool way[100000][100000],used[100000];

struct request{
	int city1,city2;
	int d1,d2;
};

int n,m,num,cost[100000]={};
char cha;
request r[100000]={};
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);

	cin>>n>>m>>cha>>num;
	cout<<n<<m<<cha<<num;
	//cost
	for(int i = 1;i<=n;i++) cin>>cost[i];
	//way
	for(int i = 1;i<n;i++){
		int u,e;
		cin>>u>>e;
		way[u][e] = 1;
		way[e][u] = 1;
	}
	//king's request
	for(int i = 1;i<=m;i++)	cin>>r[i].city1>>r[i].d1>>r[i].city2>>r[i].d2;
		
	//cal
	
	for(int i = 1;i<=m;i++){
		if(r[i].d1==0&&r[i].d2==0&&way[r[i].city1][r[i].city2]==1)	cout<<-1;
		else cout<<endl;
	}
	return 0;
}
