#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;

void ONE(){
	int dao[6]={0},du[6]={0};
		int jie[6][6]={0};
		for(int i=1,x,y;i<n;i++){
			scanf("%d%d%d",&x,&y,&dao[i]);
			du[x]++;
			du[y]++;
			jie[x][y]=dao[i];
			jie[y][x]=dao[i];
		}
		if(n==2) printf("%d\n",dao[1]);
		if(n==3) printf("%d\n",dao[1]+dao[2]);
		if(n==4){
			int maxn=-1;
			for(int i=1;i<=n;i++)
				maxn=max(maxn,du[i]);
			if(maxn==2) printf("%d",dao[1]+dao[2]+dao[3]);
			else {
				int ans;
				ans=max(dao[1]+dao[2],max(dao[1]+dao[3],dao[2]+dao[3]));
				printf("%d\n",ans);
			}
		}
		if(n==5){
			int maxn=-1,cnt;
			for(int i=1;i<=n;i++){
				if(du[i]>maxn){
					maxn=du[i];
					cnt=i;
				}
			}
			if(maxn==2) printf("%d\n",dao[1]+dao[2]+dao[3]+dao[4]);
			else if(maxn==3){
				int gen=0;
				for(int i=1;i<=n;i++){
					if(du[i]==2){
						for(int j=1;j<=n;j++) gen+=jie[i][j];
						break;
					}
				}
				int shu=-1;
				for(int i=1;i<=n;i++){
					if(i==cnt){
						for(int j=1;j<=n;j++){
							if(du[j]==1&&jie[j][i]!=0)
								shu=max(jie[i][j],shu);
						}
					}
				}
				printf("%d\n",gen+shu);
			}
			else{
				int ans=-1;
				for(int i=1;i<n-1;i++)
					for(int j=i+1;j<n;j++)
						ans=max(dao[i]+dao[j],ans);
				printf("%d\n",ans);
			}
		}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=5&&m==1) ONE();
	return 0;
}
