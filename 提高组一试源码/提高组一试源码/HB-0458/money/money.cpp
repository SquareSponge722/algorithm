#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
bool b[1000005];
int n,highest,flag,ans;

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int u=1;u<=t;u++){
		cin>>n;
		ans=n;
		for(int i=1;i<=n;i++){//输入 
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if(a[1]==1||n==1){//特判 
			cout<<"1"<<endl;
			continue;
		}
		for(int i=2;i<=n;i++){//算highest 
			if(a[i]%a[1]!=0){
				highest=a[i]*a[1]-a[i]-a[1];
				if(highest<a[i])ans++;
				break;
			}
		}
		for(int i=1;i<=highest;i++){//初始化数组b 
			b[i]=false;
		}
		for(int i=1;i<=n;i++){//查 
			if(a[i]>highest){
				ans-=n-i+1;
				break;
			}
			flag=true;
			for(int j=1;a[i]*j<=highest;j++){//查单独表示 
				if(b[a[i]*j]!=true){
					b[a[i]*j]=true;
					flag=false;
				}
			}
			for(int o=1;o<i;o++)
				for(int p=1;a[i]*p<=highest;p++)
					for(int q=1;a[i]*p+a[o]*q<=highest;q++){
						if(b[a[i]*p+a[o]*q]!=true){
							b[a[i]*p+a[o]*q]=true;
							flag=false;
						}
					}
			for(int o=1;o<i;o++)
				for(int p=1;p<o;p++)
					for(int q=1;a[i]*q<=highest;q++)
						for(int r=1;a[i]*q+a[o]*r<=highest;r++)
							for(int s=1;a[i]*q+a[o]*r+a[p]*s<=highest;s++){
								if(b[a[i]*q+a[o]*r+a[p]*s]!=true){
									b[a[i]*q+a[o]*r+a[p]*s]=true;
									flag=false;
								}
							}
			if(flag==true)ans--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
