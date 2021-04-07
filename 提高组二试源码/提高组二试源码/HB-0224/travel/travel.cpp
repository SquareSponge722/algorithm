#include<bits/stdc++.h>
using namespace std;
int b[5005],d[5005],e[5005];
bool a[5001][5001],f[5005]={0};
int k,n;
void zhuan(int x,int i){
	int y=1,j=1,l=1,z=i+1;
	for(int q=1;q<=n;q++)
	   if(a[x][q]&&!f[q])  {
	   d[y++]=q;
	   f[q]=true;
	   }
	y--;
	while(j<=y&&z<=k){
		if(d[j]<b[z]) e[l++]=d[j++];
		else if(d[j]==b[z]) e[l++]=d[j++],z++; 
		else e[l++]=b[z++];
	}
	while(j<=y) e[l++]=d[j++];
	while(z<=k) e[l++]=b[z++];
	k=l-1+i;
	for(int q=1;q<=k-i;q++){
	   b[q+i]=e[q];
	}
	memset(e,0,sizeof(e)); 
	memset(d,0,sizeof(d));
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	int m;
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	b[1]=f[1]=1;
	k=2;
	for(int i=1;i<=n;i++)
	   if(a[1][i]) b[k++]=i,f[i]=true;
	k--;
	for(int i=2;i<=n;i++){
	   f[b[i]]=true;
	   zhuan(b[i],i);
	 }    
	 for(int i=1;i<=n;i++)
	  cout<<b[i]<<" ";
	  return 0;
}	 
	   
	
