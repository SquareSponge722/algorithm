#include <bits/stdc++.h>

using namespace std;

int u[5100][5100]={0},q[10000]={0},v[5100][5100]={0};//q���ֵ����� 

int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,i,a,b,d=1,s=1;//d����ʼ�� 
	cin>>n>>m; 
	q[0]=1;
	for(i=1;i<=m;i++)
	{
	 cin>>a>>b;
	 u[a][b]=1;
	 u[b][a]=1;
	 
}
    for(i=1;i<=n;i++)
	{
	  
     for(i=1;i<=1000;i++)
    {
    	
	if(u[d][i]==1)
    {
    	v[d-1][i]=u[d][i];
    	u[d][i]=0;
    	u[i][d]=0;
        d=i;
    	q[s]=d;
		//emm����Ӧ����ɶ�� 
        s++;
        break;
	}
	else
	{
		u[d][i]=v[1][i];//������һ�㣿��ò��ʧ���ˡ� 
	}
	

    }   
    }
    //��1��ʼ����Ƚ� ,�����귵����ô�죡 
   
	
	//Ӧ�ñȽ����˰ɣ������ѣ������� �찡����������ôд�ˣ�GG�� 
    
	for(i=0;i<n;i++)
	cout<<q[i]<<"��";
	
    fclose;
	return 0;
}


