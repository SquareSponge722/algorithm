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
		for(int i=1;i<=n;i++){//���� 
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if(a[1]==1||n==1){//���� 
			cout<<"1"<<endl;
			continue;
		}
		for(int i=2;i<=n;i++){//��highest 
			if(a[i]%a[1]!=0){
				highest=a[i]*a[1]-a[i]-a[1];
				if(highest<a[i])ans++;
				break;
			}
		}
		for(int i=1;i<=highest;i++){//��ʼ������b 
			b[i]=false;
		}
		for(int i=1;i<=n;i++){//�� 
			if(a[i]>highest){
				ans-=n-i+1;
				break;
			}
			flag=true;
			for(int j=1;a[i]*j<=highest;j++){//�鵥����ʾ 
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
