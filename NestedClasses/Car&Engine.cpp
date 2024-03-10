#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

class Engine{
    int cylinders;
    int horsePower;
    public:
    Engine(){
        cylinders=0;
        horsePower=0;
    }
    void setHp(int hp){
        horsePower=hp;
    }
    void setCyl(int c){
        cylinders=c;
    }
    int getHp(){
        return horsePower;
    }
    int getCyl(){
        return cylinders;
    }
};
class Car{
    string make;
    string model;
    Engine engine;
    public:
    Car(int hp,int c,string inp_make,string inp_model){
        make=inp_make;
        model=inp_model;
        engine.setHp(hp);
        engine.setCyl(c);
    }
    void printInfo(){
        cout<<"Make : "<<make;
        cout<<"\nModel : "<<model;
        cout<<"\nNo. of Cylinders in Engine : "<<engine.getCyl();
        cout<<"\nEngine HorsePower : "<<engine.getHp();
    }
    void setMake(string inp_make){
        make=inp_make;
    }
    void setModel(string inp_model){
        model=inp_model;
    }
    string getMake(){
        return make;
    }
    string getModel(){
        return model;
    }
    void setEngineHp(int hp){
        engine.setHp(hp);
    }
    void setEngineCyl(int c){
        engine.setCyl(c);
    }
    int getHp(){
        return engine.getHp();
    }
    int getCyl(){
        return engine.getCyl();
    }
};
int menu(){
    char m;
    int choice=0;
    do{
        system("cls");
        cout<<"------Car Menu-----\n";
        cout<<(choice==0?"\033[0;32m->\033[0;0m ":"")<<"Set Make (Company)\n";
        cout<<(choice==1?"\033[0;32m->\033[0;0m ":"")<<"Set Model\n";
        cout<<(choice==2?"\033[0;32m->\033[0;0m ":"")<<"Set Engine Cylinders\n";
        cout<<(choice==3?"\033[0;32m->\033[0;0m ":"")<<"Set Engine Horse Power\n";
        cout<<(choice==4?"\033[0;32m->\033[0;0m ":"")<<"Print Car Information\n";
        cout<<(choice==5?"\033[0;32m->\033[0;0m ":"")<<"Exit"<<endl;
        m=getch();
        if(m==char(224)){
            m=getch();
            if(m=='H'&&choice!=0){
                choice--;
            }
            else if (m=='P'&&choice!=5){
                choice++;
            }
        }
    }while(m!=char(13));
    system("cls");
    return choice;
}
void process(Car &car,int choice){
    if(choice==0){
            string temp_make;
            cout<<"Enter Make : ";
            cin>>temp_make;
            car.setMake(temp_make);
        }
        else if(choice==1){
            string temp_model;
            cout<<"Enter Model : ";
            cin>>temp_model;
            car.setModel(temp_model);
        }
        else if(choice==2){
            int temp_cyl;
            cout<<"Enter No. of Cylinders of Engine : ";
            cin>>temp_cyl;
            car.setEngineCyl(temp_cyl);
        }
        else if(choice==3){
            int temp_hp;
            cout<<"Enter Engine Horse Power : ";
            cin>>temp_hp;
            car.setEngineHp(temp_hp);
        }
        else if(choice==4){
            car.printInfo();
            cout<<"\nPress any key to continue.";
            getch();
        }
}
int main(){
    Car car(10,8,"Toyota","Corolla");
    int choice;
    do{
        choice=menu();
        process(car,choice);
    }while(choice!=5);
    cout<<"Menu Exit!";
    return 0;
}