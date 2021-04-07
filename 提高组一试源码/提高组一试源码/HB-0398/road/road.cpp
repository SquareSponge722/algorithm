#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int n,deep;//路程长度 ,深度 
int Min1,day=0;
vector<int> linshi1,linshi2;
void divcon(vector<int> z,vector<int> f,int g);
void divcon(vector<int> temp,vector<int> real,int Min)
{

	for(int a=0;a<Min;a++){
		for(int b=0;b<n;b++){
			if(b!=0&&b!=(n-1)&&(real[b]==0)&&real[b-1]!=0&&real[b+1]!=0)
			day++;
			else if((b==0)&&(real[b+1]==0)&&real[b]!=0)
			day++;
			else if((b==n-1)&&real[b]!=0&&(real[b-1]==0))
			day++;
	        else if(real[b]!=0)
			real[b]=real[b]-1;
			
		}
		day++;
		   for(int b=0;b<n;b++){
			if(temp[b]!=0){
			temp[b]=temp[b]-1;
			}
		
		}
		
	}
	linshi1=temp;
linshi2=real;
}
	
	int main()
{
	fstream input;
	input.open("road.in",ios::in);//读入流road 
	input>>n;
	vector<int> linshi;//将各区间深度储存 
	for(int a=0;a<n;a++){
	input>>deep;
	linshi.push_back(deep);}
	input.close();
	vector<int> zhenshi=linshi;
    sort(linshi.begin(),linshi.end());
    /*for(int a=0;a<n;a++){
    	cout<<temp[a];
	}*/
		day-=linshi[0];
		for(int c=0;c<n;c++)
	{
	    if(linshi[c]!=0){
		Min1=linshi[c];
		divcon(linshi,zhenshi,Min1);
		linshi=linshi1;
		zhenshi=linshi2;
		
	}
		
	}
	fstream output;
	output.open("road.out",ios::out);
	output<<day<<endl;
    output.close();
	return 0;
}
