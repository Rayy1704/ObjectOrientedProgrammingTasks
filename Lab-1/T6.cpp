#include <iostream>
using namespace std;
enum cousine{Italian=1,Arabic,Desi};
struct chef{
    string name;
    cousine specialisation;   
};
struct order{
    int orderNum;
    cousine type;
    string name;
    string chef;
};

void addChef(int &totalChefs,chef *&chefs){
    chef *newChefs= new chef[totalChefs+1];
    int specialisationNum;
    for(int i=0;i<totalChefs;i++){
        newChefs[i]=chefs[i];
    }
    cout<<"\nEnter Chef Name : ";
    cin>>newChefs[totalChefs].name;
    cout<<"--Choose Chef Specialisation---";
    cout<<"\n1.Italian";
    cout<<"\n2.Arabic";
    cout<<"\n3.Desi";
    cout<<"\nSpecialisation : ";
    cin>>specialisationNum;
    newChefs[totalChefs].specialisation=static_cast<cousine>(specialisationNum);
    cout<<"\n\033[32mChef Added to List\033[0m";
    chefs=newChefs;
    totalChefs++;
}
void addOrder(int &totalOrders,order *&orders){
    int orderNum;
    order *newOrders= new order[totalOrders+1];
    for(int i=0;i<totalOrders;i++){
        newOrders[i]=orders[i];
    }
    cout<<"\nEnter Dish Name : ";
    cin>>newOrders[totalOrders].name;
    cout<<"\n---Select Dish Type---";
    cout<<"\n1.Italian";
    cout<<"\n2.Arabic";
    cout<<"\n3.Desi";
    cout<<"\nType : ";
    cin>>orderNum;
    newOrders[totalOrders].type=static_cast<cousine>(orderNum);
    newOrders[totalOrders].orderNum = totalOrders+1;
    cout<<"\n\033[32mOrder # "<<newOrders[totalOrders].orderNum<<" Submitted!\033[0m";
    orders=newOrders;
    totalOrders++;
}
void assignOrders(int &totalOrders,order *&orders,int &totalChefs,chef *&chefs){
    for(int i=0 ;i<totalOrders;i++){
        bool assigned=false;
        for(int j=0;j<totalChefs;j++){
            if(orders[i].type==chefs[j].specialisation){
                orders[i].chef=chefs[j].name;
                assigned=true;
                break;
            }
        }
        if(assigned==false){
            orders[i].chef="Chef of Speciality not available";
        }
    }
}
int main(){
    int totalChefs=0;
    chef *chefs;
    int totalOrders=0;
    order *orders;
    int newOrders,newChefs;
    void (*listChef)(int&,chef*&);
    void (*listOrder)(int&,order*&);
    void (*assignment)(int&,order*&,int&,chef*&);
    listChef=addChef;
    listOrder=addOrder;
    assignment=assignOrders;
    cout<<"How many chefs need to be added : ";
    cin>>newChefs;
    for(int i=0;i<newChefs;i++){
        listChef(totalChefs,chefs);
    }
    cout<<"\nHow many Orders need to be added : ";
    cin>>newOrders;
    for(int i=0;i<newOrders;i++){
        listOrder(totalOrders,orders);
    }
    assignment(totalOrders,orders,totalChefs,chefs);
    for(int i=0;i<totalOrders;i++){
        cout<<"\nOrder #"<<orders[i].orderNum<<" has been assigned to "<<orders[i].chef;
    }
    return 0;
}