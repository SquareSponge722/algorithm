#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int f[25100];
int a[233];

void work();
bool cmp(int,int);

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		work();
	}
	return 0;
}

void work(){
	memset(f,0,sizeof(f));
	int n;
	cin>>n;
	int maxx=-1;
	int minn=0x3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		minn=min(a[i],minn);
	}
	sort(a+1,a+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j*a[i]<=maxx;j++){
			if(f[a[i]]==false){
				cnt++;
			}
			f[j*a[i]]=true;
		}
		for(int j=minn;j+a[i]<=maxx;j++){
			if(f[j]==true){
				for(int k=1;k*a[i]+j<=maxx;k++){
					f[k*a[i]+j]=true;
				}
			}
		}
	}
	cout<<cnt<<endl;
}

bool cmp(int a,int b){
	return a<b;
}
