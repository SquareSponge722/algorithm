#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int T,n;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		if(n==2){
			int x=read(),y=read();
			if(x==y) puts("1");
			else if(x>=2 && y>=2) puts("2");
			else if(x==1 || y==1) puts("1");
			else puts("2");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
4
3 19 10 6
5 
11 29 13 19 17
*/

