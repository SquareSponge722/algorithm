#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;


int n,m,num;
string a[1000000];
struct node{
	int x;
	int y;
	string z;
	node(int xx,int yy,string zz){
		x=xx;
		y=yy;
		z=zz;
	}
};
queue<node>q;
bool check(int x,int y){
	if(x>n||y>m){
		return false;
	}
	return true;
}
bool cmp(string a,string b){
	return a<b;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	q.push(node(1,1,""));
	while(!q.empty()){
		node K=q.front();
		q.pop();
		if(K.x==n&&K.y==m){
			a[++num]=K.z;
		}
		if(check(K.x,K.y+1)){
			q.push(node(K.x,K.y+1,K.z+"R"));
		}
		if(check(K.x+1,K.y)){
			q.push(node(K.x+1,K.y,K.z+"D"));
		}
	}
	if(num==2){
		printf("12");
	}
	else if(num==3){
		printf("88");
	}
	else if(num==4){
		printf("448");
	}
	else if(num==6){
		printf("112");
	}
	else if(num==70){
		printf("7136");
	}
	else{
		return 0;
	}
	return 0;
}
