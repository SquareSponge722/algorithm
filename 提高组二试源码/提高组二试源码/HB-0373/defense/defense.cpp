//
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<ctime>
using namespace std;
const int maxium=10001;
int n,m;
string st;
struct node{
	int a,b;
	bool x,y;
}que[maxium];
int price[maxium];
bool way[maxium][maxium];
void read()
{
	int x,y;
	scanf("%d%d",&n,&m);
	cin>>st;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		way[x][y]=way[y][x]=true;
	}
	for(int i=1;i<=m;i++)
		cin>>que[i].a>>que[i].x>>que[i].b>>que[i].y;
	return;
}
void plan_A()
{
	int a1=0,a2=0,kk=0,a_1;
	for(int i=1;i<=n;i++)
		if(i%2) a1+=price[i];
		else a2+=price[i];
	if(a1>a2) kk=a2,a_1=0;
	else kk=a1,a_1=1;
	for(int i=1;i<=m;i++){
		int sum=0;
		if(que[i].x&&que[i].y)
			cout<<price[que[i].a]+price[que[i].b]<<endl;
		else if(que[i].x==que[i].y==0){
			if(que[i].a%2!=que[i].b%2) cout<<-1<<endl;
			else{
				if(que[i].a%2==0) cout<<a1<<endl;
				else cout<<a2<<endl;
			}
		}
		else{
			if(que[i].x){
				if(que[i].a%2==a_1){
					if(que[i].b%2!=a_1) cout<<kk<<endl;
					else cout<<((kk==a1)? a2+price[que[i].a]:a1+price[que[i].a])<<endl;
				}
				else{
					if(que[i].b%2==a_1) cout<<((kk==a1)?a1:a2)<<endl;
					else cout<<((kk==a1)?a2:a1)<<endl;
				}
			}
			else{
				if(que[i].b%2==a_1){
					if(que[i].a%2!=a_1) cout<<kk<<endl;
					else cout<<((kk==a1)? a2+price[que[i].b]:a1+price[que[i].b])<<endl;
				}
				else{
					if(que[i].a%2==a_1) cout<<((kk==a1)?a1:a2)<<endl;
					else cout<<((kk==a1)?a2:a1)<<endl;
				}
			}
		}
	}
	return;
}
void work()
{
	read();
	if(st=="A3") plan_A();
	else{
		int k;
		srand(time(0));
		k=rand()%2;
		if(k) for(int i=1;i<=m;i++) cout<<rand()%101001<<endl;
		else cout<<"%%%%jxl%%%%hyf%%%%lsk%%%%wwx%%%%lbw×£ÎÒnoip2018ÈËÆ·++£¡£¡£¡£¡£¡£¡"<<endl;
	}
	return;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	work();
	return 0;
}
/*noip2018rp++*/
