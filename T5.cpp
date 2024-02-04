#include <iostream>
#include <conio.h>
using namespace std;
struct book{
    int accessNum;
    string auther;
    string title;
    int quantity;
    bool issued;
};
int menuDisplay(){
    int num;
    system("cls");
    cout<<"----Choose Your Option----\n";
    cout<<"1.Display Book Information\n";
    cout<<"2.Add New Book\n";
    cout<<"3.Display Books of a Specific Auther\n";
    cout<<"4.Display Books of a title\n";
    cout<<"5.Display Total Number of Books\n";
    cout<<"6.Issue a Book\n";
    cout<<"7.Exit Libruary\n";
    cout<<"Option : ";
    cin>>num;
    return num;
}
void displayInfo(book *&books,int &totalBooks){
    system("cls");
    int aNum;
    cout<<"Enter Access Number of Book : ";
    cin>>aNum;
    for(int i=0;i<totalBooks;i++){
        if(books[i].accessNum==aNum){
            cout<<"\nBook Auther : "<<books[i].auther;
            cout<<"\nBook Title : "<<books[i].title;
            cout<<"\nBook Status : "<<(books[i].issued==true?"Issued":"Available");
            cout<<"\nBook Quantity : "<<books[i].quantity;
            break;
        }
    }
}
void addBook(book *&books,int &totalBooks){
    book *newBooks= new book[totalBooks+1];
    for(int i=0;i<totalBooks;i++){
        newBooks[i]=books[i];
    }
    newBooks[totalBooks].quantity=0;
    newBooks[totalBooks].issued=false;
    newBooks[totalBooks].accessNum=totalBooks+1;
    cout<<"\nEnter Book Auther : ";
    cin>>newBooks[totalBooks].auther;
    cout<<"\nEnter Book Title : ";
    cin>>newBooks[totalBooks].title;
    cout<<"\nThanks for the input";
    
    books=newBooks;
    totalBooks++;
    int max=0;
    for(int i=0;i<totalBooks;i++){
        if(books[i].title==books[totalBooks-1].title){
            max=(books[i].quantity>max?books[i].quantity:max);
        }
    }
    max++;
    for(int i=0;i<totalBooks;i++){
        if(books[i].title==books[totalBooks-1].title){
            books[i].quantity=max;
        }
    }
}
void displayBooksOfAuther(book *&books,int &totalBooks){
    string aName;
    cout<<"Enter name of Auther : ";
    cin>>aName;
    for(int i=0;i<totalBooks;i++){
        if(aName==books[i].auther){
            cout<<"\nBook Title : "<<books[i].title;
            cout<<"\nBook Status : "<<(books[i].issued==true?"Issued":"Available");
            cout<<"\nAccess Number : "<<books[i].accessNum;
            cout<<"\nBook Quantity : "<<books[i].quantity;
            cout<<"\n\n";
        }
    }
}
void displayBooksOfTitle(book *&books,int &totalBooks){
    string bTitle;
    cout<<"Enter Book title : ";
    cin>>bTitle;
    for(int i=0;i<totalBooks;i++){
        if(bTitle==books[i].title){
            cout<<"\nBook Auther : "<<books[i].auther;
            cout<<"\nBook Status : "<<(books[i].issued==true?"Issued":"Available");
            cout<<"\nAccess Number : "<<books[i].accessNum;
            cout<<"\nBook Quantity : "<<books[i].quantity;
            cout<<"\n\n";
        }
    }   
}
void issueBook(book *&books,int &totalBooks){
    int aNum;
    cout<<"Enter Access Number of Book : ";
    cin>>aNum;
    for(int i=0;i<totalBooks;i++){
        if(aNum==books[i].accessNum){
            cout<<"\nBook Auther : "<<books[i].auther;
            cout<<"\nAccess Title : "<<books[i].title;
            books[i].issued=true;
            cout<<"\nNew Book Status : "<<(books[i].issued==true?"Issued":"Available");
            for(int j=0;j<totalBooks;j++){
                if(books[i].title==books[j].title){
                    books[j].quantity--;
                }
            }
            cout<<"\nNew Book Quantity : "<<books[i].quantity;
        }
    }
}
int main(){
    book *books;
    int totalBooks=0,choice;
    do{
        choice=menuDisplay();
        system("cls");
        switch(choice){
            case 1:
                displayInfo(books,totalBooks);
                break;
            case 2:
                addBook(books,totalBooks);
                break;
            case 3:
                displayBooksOfAuther(books,totalBooks);
                break;
            case 4:
                displayBooksOfTitle(books,totalBooks);
                break;
            case 5:
                cout<<"Total Number of Books : "<<totalBooks;
                break;
            case 6:
                issueBook(books,totalBooks);
                break; 
            case 7:
                break;
            default :
                cout<<"Enter A Valid Choice";
        }
        cout<<"\npress anything to continue";
        getch();
        system("cls");
    }while(choice!=7);
    return 0;
}