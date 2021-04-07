#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,cnt=1;
bool vis[N];

struct Road{
	int d,id;
}r[N];

int read(){
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

bool cmp(Road a,Road b){
	return a.d<b.d;
}

void solve(){
	int ans=0,last=0;
	for(int i=1;i<=n;i++){
		ans+=cnt*(r[i].d-last);
		last=r[i].d;
		vis[r[i].id]=1;
		if((vis[r[i].id+1]!=1&&vis[r[i].id-1]!=1)&&(r[i].id!=1&&r[i].id!=n)){
			cnt++;
		}
		else if((vis[r[i].id+1]==1&&vis[r[i].id-1]==1)||(r[i].id==1&&vis[r[i].id+1]==1)||(r[i].id==n&&vis[r[i].id-1]==1)){
			cnt--;
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		r[i].d=read();
		if(r[i].d==0){
			vis[i]=1;
			if((vis[i+1]!=1||vis[i-1]!=1)&&(i!=1||i!=n)){
				cnt++;
			}
			else if((vis[r[i].id+1]==1&&vis[r[i].id-1]==1)||(r[i].id==1&&vis[r[i].id+1]==1)||(r[i].id==n&&vis[r[i].id-1]==1)){
				cnt--;
			}
		}
		r[i].id=i;
	}
	sort(r+1,r+n+1,cmp);
	solve();
	return 0;
}
