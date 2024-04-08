#include <iostream>
#include "Placeholder.h"
using namespace std;



int main(){
    int i_data=0; // 1
    cin>>i_data;

    Placeholder object(i_data); // 2

    object.print(); // 3
    
    object.public_change(); // 4

    object.print(); // 5

    cin>>i_data; // 6

    object.public_field*=i_data; // 7

    object.print(); // 8

    object.invoke_private_change(); // 9

    object.print(); // 10

    int a;
    cin>>a;

    return 0;
}