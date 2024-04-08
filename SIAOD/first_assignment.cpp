
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    //28th  Расчет активности на основе выполнения индивидуальных заданий.

Структура записи по выполненным заданиям: 
    код студента (номер зачетной книжки), 
    номер задания,
    задача 1, 
    задача 2, 
    задача 3. 
Балл за задачу: задача 1 – 10 баллов; задача 2 -20 баллов; задача 3 -60 баллов.

Операции
1) Заполнение данных по заданному заданию заданного студента с клавиатуры. 
2) Вставить запись по студенту в начало таблицы. 
3) Удалить записи по заданному студенту.
4) Сформировать таблицу
*/

struct student{
        int studentID;
        int assignmentNO;
        float problemFirst;
        float problemSecond;
        float problemThird;
    };
    
vector<student> students;

void add_student(){
        student student;
        cout<<"StudentID : ";
        cin>> student.studentID;
        cout<<"Personal assignment no. : ";
        cin>> student.assignmentNO;
        cout<<"Grade for problem no. 1 [0,10]: ";
        cin>> student.problemFirst;
        cout<<"Grade for problem no. 2 [0,20]: ";
        cin>> student.problemSecond;
        cout<<"Grade for problem no. 3 [0,60]: ";
        cin>> student.problemThird;
        if(student.problemFirst<0 || student.problemFirst>10 || 
            student.problemSecond<0 || student.problemSecond>20 ||
            student.problemThird<0 || student.problemThird>60){
            cout<<"Invalid grades, please retry\n";
            add_student();
        } 

        students.push_back(student);
    
}

void insert_at_beginning(){
        student student;
        cout<<"StudentID : ";
        cin>> student.studentID;
        
        cout<<"Personal assignment no. : ";
        cin>> student.assignmentNO;
        cout<<"Grade for problem no. 1 [0,10]: ";
        cin>> student.problemFirst;
        cout<<"Grade for problem no. 2 [0,20]: ";
        cin>> student.problemSecond;
        cout<<"Grade for problem no. 3 [0,60]: ";
        cin>> student.problemThird;

        if(student.problemFirst<0 || student.problemFirst>10 || 
            student.problemSecond<0 || student.problemSecond>20 ||
            student.problemThird<0 || student.problemThird>60){
            cout<<"Invalid grades, please retry\n";
            insert_at_beginning();
        } 

        students.insert(students.begin(), student);
}

void delete_student(int StudentID){
    for(int i=0; i<students.size();i++){
        if (students.at(i).studentID==StudentID){
            students.erase(students.begin()+i);
        }
    }
    cout<<"Deletion completed.\n";
}

void display_table(){
    for (auto v : students){
        cout<<"-----\n";
        cout<<"Student's ID: "<< v.studentID<<
        "\nPersonal assignment no.: "<<
        v.assignmentNO<<"\nGrade for problem no. 1: "<<
        v.problemFirst<<"\nGrade for problem no. 2: "<<
        v.problemSecond<<"\nGrade for problem no. 3: "<<
        v.problemThird;
        cout<<"\n-----\n";
    }
}


int main(){
    string introduction = "Assignment_1\n";
    cout<<introduction;
    string str = "If you want to proceed, print 'Yes; if you want to quit program, print 'No'\n";
    string response;
    string action = "If you want to add student info, write 'Add' \nIf you want to insert student's info at the beginning of the table, write 'Insert'\nIf you want to delete student's info, write 'Delete' \nIf you want to display table, write 'Display'\nIf you want to terminate program,  write 'Stop'\n";

    while(true){  
       cout<<str;
       cin>>response;
       if(response.compare("Yes")==0||response.compare("YES")==0||response.compare("yes")==0){
            //main body
            cout<<action;
            string resp;
            cin>>resp;
            
            if (resp.compare("Add")==0||resp.compare("ADD")==0||resp.compare("add")==0){
                add_student();
            }
            
            if (resp.compare("Insert")==0||resp.compare("INSERT")==0||resp.compare("insert")==0){
                insert_at_beginning();
            }
            
            if (resp.compare("Delete")==0||resp.compare("DELETE")==0||resp.compare("delete")==0){
                cout<<"Write student's ID whose info you want to delete\n";
                int a=0; 
                cin>>a;
                delete_student(a);
            }
            if (resp.compare("Display")==0||resp.compare("DISPLAY")==0||resp.compare("display")==0){
                display_table();
            }

            if(resp.compare("Stop")==0||resp.compare("stop")==0||resp.compare("STOP")==0){
                cout<<"Program has been terminated successfully\n";
                break;
            }

        }else{
            cout<<"Program has been terminated successfully\n";
            break;
        }
    }
    cout<<"Press any key to quit\n";
    cin>>response;
}