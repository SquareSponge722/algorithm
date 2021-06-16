#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int main(){

    //1
    //对于以\n为结束标志的int数据读入
    //例如
    //3
    //5 2 3 5
    //7 8 6
    //3 2 1 5 4 9
    int n1;
    int array1[20][20];
    scanf("%d",&n1);
    for(int i = 0;i < n1;i++){
        int tot1 = 0;
        do{
            scanf("%d",&array1[i][tot1++]);
        }while(getchar() != '\n');
    }
    
    //2
    //对于读入一行带空格的字符串
    string str2;
    //cin >> str2; 这是明显不行的
    getline(cin,str2);

    return 0;
}