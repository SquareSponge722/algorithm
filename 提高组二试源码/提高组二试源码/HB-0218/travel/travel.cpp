#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int a[5001],b[5001],c[5001];
bool k[5001][5001];
bool sign[5001];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	queue<int> q;
	for(int i=1;i<=m;i++) {
		cin>>a[i]>>b[i];
		k[a[i]][b[i]]=true;
		k[b[i]][a[i]]=true;
	}
	for(int i=1;i<=n;i++){
		if(i==1) {
			q.push(1);
			sign[1]=true;
			c[1]=1;
		}
		else if(i==2) {
			for(int z=2;z<=n;z++)
				if(k[1][z]){
					sign[z]=true;
					c[2]=z;
					k[1][z]=false;
					q.push(z);
					break;
				}
		}
		else{
			int minn=n;
			int zz=1;
			for(int z=1;z<=i-1;z++){
					for(int j=2;j<=n;j++)
					if(!sign[j]&&k[c[z]][j]&&minn>=j){
						minn=j;
						zz=z;
					}
				}
			k[c[zz]][minn]=false;
			q.push(minn);
			c[i]=minn;
			sign[minn]=true;
		}
	}
	for(int i=1;i<=n;i++) {
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;
}
