#include <iostream>
#include <conio.h>
using namespace std;
struct Employee{
    string name;
    int ID;
    string department;
    float salary;
};
void addEmployee(int &total,Employee *&emp,int i){
    Employee *newEmp= new Employee[total+1];
    for(int i=0;i<total;i++){
        newEmp[i]=emp[i];
    }
    cout<<"Enter Employee "<<i+1<<" Details\n";
    cout<<"Enter Employee Name : ";
    cin>>newEmp[total].name;
    cout<<"Enter Employee ID : ";
    cin>>newEmp[total].ID;
    cout<<"Enter Employee Department : ";
    cin>>newEmp[total].department;
    cout<<"Enter Employee Salary : ";
    cin>>newEmp[total].salary;
    delete[] emp;
    emp=newEmp;
    total++;
}
void displayEmployee(int searchID,int total,Employee *emp){
    bool present =false;
    for(int i=0;i<total;i++){
        if (emp[i].ID==searchID){
            cout<<"\033[32mEmployee "<<i+1<<" Details";
            cout<<"\nName : "<<emp[i].name;
            cout<<"\nDepartment : "<<emp[i].department;
            cout<<"\nSalary : "<<emp[i].salary<<"\033[0m";
            present=true;
            break;
        }
    }
    if(present==false){
            cout<<"\033[31mNo such Employee was found\033[0m";
    }
}
float calcTotal(int total,Employee *emp){
    float sum=0;
    for(int i=0;i<total;i++){
        sum+=emp[i].salary;
    }
    return sum;
}
int main(){
    Employee *emp;
    int numEmployees=0,addNum,searchID,sNum;
    void (*searchDetails)(int,int,Employee*);
    float (*totalSalary)(int,Employee*);
    totalSalary=calcTotal;
    searchDetails=displayEmployee;
    system("cls");
    cout<<"How Many Employees Would you like to add : ";
    cin>>addNum;
    for(int i=0;i<addNum;i++){
        addEmployee(numEmployees,emp,i);
        system("cls");
    }
    cout<<"How many employees do you want to search: ";
    cin>>sNum;
    for(int i=0;i<sNum;i++){
        system("cls");
        cout<<"Enter ID of Employee You want : ";
        cin>>searchID;
        searchDetails(searchID,numEmployees,emp);
        cout<<"\nPress Any Key to continue";
        getch();
    }
    system("cls");
    cout<<"Sum of all Salaries : "<<totalSalary(numEmployees,emp);
    return 0;
    
}