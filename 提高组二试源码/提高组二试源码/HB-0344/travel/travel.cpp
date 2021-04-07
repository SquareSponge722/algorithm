#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int nodenum;
int ans [5005];
int A [5005];
int yes_ [5005];

struct node{
	int visit;
	int linknum;
	node * next;
};

struct dingdian{
	int nodenum;
	int num;
	node * head;
};

struct graph{
	int vertex;
	dingdian * dingdianbiao;
}; 
graph g;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(ans,0,sizeof(int)*5005);
	scanf("%d",&g.vertex);

	for(int i=1;i<=g.vertex;i++){
		g.dingdianbiao[i].num=i;
		g.dingdianbiao[i].head=NULL;
		g.dingdianbiao[i].nodenum=0;
		
	}
	scanf("%d",&nodenum);
	for(int j=0;j<nodenum;j++){
		int tempstart,tempend;
		node * tempnode1=new node;
		node * tempnode2=new node;
		scanf("%d%d",&tempstart,&tempend);
		tempnode1->next=NULL;tempnode2->next=NULL;
		tempnode1->visit=1;tempnode2->visit=1;//¿É·ÃÎÊ 
		tempnode1->linknum=tempend;
		tempnode2->linknum=tempstart; 
		g.dingdianbiao = new dingdian[5005];
		if(g.dingdianbiao[tempstart].head!=NULL){
			node * temp=g.dingdianbiao[tempstart].head;
			while(temp->next!=NULL){
				temp=temp->next;
				g.dingdianbiao[tempstart].nodenum++;
			}
			temp->next=tempnode1;
		}
		else{
			g.dingdianbiao[tempstart].head=tempnode1;
			g.dingdianbiao[tempstart].nodenum++;
		}
		if(g.dingdianbiao[tempend].head!=NULL){
			node * temp=g.dingdianbiao[tempend].head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=tempnode2;
			g.dingdianbiao[tempend].nodenum++;
		}
		else{
			g.dingdianbiao[tempend].head=tempnode2;
			g.dingdianbiao[tempend].nodenum++;
		}
	}
	A[1]=1;
	node* temp=new node ;
	temp=g.dingdianbiao[1].head;
	for(int i=1;i<=dingdianbiao[1].nodenum){
		temp=temp->next;
		A[temp.linknum]=1;
	}
	return 0;
}
	


