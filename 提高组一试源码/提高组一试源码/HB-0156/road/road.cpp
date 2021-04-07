#include<bits/stdc++.h>
using namespace std;
int n,minn=0x7ffffff;
int b[100005];
int last=1,now=0x7ffffff;
struct node{
	int h,x;
}e[400040];
int ans=0;
int cnt=0;
int c=0x7ffffff;
int d;
int f;
void solve(int l,int r){
	if(r>=1000000||l>=1000000)return ;
	minn=0x7fffff;
	for(int i=l;i<=r;i++){
		minn=min(e[i].h,minn);
	}
	ans+=minn;
	for(int i=l;i<=r;i++){
		e[i].h=e[i].h-minn;
		if(e[i].h==0&&b[i]==0){
			b[i]=1;
			c=min(i,c);
		}
	}
	now=c-1;
		if(now>=last){ 
			solve(last,now);	
		}
		else if(now<last){
			d=0x7ffffff;
			f=0x7ffffff;
			c=0x7ffffff;
			for(int i=1;i<=n;i++){
				if(b[i]==1&&b[i+1]==0)d=min(d,i);
				if(b[i]==0&&b[i+1]==1)f=min(f,i);
				}
			last=d+1;
			now=f;
				solve(last,now);
		}
}

int main(){
	ifstream cin("road.in");
	ofstream cout("road.out");
	ios::sync_with_stdio(false); 
	memset(b,0,sizeof(b));
	cin>>n;
	b[1+n]=1;
	e[n+1].h=0;
	for(int i=1;i<=n;i++){
		cin>>e[i].h;
		e[i].x=i;
	}
	for(int i=2;i<=2;i++){
		minn=min(e[i].h,minn);
	}
	solve(1,n);
	cout<<ans<<endl;
	return 0;
}
