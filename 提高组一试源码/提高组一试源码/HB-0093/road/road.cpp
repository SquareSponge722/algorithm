#include <iostream>
#include <fstream>
using namespace std;
bool search[100000];
void deep(int d[],int b,int e,int& result,int p)
{
	if(b==e) return;
	for(int i =b ;i<=e;i++){
		for(int j = i;j<=e;j++){
			if(d[j]<d[p]) p=j;
		}
	}
		if(search[d[p]]==0){
			if(p==0)result += d[p];
		 
			search[d[p]] = 1;	
		}
	deep(d,b,p-1,result,p-1);
	deep(d,p+1,e,result,p+1);	
}

int main(){
ifstream in;
ofstream out;
in.open("road.in");
out.open("road.out");
int n,d[100000] = {};
in>>n;
int result = 0;
for(int i = 0;i<n;i++) in>>d[i];
int b = 0,e = n-1,p = 0;
deep(d,b,e,result,p);
out<<result;
in.close();
out.close();

}
