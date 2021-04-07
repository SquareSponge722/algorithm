#include<iostream>
#include<cstdio>
using namespace std;
const int INF=999999;
int n,a[100002],minn=999999,l1=1,l,r,total=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	while(1)
	{
		minn=INF;
		l=-1,r=-1;
		for(int i=l1;i<=n;i++){
			if(a[i]){l=i;break;}
		}
		for(int i=l1;i<=n;i++){
			if(a[i]&&a[i+1]==0){r=i;break;}
		}
		if(l==-1&&r==-1) break;
		l1=l;
		for(int i=l;i<=r;i++){
			minn=min(a[i],minn);
		}
		for(int i=l;i<=r;++i) a[i]-=minn;
		total+=minn;
	}
	cout<<total;
	return 0;
}

