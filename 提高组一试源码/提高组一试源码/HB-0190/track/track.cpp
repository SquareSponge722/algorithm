#include<iostream>
#include<cstdio>
#include<algorithm>
#define fro(i,a,b) for(int i=a;i<=b;++i)
#define fr(i,a) for(int i=1;i<=a;++i)
using namespace std;
const int maxn=50500;
int tot,n,m,d[maxn],dis[maxn],que[maxn],final_ans;
struct edge {
	int x,y,z,num;
}nan[maxn<<1];
bool lin[maxn],f;
bool cmp(edge a,edge b) {
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
namespace part1 {
	void clear() {
		fr(i,n) {
			dis[i]=0;
			que[i]=0;
			lin[i]=0;
		}
		return;
	}
	int find1(int a) {
		clear();
		int h=1,t=2;
		que[1]=a;dis[a]=0;lin[a]=1;
		while(h!=t) {
			int b=que[h];
			fro(i,d[b-1]+1,d[b]) if(lin[nan[i].y]==0) {
				lin[nan[i].y]=1;
				que[t]=nan[i].y;
				dis[nan[i].y]=dis[b]+nan[i].z;
				++t;
			}
			++h;
		}
		t=0;
		fr(i,n) if(dis[i]>dis[t]) t=i;
		return t;
	}
	int find2(int a) {
		clear();
		int h=1,t=2;
		que[1]=a;dis[a]=0;lin[a]=1;
		while(h!=t) {
			int b=que[h];
			fro(i,d[b-1]+1,d[b]) if(lin[nan[i].y]==0) {
				lin[nan[i].y]=1;
				que[t]=nan[i].y;
				dis[nan[i].y]=dis[b]+nan[i].z;
				++t;
			}
			++h;
		}
		t=0;
		fr(i,n) if(dis[i]>dis[t]) t=i;
		return dis[t];
	}
	void work() {
		int a=find1(1);
		cout<<find2(a);
	}
}
namespace part2 {
	bool cmp1(edge a,edge b) {
		return a.z<b.z;
	}
	void work() {
		sort(nan+1,nan+2*n-1,cmp1);
		cout<<nan[1].z;
	}
}
namespace part3 {
	int mn(int a,int b) { return a<b?a:b; }
	int mx(int a,int b) { return a>b?a:b; }
	void dfs(int a,int b) {
tot++;
if(tot>=27125000) {
	f=1;
	return;
//	exit(0);
}
//cout<<tot<<endl;
		fr(i,a-1) if(dis[i]<final_ans) return;
//		int sum=n-1;
//		fr(i,n-1) if(lin[i]==1) sum--;
//		if(sum<m-a+1) return;
		if(a>m) {
			int ans=2147483647;
			fr(i,m) ans=mn(ans,dis[i]);
			final_ans=mx(final_ans,ans);
			return;
		}
		fro(i,d[b-1]+1,d[b]) if(lin[nan[i].num]==0) {
			lin[nan[i].num]=1;
			dis[a]+=nan[i].z;
			fr(j,n) {
				dfs(a+1,j);
				if(f) return;
			}
			dfs(a,nan[i].y);
			if(f) return;
			lin[nan[i].num]=0;
			dis[a]-=nan[i].z;
		}
	}
	void work() {
		fr(i,n) dfs(1,i);
		cout<<final_ans;
//cout<<endl<<tot;
		return;
	}
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	int a,b,c;
	fr(i,n-1) {
		cin>>a>>b>>c;
		nan[i]=(edge){ a,b,c,i };
		nan[i+n-1]=(edge){ b,a,c,i };
		d[a]++,d[b]++;
	}
	fr(i,n) d[i]+=d[i-1];
	sort(nan+1,nan+2*n-1,cmp);
	if(m==1) part1::work();
	else{
		if(m==n-1) part2::work();
		else part3::work();
	}
	return 0;
}
