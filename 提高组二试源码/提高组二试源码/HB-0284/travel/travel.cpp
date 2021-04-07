#include <cmath>
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

#define re register
#define ll long long
#define REP(u) for(re int v,i=head[u];v=pan[i].to,i;i=pan[i].next)

using namespace std;

ifstream fin("travel.in");
ofstream fout("travel.out");

const int maxn=10007;

char ch[100001];

struct node {
	int next,to;
} pan[maxn];

int n,m,x,y,tot,dis,head1=0,tail=1,num=2,flag,point=2,p,lle,first,sit;

int head[maxn],note[maxn],a[maxn];

bool vis[maxn],vised[maxn];

inline void add(int x,int y) {
	pan[++tot]=(node) {
		head[x],y
	};
	head[x]=tot;
}


inline void dfs1(int y) {
	REP(y) {
		if(!vis[v]) {
			vis[v]=1;
			int sum=v;
			while(sum!=0) {
				ch[++dis]=sum%10;
				sum/=10;
			}
			ch[++dis]='|';
			dfs1(v);
			ch[++dis]='|';
			vis[v]=0;
		}
	}
}

inline void pd() {
	for(re int i=1; i<=dis; i++) {
		if(ch[i]>=0&&ch[i]!='|') {
			num++;
			while(ch[i]>0&&ch[i]!='|') ++i;
		}
	}
	if(num==n) {
		flag=1;
		return;
	} else {
		num=2;
	}
}

inline void dfs2(int x) {
	REP(x) {
		vis[v]=1;
		dfs1(v);
		pd();
		if(flag==1) {
			a[1]=x;
			a[2]=v;
			return;
		} else dis=0;
		memset(vis,0,sizeof(vis));
		memset(ch,0,sizeof(ch));
	}
}

inline void bfs(int x) {
	while(head1<tail) {
		head1++;
		vis[x]=1;
		dfs2(x);
		if(flag==1) return;
		memset(vis,0,sizeof(vis));
		memset(ch,0,sizeof(ch));
	}
}

int main() {
	fin>>n>>m;
	for(re int i=1; i<=m; i++) {
		fin>>x>>y;
		add(x,y),add(y,x);
	}
	for(re int i=1; i<=n; i++) {
		if(flag==1) break;
		else dis=0;
		bfs(i);
		head1=0,tail=1;
	}
//	cout<<num;
	a[++point]=0;
	for(re int i=1; i<=dis; i++) {
		if(ch[i]>=0&&ch[i]<=9) point++;
		while(ch[i]>=0&&ch[i]<=9) {
			a[point]=a[point]*10+ch[i],i++;
		}
		while(ch[i]=='|') {
			++i;
			lle++;
			if(lle>=2&&!p) {
				a[++point]=0;
				p=1;
			}
		}
		i--;
		lle=0;
		p=0;
	}
	fout<<a[1]<<' '<<a[2]<<' ';
	for(re int k=1; k<=point; k++) {
		int minn=99999;
		for(re int i=3; i<=point; i++) {
			while(a[i]>0&&!vised[i]) {
				if(minn>a[i]&&!first) {
					minn=a[i];
					sit=i;
				}
				++i;
				first=1;
			}
			if(first==1)
				i--;
			first=0;
		}
		if(sit!=0)
			for(re int i=sit; i<=point; i++) {
				if(a[i]==0) break;
				else fout<<a[i]<<' ',vised[i]=1;
			}
		sit=0;
	}
	return 0;
}
/*
6 5
1 3
2 3
2 5
3 4
4 6
*/
