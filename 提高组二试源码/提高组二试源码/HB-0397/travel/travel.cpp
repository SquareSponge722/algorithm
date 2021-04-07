#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int m;
int n;
int s=99999;
int h=1;
int p=99999;
int ans[5005];
int a[5005];
int b[5005];
struct node{
	bool son[5005];
}tree[5005]; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<5005;i++) {
		ans[i]=5005;
	}
	for(int i=0;i<5005;i++) {
		for(int j=0;j<5005;j++) {
			tree[i].son[j]=0;
		}
	}
	ans[0]=1;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++) {
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=0;i<n;i++) {
		tree[a[i]].son[b[i]]=1;
		tree[b[i]].son[a[i]]=1;
	}
	int last=0;
	int k=1;
	while(1) {
		int t=0;
		for(int j=0;j<5005;j++) {
			if(tree[k].son[j]) t=1;
		}
		if(t){
			tree[last].son[k]=0;
			tree[k].son[last]=0;
			for(int j=0;j<5005;j++){
				if(tree[k].son[j]) {
					ans[h]=min(ans[h],j);
				
				}
			}
			for(int j=0;j<5005;j++){
				if(tree[last].son[j]) {
					ans[h]=min(ans[h],j);
					
				}
			}
			tree[ans[h]].son[last]=0;
			last=k;
			k=ans[h];
		}
		else {
			k=last;
		}
		if(h==m) {
			for(int j=0;j<m;j++) {
				printf("%d ",ans[j]);
			}
			return 0;
		}
		h++;
	}
	return 0;
}

