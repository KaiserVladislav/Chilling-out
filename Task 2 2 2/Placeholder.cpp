#include "Placeholder.h"
#include <iostream>
using namespace std;

Placeholder::Placeholder(int a){
    public_field=a;
    private_field=3*a;
}

void Placeholder::print(){
    cout<<"Value of the available property "<<public_field<<"; Value of a hidden property "<<private_field<<endl;
}
void Placeholder::public_change(){
    public_field+=4;
    private_field+=1;
}

void Placeholder::private_change(){
    public_field+=7;
    private_field+=5;
}

void Placeholder::invoke_private_change(){
    private_change();
}


