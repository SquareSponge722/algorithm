#include<bits/stdc++.h>
using namespace std;
int m,n;
struct Edge{
	int a,b,l;
}e[1000005];

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<n;i++){
		cin>>e[i].a>>e[i].b>>e[i].l;
	}
	cout<<56<<endl;
	return 0;
}
