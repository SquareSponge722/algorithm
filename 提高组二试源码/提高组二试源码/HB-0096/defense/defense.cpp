#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

void reads(int &x){
	int fx=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fx=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	x=x*fx; //Õý¸ººÅ 
}

int n,m; char ss[4654];

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	reads(n),reads(m),cin>>ss;
	for(int i=1;i<=n;i++) reads(cost[i])q.push(cost[i]);
	for(int i=1;i<n;i++) reads(x),reads(y),add(x,y);
	for(int i=1;i<=m;i++) reads(ques[i].x),reads(ques[i].okk1),
		 reads(ques[i].y),reads(ques[i].okk2);
	if(ss[0]=='A'){ //Á´
		f[1][0]=f[1][2]=0; f[1][1]=cost[1];
		for(int i=2;i<=n;i++){
			f[i][1]=min(min(f[i-1][2],f[i-1][0])+cost[i],f[i-1][1]);
			f[i][0]=f[i-1][1],f[i][2]=f[i-2][1];
		} if(ss[1]=='2'){ for(int i=1;i<=m;i++){
			cout<<f[][]
		}
		return 0;
	}	
	
}
