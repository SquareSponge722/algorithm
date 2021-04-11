#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int STR_LENGTH = 12;
string str = "Hello World!";
int main(){
    
    cout << str << endl;

    //Hello World!Hello World!
    cout << str.append(str) << endl;

    //Hello World!
    cout << str.erase(STR_LENGTH,STR_LENGTH) << endl;

    //2
    cout << str.find("l") << endl;
    //2
    cout << str.find("l",2) << endl;
    //3
    cout << str.find("l",3) << endl;

    int position = 0;
    while(str.find("l",position) != string::npos){
        // do something
        position++;
    }

    //4
    string searchSet = "Hel";
    cout << str.find_first_not_of(searchSet,0) << endl;

    //7
    cout << str.rfind("o") << endl;

    //Heollo World!
    cout << str.insert(2,"o") << endl;

    //HeKKKKollo World!
    cout << str.insert(2,4,'K') << endl;
    //cout << str.insert(2,4,"kk") << endl; WRONG!!
    
    //!dlroW olloKKKKeH
    reverse(str.begin(),str.end()); //reverse的适用容器很多
    cout << str << endl;

    //dlroW olloKKKKeH
    cout << str.substr(1) << endl;
    //!dl
    cout << str.substr(0,3) << endl; //substr不会更改str自身

    //re&lroW olloKKKKeH
    cout << str.replace(str.find("!"),2,"re&") << endl;
    //re&lroW olloK@@
    cout << str.replace(str.end() - 5,str.end(),"@@") << endl;

    string tmp = "12345";
    //12345&lroW olloK@@
    cout << str.replace(0,2,tmp,0,tmp.length()) << endl; //参数不可以是迭代器

    return 0;
}