/*
TODO: В составе программы описать функцию, которая считает сумму
элементов списка, не равных элементу Е, значение которого введено с клавиатуры
*/
#include <iostream>
using namespace std;

int put_element(int n){
    cout<<"Element no. "<<n<<" is: \n";
    int elem;
    cin>>elem;
    return elem;
}

int main(){
    //cout<<"В составе программы описать функцию, которая считает сумму\n";
    //cout<<"элементов списка, не равных элементу Е, значение которого введено с клавиатуры";

    cout<<"Size of a linked list is: \n";
    int size;
    cin>>size;
    if(size<=0){
        cout<<"Given value is invalid\n";
        return 0;
    }
    cout<<"Enter element E\n";
    int E;
    cin>>E;
    int sum=0;


    struct linked_list{
        int info;
        linked_list* next;
    };

    linked_list* head = nullptr;
    linked_list* current;
    linked_list* tail;
    
        
    if(head==nullptr){
        head = new linked_list;
        head->info = put_element(0);
        head->next = nullptr;
        tail=head;
    }
    for(int i =0; i<size-1;i++){
        current = new linked_list;
        current->info=put_element(i+1);
        tail->next=current;
        current->next=nullptr;
        tail=current; 
    }

    //printing
    current=head;
    for(int i = 0; i < size; i++){
        if(current->info!=E)
            sum+=current->info;
        cout<<current->info<<" ";
        current=current->next;
    }
    cout<<endl;
    cout<<"The result is "<<sum<<endl;

   
    int a;
    cin>>a;


    return 0;
    
}


