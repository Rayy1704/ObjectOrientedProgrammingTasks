#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct employee{
    string name;
    float oldSalary;
    float newSalary;
    int workHours;
};

int main(){
    employee Employees[10];
    for(int i=0;i<10;i++){
        char nameForm[3]={char(97+i),char(122-i),'\0'};
        Employees[i].name=nameForm;
        Employees[i].oldSalary=rand()%900+100;
        Employees[i].workHours=(rand()%2==0?8:(rand()%2==0?10:rand()%13+12));
        Employees[i].newSalary=Employees[i].oldSalary+(Employees[i].workHours==8?50:Employees[i].workHours==10?100:150);
    }
    cout<<"Name---WorkingHours----Old Salary----Final Salary\n";
    for(int i=0;i<10;i++){
        cout<<" "<<Employees[i].name<<"          "<<Employees[i].workHours<<"            "<<Employees[i].oldSalary<<"             "<<Employees[i].newSalary<<endl;
    }
}