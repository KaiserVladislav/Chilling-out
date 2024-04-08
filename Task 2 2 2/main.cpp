#include <iostream>
#include "Placeholder.h"
using namespace std;



int main(){
    int i_data=0; // 1
    cin>>i_data;

    Placeholder* p_object = new Placeholder(i_data); // 2

    p_object->print(); // 3
    
    p_object->public_change(); // 4

    p_object->print(); // 5

    cin>>i_data; // 6

    if (i_data>p_object->public_field) // 7
        p_object->public_field=i_data*8; 

    p_object->print(); // 9

    p_object->invoke_private_change(); // 10

    p_object->print(); // 11

    int a;
    cin>>a;

    return 0;
}