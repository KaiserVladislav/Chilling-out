
#include <iostream>
using namespace std;


// look into second tier pointers
// destructors, copy constructors

class myClass{
    public : 
        int a;
        myClass(int id);
        ~myClass();
        int anotherF();
        void show();
};

myClass::myClass(int id){
    cout<<"The object has been created\n";
    cout<<"ID is: "<<id;
}
myClass::~myClass(){
    cout<<"DESTRUCTOR";
}

int anotherF(){

}
void show(){

}


int main(){
    
    myClass obj(12);
    myClass* pbj = &obj;
    delete pbj;

}
