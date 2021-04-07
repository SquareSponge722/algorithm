#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>

#define REP(u) for(re int i=head[u],v,w;v=pan[i].to,w=pan[i].wi,i;i=pan[i].next)

#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,100000,in),pa==pb)?EOF:*pa++

using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");

const int maxn=110000;

char buf[100000],*pa(buf),*pb(buf);

int a[maxn];

int maxp=0,sit1,sit2,sits1,sits2,ans,minn=99999,flag,an,n,pass,tot;

inline void two(int x,int y) {
	while(a[x]<=0) ++x;
	if(x>y) {
		return;
	}
	if(x==y) {
		tot+=a[x],a[x]=0;
		return;
	} else {
		for(int j=x; j<=y; j++) {
			pass=(a[j]>0)*(pass+1);
			if(pass>maxp) {
				if(!flag) {
					maxp=pass;
					sits1=j;
					flag=1;
				} else {
					maxp=ans;
					sits2=j;
				}
				minn=min(a[j],minn);
			} else {
				if(minn!=99999)
				tot+=minn;
				flag=0;
				for(int i=sits1; i<=sits2; i++) {
					a[i]-=minn;
				}
				two(sits1,sits2);
				pass=maxp=0;
				minn=99999;
				two(sits2,n);
			}
		}
		if(flag==1) {
			tot+=minn;
			for(int i=sits1; i<=sits2; ++i) {
				a[i]-=minn;
			}
			pass=maxp=0;
			minn=99999;
			two(sits1,n);
		}
	}
}
int main() {
	fin>>n;
	for(int i=1; i<=n; i++) {
		fin>>a[i];
	}
	for(int j=1; j<=n; j++) {
		pass=(a[j]>0)*(pass+1);
		if(pass>maxp) {
			if(!flag) {
				maxp=pass;
				sit1=j;
				flag=1;
			} else {
				maxp=pass;
				sit2=j;
			}
			minn=min(a[j],minn);
		} else {
			flag=0;
			tot+=minn;
			for(int i=sit1; i<=sit2; i++) {
				a[i]-=minn;
			}
			ans+=minn;
			maxp=0;
			pass=0;
			minn=99999;
			two(sit1,sit2);
		}
	}
	if(flag==1) {
		tot+=minn;
		for(int i=sit1; i<=sit2; i++) {
			a[i]-=minn;
		}
		pass=maxp=0;
		minn=99999;
		two(sit1,sit2);
	}
	fout<<tot;
	return 0;
}
/*
6
4 3 2 5 3 5
*/
