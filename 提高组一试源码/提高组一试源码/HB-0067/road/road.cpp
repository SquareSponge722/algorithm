# include <cstdio>
# include <iostream>
# include <cstring>
# define N 150000
using namespace std;
inline int read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	
	int res=ch-48;
	
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-48;
	return res;
}
int n,dep[N],ans;
int solve(int l,int r){
	if(l==r)	return dep[l];
	else {
		int mid=(l+r)>>1;
		ans=solve(l,mid)+solve(mid+1,r)-min(dep[mid],dep[mid+1]);
	}
}
int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		dep[i]=read();
	}
	solve(1,n);
	cout<<ans;
	return 0;
}
