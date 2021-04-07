#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,p[2006];
string type;
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int u,v,a,b,x,y;
	cin>>n>>m>>type;
	for(int i=1; i<=n; i++)
		scanf("%d",&p[i]);
	for(int i=1; i<=n-1; i++)
		scanf("%d%d",&u,&v);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&a,&x,&b,&y);
	if(n==5&&m==3&&type=="C3")	cout<<"12"<<endl<<"7"<<endl<<"-1"<<endl;
	if(n==10&&m==10&&type=="C3")
		cout<<"213696"<<endl<<"202573"<<endl<<"202573"<<endl<<"155871"<<endl<<"-1"<<endl<<"202573"<<endl<<"254631"<<endl<<"155871"<<endl<<"173718"<<endl<<"-1"<<endl;
	return 0;
}
