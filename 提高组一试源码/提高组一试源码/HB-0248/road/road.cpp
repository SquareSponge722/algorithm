#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N=20000001,M=10001;
int d[N],n,minn;
int ks,t,mkzxz[M],js[M];
bool flag[N];
long long ans;
int getwz(int i){
	if(i%t==0)
		return i/t;
	else
		return i/t+1;
}
void init(){
	scanf("%d",&n);
	minn=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		if(d[i])
			flag[i]=true;
		else
			flag[i]=false;
		if(d[i]<d[minn])
			minn=i;
	}
}
void jm(){
	int k=sqrt(n);
	if(n%k==0)
		ks=k;
	else
		ks=k+1;
	t=k;
	for(int i=1;i<=ks;i++)
		mkzxz[i]=-1;
	for(int i=1;i<=n;i++){
		int djk;
		if(i%t==0)
			djk=i/t;
		else
			djk=i/t+1;
		if(mkzxz[djk]==-1 || mkzxz[djk]>d[i])
			mkzxz[djk]=d[i];
	}
}
int fhmin(int l,int r){
	int lk,rk;
	if(l%t==0)
		lk=l/t;
	else
		lk=l/t+1;
	if(r%t==0)
		rk=r/t;
	else
		rk=r/t+1;
	if(lk==rk || rk==lk+1){
		int nmin=-1,mink;
		for(int i=l;i<=r;i++){
			int xzk=(i<=lk*t)?lk:rk;
			if(nmin==-1)
				nmin=i,mink=xzk;
			else
				if(d[nmin]-js[mink]>d[i]-js[xzk])
					nmin=i,mink=xzk;
		}
		return d[nmin]-js[mink];
	}
	else{
		int minl=-1,minr=-1;
		for(int i=l;i<=lk*t;i++)
			if(minl==-1 || d[minl]>d[i])
				minl=i;
		for(int i=(rk-1)*t+1;i<=r;i++)
			if(minr==-1 || d[minr]>d[i])
				minr=i;
		int minv=(d[minl]<d[minr])?(d[minl]-js[lk]):(d[minr]-js[rk]);
		for(int i=lk+1;i<rk;i++)
			if(mkzxz[i]-js[i]<minv)
				minv=mkzxz[i]-js[i];
		return minv;
	}
}
void jsqj(int l,int r,int v){
	int lk,rk;
	if(l%t==0)
		lk=l/t;
	else
		lk=l/t+1;
	if(r%t==0)
		rk=r/t;
	else
		rk=r/t+1;
	if(lk==rk || rk==lk+1)
		for(int i=l;i<=r;i++)
			d[i]-=v;
	else{
		for(int i=l;i<=lk*t;i++)
			d[i]-=v;
		for(int i=(rk-1)*t+1;i<=r;i++)
			d[i]-=v;
		for(int i=lk+1;i<rk;i++)
			js[i]+=v;
	}
}
int jt(int l,int r){
	if(l==r)
		return d[l]-js[getwz(l)];
	int zc=fhmin(l,r);
	jsqj(l,r,zc);
	bool fx=false;
	int last=-1;
	for(int i=l;i<=r;i++)
		if(d[i]-js[getwz(i)]){
			last=i;
			break;
		}
	if(last==-1)
		return zc;
	for(int i=l;i<=r;i++){
		int wz=(i%t==0)?(i/t):(i/t+1);
		if(d[i]-js[wz]==0)
			zc+=jt(last,i-1),fx=true;
		else
			if(fx)
				last=i,fx=false;
	}
	if(!fx)
		zc+=jt(last,r);
	return zc;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	jm();
	printf("%ld",jt(1,n));
	return 0;
}
