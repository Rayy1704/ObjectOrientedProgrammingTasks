#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct student{
    string name;
    int rollNumber;
    int age;
};

void print14(student students[],int totalNum){
    cout<<"Names Of students with Age 14 : \n";
    for(int i=0;i<totalNum;i++){
        if(students[i].age==14){
            cout<<students[i].name<<"\n";
        }
    }
}

void printEven(student students[],int totalNum){
    cout<<"Names Of students with Even Roll Numbers : \n";
    for(int i=0;i<totalNum;i++){
        if(students[i].rollNumber%2==0){
            cout<<students[i].name<<"\n";
        }
    }
}
void searchDisplay(student students[],int totalNum){
    int inputNumber;
    cout<<"Roll number of student you want to search for : \n";
    cin>>inputNumber;
    for(int i=0;i<totalNum;i++){
        if(students[i].rollNumber==inputNumber){
            cout<<"-----Details-----\n";
            cout<<"Name : "<<students[i].name<<"\n";
            cout<<"Age : "<<students[i].age<<"\n";
            break;
        }
    }
}
int main(){
    srand(time(NULL));
    int totalStudents=11;
    student students[totalStudents];
    for(int i=0;i<totalStudents;i++){
        students[i].rollNumber=i+1;
        students[i].age=rand()%4+11;
        char nameForm[3]={char(97+i),char(122-i),'\0'};
        students[i].name=nameForm;
    }
    print14(students,totalStudents);
    printEven(students,totalStudents);
    searchDisplay(students,totalStudents);
    return 0;

}