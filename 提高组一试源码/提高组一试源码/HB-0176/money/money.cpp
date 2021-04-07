#include<bits/stdc++.h>
using namespace std;
const int N=105;
int T,n,a[N],m,b[N],en=0;

bool judge(int x,int y,int z){
	if(z%x==0||z%y==0) return true;
	for(int i=y;i<=z;i+=y){
		if((z-i)%x==0){
			return true;
		}
		for(int j=x;j+i<=z;j+=x){
			for(int k=1;k<=en;k++){
				if(b[k]==x||b[k]==y) continue;
				if((z-i-j)%b[k]==0) return true;
			}
		}
	}
	return false;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		en=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		if(n==1) printf("1\n");
		else if(n==2){
			if(a[1]%a[2]==0||a[2]%a[1]==0) printf("1\n");
			else printf("2\n");
		}
		else if(n==3){
			m=n;
			sort(a+1,a+n+1);
			int temp;
			if(a[2]%a[1]==0) m--;
			temp=a[1];
			if(a[3]%a[2]==0||a[3]%a[1]==0){
				m--,printf("%d\n",m);
				continue;
			}
			for(;temp<=a[3];temp+=a[1]){
				if((a[3]-temp)%a[2]==0){
					m--,printf("%d\n",m);
					break;
				}
			}
			
		}
		else{
			sort(a+1,a+n+1);
			m=n;
			bool ok=0;
			if(a[2]%a[1]==0){
				b[1]=a[1];
				en=1;
				m--;
			}
			else{
				b[1]=a[1];
				b[2]=a[2];
				en=2;
			}
			for(int i=3;i<=n;i++){//记得从3开始 
				if(i==3&&en==1){
					if(a[i]%b[en]==0) ok=1; 
					else ok=0;
				}
				for(int j=1;j<en;j++){
					for(int k=j+1;k<=en;k++){
						if(ok) break;
						ok=ok|judge(b[j],b[k],a[i]);
					}
					if(ok) break;
				}
				if(ok) m--;
				else b[++en]=a[i];
				ok=0;
			}
			printf("%d\n",m);
		}
	}
	return 0;
}
