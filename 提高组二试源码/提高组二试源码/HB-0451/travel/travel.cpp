#include <bits/stdc++.h>

using namespace std;

int u[5100][5100]={0},q[10000]={0},v[5100][5100]={0};//q是字典数列 

int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,i,a,b,d=1,s=1;//d是起始点 
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
		//emm后面应该是啥啊 
        s++;
        break;
	}
	else
	{
		u[d][i]=v[1][i];//返回上一层？？貌似失败了。 
	}
	

    }   
    }
    //从1开始逐个比较 ,搜索完返回怎么办！ 
   
	
	//应该比较完了吧，广深搜？？？？ 天啊忘记深搜怎么写了，GG。 
    
	for(i=0;i<n;i++)
	cout<<q[i]<<"　";
	
    fclose;
	return 0;
}


