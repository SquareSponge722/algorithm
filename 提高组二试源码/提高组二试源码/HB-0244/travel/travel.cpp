#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<fstream>

using namespace std;
#define R register
static char buff[100000],*pa,*pb;
FILE *read;
#define gc pa==pb&&(pb=(pa=buff)+fread(buff,1,100000,read))?EOF:*pa++
int n,m;
const int ROOM=5010;
int e[ROOM][ROOM];
int ans[ROOM];
struct EDGE {
	int to,nxt,w;
} edge[2*ROOM];
int head[ROOM];
int cnt=0;
int pd[ROOM];
void add(int a,int b) {
	edge[++cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
bool used[ROOM];
int fate[ROOM];

int in() {
	R char w(gc);
	R int num(0);
	while(!(w>='0'&&w<='9')) w=gc;
	while(w>='0'&&w<='9') {
		num=num*10+(w^48);
		w=gc;
	}
	return num;
}

ofstream fout;

void out() {
	fout.open("travel.out");
	for(int i=1; i<=n; ++i) fout<<ans[i]<<" ";
	fout.close();
}


namespace LINE {
	int top=1;
	void dfs(int sta) {
		for(int i=1; i<=n; ++i)
			if(e[i][sta]&&!used[i]) {
				used[i]=1;
				ans[top++]=i;
				dfs(i);
			}
	}
	void work() {
		for(int i=1; i<=n; ++i) {
			if(e[i][1]&&!used[i]) {
				dfs(i);
			}
		}
	}
}

namespace TREE{

	int top=1;
	void dfs(int sta,int step) {
		if(top==n) {
			return ;
		}
		for(int i=1; i<=n; ++i) {
			if(e[i][sta]&&!used[i]) {
				ans[++top]=i;
				used[i]=1;
				dfs(i,step+1);
			}
		}
	}
	void work() {
		ans[1]=1;
		fate[1]=1;
		used[1]=1;
		dfs(1,2);
	}
}

namespace P2 {
	int top=1;
	void dfs(int sta,int step) {
		if(top==n) {
			for(int i=1; i<=n; ++i) ans[i]=fate[i];
		}
		for(int i=1; i<=n; ++i) {
			if(e[i][sta]&&!used[i]) {
				if(i>ans[step]) break;
				fate[++top]=i;
				used[i]=1;
				dfs(i,step+1);
				used[i]=0;
			}
		}
	}
	void work() {
		for(int i=1; i<=n; ++i) ans[i]=999999;
		ans[1]=1;
		fate[1]=1;
		used[1]=1;
		dfs(1,2);
	}
}

void cross() {
	int flag=1;
	int flag2=1;
	for(int i=1; i<=n; ++i) 
	{
		if(pd[i]>=3) flag=0;
		if(pd[i]>3) flag2=0; 
	}
	if(flag) LINE::work();
	else if(flag2) TREE::work();
	else P2::work();
}

void scan() {
	read=fopen("travel.in","r");
	n=in();
	m=in();
	for(int i=1; i<=m; ++i) {
		int a,b;
		a=in();
		b=in();
		pd[a]++;
		pd[b]++;
		e[a][b]=1;
		e[b][a]=1;
	}
}

int main() {
	scan();
	cross();
	out();
	return 0;
}
