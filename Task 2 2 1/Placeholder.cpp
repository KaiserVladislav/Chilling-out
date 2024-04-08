#include "Placeholder.h"
#include <iostream>
using namespace std;

Placeholder::Placeholder(int a){
    public_field=a;
    private_field=2*a;
}

void Placeholder::print(){
    cout<<"Value of the available property "<<public_field<<"; Value of a hidden property "<<private_field<<endl;
}
void Placeholder::public_change(){
    public_field+=1;
    private_field+=4;
}

void Placeholder::private_change(){
    public_field+=5;
    private_field+=7;
}

void Placeholder::invoke_private_change(){
    private_change();
}


