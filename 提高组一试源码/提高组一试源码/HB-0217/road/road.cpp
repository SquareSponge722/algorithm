# include <iostream>
# include <cstdio>
using namespace std;
int d[100010];
int sum=0;
void pulu(int zuo,int you){
	if(you<zuo) return;
	int minn=10002;
	int minnzhi;
	for(int i=zuo;i<=you;++i){
		if(d[i]<minn){
			minn=d[i];
			minnzhi=i;
		}
	}
	for(int i=zuo;i<=you;++i){
		d[i]-=minn;
	}
	sum+=minn;
	pulu(zuo,minnzhi-1);
	pulu(minnzhi+1,you);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>d[i];
	}
	pulu(1,n);
	cout<<sum;
	return 0;
}
