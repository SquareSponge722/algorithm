#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,m,kaixiao,q;
	char type;
	int a[10001],j,u[10001],v[10001],x[10001],b[10001],y[10001],p[10001],f,w[10001],i;
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type; q=n-1;
	for(i=1;i<=n;++i) cin>>p[i];  //ÿ�����ж�Ӧ�Ŀ��� 
	for(f=1;f<=q;++i) cin>>u[f]>>v[f];  //u��v֮���е�·���� 
	for(j=1;j<=m;++j) 
		cin>>a[j]>>x[j]>>b[j]>>y[j];  //a��b��ʾ���У�x��y��ʾ�Ƿ�פ�� 
		for(j=1;j<=m;++j) {
		for(f=1;f<=q;++f){
			if(x[j]==0){		
				if(u[f]==a[j]) u[f]=0;
				if(v[f]==a[j]) v[f]=0;	
				}
			if(y[j]==0){
				if(u[f]==b[j]) u[f]=0;
				if(v[f]==b[j]) v[f]=0;
				}
			if(v[f]==0 && u[f]==0)  //�������������о���פ�������޷����� 
			cout<<"-1"<<endl;
				}
				else
 				if(u[f]!=0  && v[f]==0) w[f]=u[f];        //���ӳ��о����ٲ��ұ��� 
			 	if(u[f]==0 && v[f]!=0) w[f]=v[f];
			 	if(u[f]!=0 && v[f]!=0) {
					if(w[f]==w[f-1] || w[f]==w[f-2]) w[f]=0;
					else{				
				 if(p[u[f]]<=p[v[f]]) w[f]=u[f]; else w[f]=v[f];                             //ȥ���ظ����� 
					}
				 }
				kaixiao+=w[f]*p[w[f]];			 
			 }
			 cout<<kaixiao<<endl;
			}
	return 0;		
	}
		
			
	
		
		
		
		
		
		//�������ڳ���֮��ֻ��Ҫһ����פ�����ж�u[i]==0ʱ��v[i]�Ƿ�==0 
		

