


#include <iostream>
using namespace std;

struct linked_list{ // queue in essence 
        double info;
        linked_list* next;
 };

linked_list* push_element(int size, linked_list* head, linked_list* tail){
    cout<<"Enter element E\n";
    double E;
    cin>>E;

    linked_list* current;
    current=head;
    if(E>current->info){
        head=new linked_list;
        head->info=E;
        head->next=current;
    }

    else if(E<tail->info){
        linked_list* insert = new linked_list;
        insert->info=E;
        insert->next=nullptr;
        tail->next=insert;
        tail=insert;
    }

    for(int i = 0; i < size-1; i++){
        if (current->info >= E && current->next->info <= E){

            linked_list* insert = new linked_list;
            insert->info=E;
            insert->next=current->next; 
            current->next=insert;
            break;
            
        }
        current=current->next;
    }

    return head;
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

/*
    struct linked_list{
        float info;
        linked_list* next;
    };
*/
    linked_list* head = nullptr;
    linked_list* current;
    linked_list* tail;
    
    if(head==nullptr){
        head = new linked_list;

        head->info = size;

        head->next = nullptr;
        tail=head;
    }
    for(int i =0; i<size-1;i++){
        current = new linked_list;

        current->info=size-i-1;

        tail->next=current;
        current->next=nullptr;
        tail=current; 
    }

/*
    cout<<"Enter element E\n";
    int E;
    cin>>E;

    current=head;
    if(E>current->info){
        head=new linked_list;
        head->info=E;
        head->next=current;
    }

    else if(E<tail->info){
        linked_list* insert = new linked_list;
        insert->info=E;
        insert->next=nullptr;
        tail->next=insert;
        tail=insert;
    }

    for(int i = 0; i < size-1; i++){
        if (current->info >= E && current->next->info <= E){

            linked_list* insert = new linked_list;
            insert->info=E;
            insert->next=current->next; 
            current->next=insert;
            break;
            
        }
        current=current->next;
    }
    
    cout<<endl;*/

    
    //printing
    
    //current=head;
    current = push_element(size, head, tail);

    for(int i = 0; i < size+1; i++){
        cout<<current->info<<" ";
        current=current->next;
    }
    cout<<endl;

    cout<<"END"<<endl;
    int a;
    cin>>a;

    return 0;
}


