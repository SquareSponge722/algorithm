#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int d[100002];
int sum=0,_min=100001,_max=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n; cin>>n;
	for(int i=1;i<=n;i++){
	   cin>>d[i];
	   if(_min>d[i])   _min=d[i];
	   if(_max<d[i])   _max=d[i];
	   }
	   
	int i;  bool flag;
	while(_min!=_max)
	{
		flag=false;
		for(i=1;i<=n;i++)
		{
			if(d[i]==_max&&flag)//如果找到 
			{
				d[i]--;//修补 
			}
			else if(d[i]==_max)
			{
				flag=true;
				d[i]--;
				sum++;
			}
			else flag=false;
		}//第一次结束 
		_max--;
	}
	cout<<sum+_min;
	fclose(stdin);  fclose(stdout);
	return 0;
}


