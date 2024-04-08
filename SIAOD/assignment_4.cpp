#include <iostream>
using namespace std;
int F(int n);
int counter=0;

int main(){
    for(int i=1;i<10;i++){
        cout<<"Function of "<<i<<" is "<<F(i)<<endl;
        cout<<"Complexity is "<<counter<<endl;
        counter=0;
    } 
}

int F(int n){
    counter++;
    if (n<=1)
        return 2;
    else if (n>1 && n%2)
        return 1+F(n-1)*F(n-2)-F(n-1)-F(n-2);
    else 
        return 2*F(n-1);
}


