#include<bits/stdc++.h>
using namespace std;

int n,m,r[5000]={0},k=1,t[5000];
struct city{
	int a,b,c;
}p[5000],q[5000];

bool cmp(const city &x,const city &y){
	x.b<=y.b;   
}

bool can(int x,int y){
	for(int i=1;i<=m;i++){
	if(p[i].a == x && p[i].b == y && p[i].c==0 || p[i].c==1 && q[i].a == x && q[i].b == y)	
	return true;
	
	else return false;
	if(p[i].c>=1&&t[i]==0) return false;
}
}
void f(int x){//Æðµã 
	for(int i=1;i<=m;i++){
		if (can(x,p[i].b)) {
			p[i].c++;
		if (p[i].c == 1) 
			r[k++] = x;
			r[k++] = p[i].b;
			q[i].a = p[i].b;
			q[i].b = x;
			x = p[i].b;
		if(k<n+1) return f(x);
		if(k=n+1){
			for(int i = 1;i<k;i++)
				cout<<r[k]<<" ";	
		if(k>=n+1) continue;
			} 
		}
		else continue;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
	cin>>p[i].a>>p[i].b;
	t[p[i].a]++;t[p[i].b]++;
	p[i+m].a = p[i].b = q[i].a;
	p[i+m].b = p[i].a = q[i].b;
	
	}
	sort(p+1,p+m+1,cmp);
	
	f(1);
	return 0;
}
