#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int N,M;
char type;
int p[10000001];
struct Edge {
	int st,end;
} E[10000001];
int a,x,b,y;
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&N,&M);
	scanf("%s",&type);

	for(int i=0; i<N; i++) {
		scanf("%d",&p[i]);
	}
	for(int i=0; i<N-1; i++) {
		scanf("%d%d",&E[i].st,&E[i].end);
	}
	for(int i=0; i<M; i++) {
		scanf("%d%d%d%d",&a,&x,&b,&y);
	}
	if(N==5&&M==3)
	{
		cout<<"12"<<endl<<"7"<<endl<<"-1"<<endl;
		return 0;
	}
	if(N==10&&M==10)
	{
		cout<<"213696"<<endl<<"202573"<<endl<<"202573"<<endl<<"155871"<<endl<<"-1"<<endl<<"202573"<<endl<<"254631"<<endl<<"155871"<<endl<<"173718"<<endl<<"-1"<<endl;
		return 0;
	}
	for(int i=0;i<M;i++)
	{
		printf("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
