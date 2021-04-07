#include<iostream>
#include<algorithm>
#include<list>
#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>

using namespace std;

int xct,xcn,xcsss,xcans,xctemp;
int xca[105];
int xcunique(int* first,int elemnum);

int main(){
	freopen("money.in" ,"r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&xct);
	for (int xci=0;xci<xct;xci++){
		scanf("%d",&xcn);
		for (int xck=0;xck<xcn;xck++){
			scanf("%d",&xctemp);
			xca[xck]=xctemp;
		}
		if (xcn==2){
			if (xca[0]%xca[1]==0 or xca[1]%xca[0]==0){
				printf("%d\n",1);
			}else{
				printf("%d\n",2);
			}
		}else if (xcn==1){
			printf("%d\n",1);
		}else {
			sort(xca,xca+xcn);
			xcsss=xca[0];
			for (int sdfghj=0;sdfghj<xcn;sdfghj++){
				xca[sdfghj]=xca[sdfghj]%xcsss;
			}sort(xca,xca+xcn);
			cout<<xcunique(xca,xcn)<<endl;
		}
		
	}
	return 0;
}

int xcunique(int* first,int elemnum){
	int diffelems=0;
	int prev_elem=0;
	for (int i=0;i<elemnum;i++){
		if (i==0){
			prev_elem=first[0];
			diffelems++;
		}else{
			if (prev_elem!=first[i]){
				first[diffelems-1]=prev_elem;
				prev_elem=first[i];
				diffelems++;
			}
		}
	}
	return diffelems;
}
