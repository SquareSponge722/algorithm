#include <iostream>
using std::cout;
using std::endl;
class Cla
{
public:
    int data;
};
void Pchange(Cla* ot){
    ot = new(Cla);
    ot->data = 20;
}
void Rchange(Cla &ot){
    ot = Cla();
    ot.data = 20;
}
int main(){
    Cla t = Cla();
    t.data = 5;
    cout << t.data << endl; //5
    Pchange(&t);
    cout << t.data << endl; //5
    Rchange(t);
    cout << t.data << endl; //20
    return 0;
}