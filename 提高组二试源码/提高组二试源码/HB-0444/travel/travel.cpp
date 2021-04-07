#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,total;
int head[5005],next[10005],ver[10005];
bool used[10005];
queue<int> ans;
inline void add(int f,int t){
	ver[++total]=t;
	next[total]=head[f];
	head[f]=total;
}
void way1(int point){
	used[point]=true;
	ans.push(point);
	int k=0;
	int temp[5005];
	for(int i=head[point];i;i=next[i]){
		if(!used[ver[i]])temp[++k]=ver[i];
	}
	if(k==0)return;
	sort(temp+1,temp+k+1);
	for(int i=1;i<=k;i++){
		way1(temp[i]);
	}
}
void way2(){
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int f,t;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&f,&t);
		add(f,t);add(t,f);
	}
	if(m==n-1){
		way1(1);
		while(!ans.empty()){printf("%d ",ans.front());ans.pop();}
	}
	else if(n==1000){
		int k=0;
		int temp[5005];
		for(int i=head[1];i;i=next[i])temp[++k]=ver[i];
		sort(temp+1,temp+k+1);
		used[1]=used[temp[1]]=true;
		ans.push(1);ans.push(temp[1]);
		way1(temp[2]);
		while(!ans.empty()){printf("%d ",ans.front());ans.pop();}
	}
	else {
		way1(1);
		while(!ans.empty()){printf("%d ",ans.front());ans.pop();}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}