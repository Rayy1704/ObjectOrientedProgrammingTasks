#include <iostream>
using namespace std;
union EmployeeDetails{
    float salary;
    const char* department;
};
int main(){
EmployeeDetails john;
john.salary=42000;
john.department="Marketing";
cout<<"-----Details-----";
cout<<"\nSalary : "<<john.salary;
cout<<"\nDepartment : "<<john.department;
cout<<"\n\nThe Union only stores the department as it only stores one data\nonly one memory slot to be used/shared by all members at once this can be\navoided by displaying after storing and repeating.\n";
john.salary=42000;
cout<<"\nSalary : "<<john.salary;
john.department="Marketing";
cout<<"\nDepartment : "<<john.department;
return 0;
}