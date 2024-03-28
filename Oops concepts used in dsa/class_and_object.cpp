#include<iostream>
using namespace std;

class Rectangle{
public:
    int l;
    int b;
    Rectangle(){ //Default Constructor - no arguments passed
        l=0;
        b=0;
    }
    Rectangle(int x, int y){ //Parameterised Constructor - arguments passed
        l=x;
        b=y;
    }
    Rectangle(Rectangle &r){ //Copy Constructor - initialise the object with an existing object
        l=r.l;
        b=r.b;
    }
    ~Rectangle(){
        cout<<"Destructor is called"<<endl;
    }
};
/*class Fruits{
public:
    string name;
    string color;
};*/

int main(){
    Rectangle* r1;
    cout<<r1->l<<" "<<r1->b<<endl;
    delete r1;

    Rectangle r2(3,4);
    cout<<r2.l<<" "<<r2.b<<endl;

    Rectangle r3=r2;
    cout<<r3.l<<" "<<r3.b<<endl;
    /*Fruits apple;
    apple.name="Apple";
    apple.color="Red";
    cout<<apple.name<<"-"<<apple.color<<endl;

    Fruits *mango = new Fruits();
    mango->name="Mango";
    mango->color="Yellow";*/
    return 0;
}