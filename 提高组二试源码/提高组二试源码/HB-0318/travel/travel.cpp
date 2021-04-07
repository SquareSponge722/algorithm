#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5005;

//其实题目我是看了的并且知道思路   然而我不会实现它……  还有几分钟  瞎打 

inline long long read(){
	long long x=0,y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')  y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
}

struct edge{
	int from,to;
//	bool operator < ( const edge &b ) const {  from < b.from ;}
}e[N];

bool visited[N];

bool cmp(edge a,edge b){
	if(a.from != b.from ) return a.from < b.from ;  
	if(a.from == b.from ) return a.to < b.to ;

}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans[N];
	n=read();	m=read();
	for(int i=1;i<=m;i++) {  e[i].from=read();	e[i].to=read();	 } 
	sort(e+1,e+1+m,cmp);
	cout<<e[1].from<<" ";
	for(int i=1;i<n;i++)  cout<<e[i].to<<" ";
	cout<<endl;
	return 0;
}
