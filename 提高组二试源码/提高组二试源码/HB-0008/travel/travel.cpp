#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=5005;
int a[N][N]={0},b[N]={0};
bool f[N]={0};
int mint1,mint2;
bool back=true;
int n,m;
bool all(bool q[]){
	for (int i=1;i<=n;i++) if (!f[i])return false;
	return true;
}

int save[N]={0},out[N]={0},ans(1);
void search(int x){
	if (!all(f)){
	mint1=mint2=0x3fff;back=true;
 	for (int i=1;i<=b[x];i++)
	     if (!f[a[x][i]]){
		    mint1=min(mint1,a[x][i]);
		    back=false;
		 }
		 else 
		    for (int j=1;j<=b[a[x][i]];j++)
			    if (!f[a[a[x][i]][j]] && save[a[a[x][i]][j]]==a[x][i]){
		            mint1=min(mint1,a[a[x][i]][j]);
		            back=false;
				}
 	for (int i=1;i<=b[save[x]];i++)
	     if (!f[a[save[x]][i]]){
		    mint2=min(mint2,a[save[x]][i]);
		 }
		 if (back)
		    search(save[x]);
		 else if (mint1>mint2 && b[mint1]>1){
			out[++ans]=mint2;
            save[mint2]=x;
			f[mint2]=true;
			search(save[mint2]);			
		 }
		 else{
		 	out[++ans]=mint1;   
		    save[mint1]=x;
		    f[mint1]=true;	
		    search(mint1);
		 }
 }
}
	
 void out_put (int r[]){
 	for (int i=1;i<n;i++) cout<<r[i]<<" ";
 	cout<<r[n]<<endl;
 }
int main(){
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
    int e,f1;
	cin>>n>>m;
	for (int i=1;i<=m;i++){ 
	    cin>>e>>f1;
		a[min(e,f1)][++b[min(e,f1)]]=max(e,f1);
		a[max(e,f1)][++b[max(e,f1)]]=min(e,f1);
	}
	f[1]=true;
	out[1]=1;
	search(1);
	out_put(out);
	return 0;
}
