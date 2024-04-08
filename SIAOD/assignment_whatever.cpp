#include "VladQ.h"
#include <iostream>
using namespace std;

int main (){

    struct node {
        int info;
        struct node *next;
    };

    //typedef node* NodePtr; // указатель на тип node
    //node* NodePtr = new node;
    node* head = nullptr;
    node* p; // указатель на текущий элемент
    node* tail; // указатель на "хвост" очереди

    //12. Программирование задач с использованием динамических структур данных 125
    int N = 10; // количество элементов в очереди
    int cnt = 1; // счетчик элементов в очереди
    if (head == NULL)
    { 
        head = new node;
        head->info = cnt++; // или какому-то
        // другому значению
        head->next = NULL;
        tail = head;
    }

    for (int i = 2; i <= N; i++)
    { 
        p = new node;
        p->info = cnt++;
        tail->next = p; // в данном случае – NULL
        p->next = NULL;
        tail = p;
    }
    // Вывод очереди на экран
    p = head;
    for (int i = 1; i <= N; i++)
    { 
        cout << p->info << ' ';
        p = p->next;
    }
    cout << endl;

////////////////////////////////////////////////////
    struct node_ {
        int info;
        node_*next;
    };

    node_* head_ = NULL;
    node_* p_; // указатель на текущий элемент
    int n = 10; // количество элементов в стеке
    int c = 1; // счетчик элементов в стеке
    if (head_ == NULL)
    { 
        head_ = new node_;
        head_->info = c++; //или так: rand()%100-50;
        head_->next = NULL;
    }
    for (int i = 2; i <= n; i++)
    {
        p_ = new node_;
        p_->info = c++; //или rand()%100-50;
        p_->next = head_;
        head_ = p_;
    }

    // Вывод стека на экран
    p_ = head_;
    for (int i = 1; i <= n; i++)
    { 
        cout << p_->info << ' ';
        p_ = p_->next;
    }

    cout <<endl;
    return 0;
} 



