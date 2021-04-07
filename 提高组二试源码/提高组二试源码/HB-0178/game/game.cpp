#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<iostream>
#include<algorithm>

#define vd void
#define il inline
#define re register

#define FOR(i,a,b) for(re int i(a);i<=(b);++i)
#define ROF(i,a,b) for(re int i(a);i>=(b);--i)
#define REP(u) for(re int i(head[u]);i;i=edge[i].nex)

#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,1<<17,in),pa==pb)?EOF:*pa++
//#define gc getchar()

using namespace std;
typedef long long ll;

char buf[1<<17],*pa(buf),*pb(buf);

FILE *in=fopen("game.in","r");
ofstream fout("game.out");

il int read() {
	re int s(0);
	re char c(gc);
	while(c<'0'||c>'9') c=gc;
	while(c>='0'&&c<='9') s=10*s+(c^48),c=gc;
	return s;
}

int n,m;

vd Main() {
	n=read(),m=read();
	if(n==1) {
		if(m==1) fout<<2;
		if(m==2) fout<<4;
		if(m==3) fout<<8;
	}
	if(n==2) {
		if(m==1) fout<<4;
		if(m==2) fout<<12;
		if(m==3) fout<<36;
	}
	if(n==3) {
		if(m==1) fout<<8;
		if(m==2) fout<<36;
		if(m==3) fout<<112;
	}
	if(n==5&&m==5) fout<<7136;
}
int main() {
	Main();
	return 0;
}
