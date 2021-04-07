#include<bits/stdc++.h>
using namespace std;
int T,n,ans=2,cnt=0;
int a[105];
int f[25005];

inline int read(){
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') k=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*k;
}

int gcd(int x,int y){
	if(x<y) swap(x,y);
	if(x%y!=0) gcd(y,x%y);
	else return y;
}

bool m(int a,int b){
	if(gcd(a,b)==1) return 1;
	else return 0;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		if(n==2){
			if(a[1]==1||a[2]==1) {printf("1\n");continue;}
			else {
				if(gcd(a[1],a[2])!=1) {printf("1\n");continue;}
				else {printf("2\n");continue;}
			}
		}
		if(n==3){
			if(a[1]==1||a[2]==1||a[3]==1) {printf("1\n");continue;}
			else if(gcd(a[1],gcd(a[2],a[3]))==1) {printf("3\n");continue;}
			else{
				sort(a+1,a+4);
				if(a[3]%a[1]==0&&a[3]%a[2]==0) {printf("1\n");continue;}
				if((a[3]%a[1]==0&&gcd(a[3],a[2])==1)||(a[3]%a[2]==0&&gcd(a[3],a[1])==1)) {printf("2\n");continue;}
				if(a[2]%a[1]==0&&m(a[3],a[2])) {printf("2\n");continue;}
			}
		}
		if(n==4){
			if(a[1]==1||a[2]==1||a[3]==1||a[4]==1) {printf("1\n");continue;}
			if(m(a[4],a[3])&&m(a[4],a[2])&&m(a[4],a[1])&&m(a[3],a[2])&&m(a[3],a[1])&&m(a[2],a[1])) {printf("1\n");continue;}
			else{
				sort(a+1,a+5);
				if(a[4]%a[1]==0&&a[4]%a[2]==0&&a[4]%a[3]==0) {printf("1\n");continue;}
				if((a[4]%a[1]==0&&gcd(a[4],a[2])==1&&gcd(a[4],a[3])==1)||(a[4]%a[2]==0&&gcd(a[4],a[1])==1&&gcd(a[4],a[3])==1)||(a[4]%a[3]==0&&gcd(a[4],a[1])==1&&gcd(a[4],a[2])==1)) {printf("2\n");continue;}
				if((a[4]%a[1]==0&&a[4]%a[2]==0&&gcd(a[4],a[3])==1)||(a[4]%a[1]==0&&a[4]%a[3]==0&&gcd(a[4],a[2])==1)||(a[4]%a[3]==0&&a[4]%a[2]==0&&gcd(a[4],a[1])==1)) {printf("3\n");continue;}
				if(m(a[4],a[3])){
					if(a[3]%a[1]==0&&a[3]%a[2]==0) {printf("2\n");continue;}
					if((a[3]%a[1]==0&&gcd(a[3],a[2])==1)||(a[3]%a[2]==0&&gcd(a[3],a[1])==1)) {printf("3\n");continue;}
				}
				if(m(a[4],a[3])&&m(a[4],a[2])){
					if(a[2]%a[1]==0) {printf("3\n");continue;}
				}
			}
		}
		if(n==5){
			if(a[1]==1||a[2]==1||a[3]==1||a[4]==1||a[5]==1) {printf("1\n");continue;}
			if(m(a[4],a[3])&&m(a[4],a[2])&&m(a[4],a[1])&&m(a[3],a[2])&&m(a[3],a[1])&&m(a[2],a[1])&&m(a[5],a[1])&&m(a[5],a[2])&&m(a[5],a[3])&&m(a[5],a[4])) {printf("1\n");continue;}
			else{
				sort(a+1,a+5);
				if(a[5]%a[1]==0&&a[5]%a[2]==0&&a[5]%a[3]==0&&a[5]%a[4]==0) {printf("1\n");continue;}
				if((a[5]%a[1]==0&&gcd(a[5],a[2])==1&&gcd(a[5],a[3])==1&&gcd(a[5],a[4])==1)||(a[5]%a[2]==0&&gcd(a[5],a[1])==1&&gcd(a[5],a[3])==1&&gcd(a[5],a[4])==1)||(a[5]%a[3]==0&&gcd(a[5],a[1])==1&&gcd(a[5],a[2])==1&&gcd(a[5],a[4])==1)||(a[5]%a[4]==0&&gcd(a[5],a[1])==1&&gcd(a[5],a[2])==1&&gcd(a[5],a[3])==1)) {printf("2\n");continue;}
				if((a[5]%a[1]==0&&a[5]%a[2]==0&&gcd(a[5],a[3])==1&&gcd(a[5],a[4])==1)||(a[5]%a[1]==0&&a[5]%a[3]==0&&gcd(a[5],a[2])==1&&gcd(a[5],a[4])==1)||(a[5]%a[3]==0&&a[5]%a[2]==0&&gcd(a[5],a[1])==1&&gcd(a[5],a[4])==1)||(a[5]%a[3]==0&&a[5]%a[4]==0&&gcd(a[5],a[1])==1&&gcd(a[5],a[2])==1)||(a[5]%a[2]==0&&a[5]%a[4]==0&&gcd(a[5],a[1])==1&&gcd(a[5],a[3])==1)||(a[5]%a[1]==0&&a[5]%a[4]==0&&gcd(a[5],a[2])==1&&gcd(a[5],a[3])==1)) {printf("3\n");continue;}
				if((a[5]%a[1]==0&&m(a[5],a[4])&&m(a[5],a[3])&&m(a[5],a[2]))||(a[5]%a[2]==0&&m(a[5],a[4])&&m(a[5],a[3])&&m(a[5],a[1]))||(a[5]%a[3]==0&&m(a[5],a[4])&&m(a[5],a[1])&&m(a[5],a[2]))||(a[5]%a[4]==0&&m(a[5],a[1])&&m(a[5],a[3])&&m(a[5],a[2]))) {printf("4\n");continue;}
				if(m(a[4],a[5])){
					if(a[4]%a[1]==0&&a[4]%a[2]==0&&a[4]%a[3]==0) {printf("2\n");continue;}
					if((a[4]%a[1]==0&&gcd(a[4],a[2])==1&&gcd(a[4],a[3])==1)||(a[4]%a[2]==0&&gcd(a[4],a[1])==1&&gcd(a[4],a[3])==1)||(a[4]%a[3]==0&&gcd(a[4],a[1])==1&&gcd(a[4],a[2])==1)) {printf("3\n");continue;}
					if((a[4]%a[1]==0&&a[4]%a[2]==0&&gcd(a[4],a[3])==1)||(a[4]%a[1]==0&&a[4]%a[3]==0&&gcd(a[4],a[2])==1)||(a[4]%a[3]==0&&a[4]%a[2]==0&&gcd(a[4],a[1])==1)) {printf("4\n");continue;}	
				}
				if(m(a[4],a[5])&&m(a[5],a[3])){
					if(a[3]%a[1]==0&&a[3]%a[2]==0) {printf("3\n");continue;}
					if((a[3]%a[1]==0&&gcd(a[3],a[2])==1)||(a[3]%a[2]==0&&gcd(a[3],a[1])==1)) {printf("4\n");continue;}
				}
				if(m(a[4],a[5])&&m(a[5],a[3])&&m(a[5],a[2])){
					if(a[2]%a[1]==0) {printf("4\n");continue;}
				}
			}
		}
		if(n>5&&n<=25){
			int x,ii;
			ans=0;
			sort(a+1,a+n+1);
			if(a[1]==1){
				printf("1\n");
				continue;
			}
			for(int i=2;i<=n;i++){
				if(gcd(a[i],a[1])==1){
					x=a[i];
					break;
				}
			}
			int m;bool okk=1;
			for(int i=n;i>1;i--){
				m=a[i];
				for(;m>0;){
					m-=a[1];
					if(m==x) okk=0;
				}
				if(okk) ans++;
			}
			printf("%d",ans);
		}
		if(n>25){
			ans=0;
			int x;
			sort(a+1,a+n+1);
			if(a[1]==1){
				printf("1\n");
				continue;
			}
			for(int i=2;i<=n;i++){
				if(gcd(a[i],a[1])==1){
					x=a[i];
					break;
				}
			}
			long long mx;
			mx=(long long)(x*a[1])+(x%a[1]);
			for(int i=1;i<=mx;i++){
				if(i<a[1]) f[++cnt]=i;
				else{
					if(i%a[1]!=0&&i%x!=0) f[++cnt]=i;
				}
			}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=cnt;j++){
					if(a[i]<f[j]) break;
					if(a[i]==f[j]){
						ans++;
						break;
					} 
				}
			printf("%d",ans);
		}
	}
	return 0;
}
