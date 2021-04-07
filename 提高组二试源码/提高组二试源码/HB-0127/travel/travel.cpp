#include<bits/stdc++.h>
using namespace std;
int m,n,head[5005],lian[5005],en;
struct Edge{
	int to,next;
}edge[10008];
bool ok[5005],done[5005];

void read(int &x){
	char a;
	x=0;
	a=' ';
	while (a==' ') a=getchar();
	while (a>='0'&&a<='9') {
		x=x*10+a-48;
		a=getchar();
	}
	return;
}

void dfs(int x){
	int did[lian[x]];
	ok[x]=1;
	int i,len(0);
	for (i=head[x];edge[i].to!=0;i=edge[i].next){
		if (ok[edge[i].to]==1) continue;
		if (done[edge[i].to]==1&&edge[i].to<x) {
			ok[x]=0;
			return;
		}
		len++;
		did[len]=edge[i].to;
		done[edge[i].to]=1;
	}
	printf("%d ",x);
	sort(did+1,did+len+1);
	for (i=1;i<=len;i++){
		if (ok[did[i]]==0) dfs(did[i]);
	}
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n);
	read(m);
	for (int x,y,i=1;i<=m;i++){
		read(x);
		read(y);
		en++;
		edge[en].to=y;
		edge[en].next=head[x];
		head[x]=en;
		lian[x]++;
		en++;
		edge[en].to=x;
		edge[en].next=head[y];
		head[y]=en;
		lian[y]++;
	}
	done[1]=1;
	dfs(1);
	return 0;
}
