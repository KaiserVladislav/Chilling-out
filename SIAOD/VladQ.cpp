#include <iostream>
#include <conio.h>
using namespace std;

int main ()
{ 
    int N; // количество элементов в списке
    int target; // искомое значение
    int count; // местоположение искомого элемента
    struct node {
        int dat; // информационное поле
        node *link; // поле-указатель
        };
        typedef node *NodePtr; //указатель на тип Node
        NodePtr head = NULL;
        NodePtr here; // указатель на текущий элемент
        cout << "Input a quantity elements: ";
        cin >> N;
        for (int i = 0; i<N; i++) // формируем стек
        { 
            if (head == NULL)
            { 
                head = new node;
                if (head == NULL)
                { 
                    cout << "Not enough memory !" << endl;
                    exit (1);
                }
                head->dat = rand()%100 - 50;
                cout << head->dat << ' ';
                head->link = NULL;
            }
            else
            { 
                here = new node;
                if (here == NULL)
                {
                    cout << "Not enough memory !"<< endl;
                    exit (2);
                }
                here->dat = rand()%100 - 50;
                cout << here->dat << ' ';
                here->link = head;
                head = here;
            }
        }

        cout <<endl;

        cout << "Input target ";
        cin >> target;
        here = head; // встали в начало списка
        count = 1;
        if (here == NULL)
            cout << "List is empty!" << endl;
        else {
            while (here->dat != target && here->link != NULL)
            { 
                here = here->link;
                count++;
            }
            if (here->dat == target)
                cout << "Target element has a number " << count << endl;
            else
                cout<<"Target element is not found!"<< endl;
        }
    int n;
    cin>>n;
    return 0;
}

