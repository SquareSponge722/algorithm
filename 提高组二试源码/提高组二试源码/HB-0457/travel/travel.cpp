#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n,x,c;
	int g=2;
	int t[2500];
	int d[2500];
	int r[2500];
	int z=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>r[i]>>d[i];
	}
	t[1]=r[1];
	t[2]=d[1];
	for(int i=2;i<=m;i++){
		if(d[i]=d[i+1]){
			t[g]=d[i];
			g++;
			t[g]=r[i];
		}
		for(i=1;i<=n;i++){
			if(i>g)t[i]=i;
			for(int j=1;j<=m;j++){
				if(r[j]==i)z++;	
			}
		}
			if(z==0){
				for(int k=1;k<=m;k++){
					if(r[k]=i)x=k;
					break;
				}
				for(int k=i;k>=x+2;k--){
					c=t[k];
					t[k]=t[k-1];
					t[k-1]=t[k];
				}
			}
		}
	for(int i=0;i<=n;i++){
		cout<<t[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
