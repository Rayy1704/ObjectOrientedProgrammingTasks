#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <ctime>
using namespace std;
void overlapError(string map[][15]){//error handling for the case of placing character oevr an area with a character present 
    system("cls");
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            cout<<"\033[33m"<<map[i][j]<<"  "<<"\033[0m";
        }
        cout<<endl;
    }
    Beep(10000,1000);
    system("cls");
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            cout<<map[i][j]<<"  ";
        }
        cout<<endl;
    }
}
void overlapError(string map[][9]){//error handling for the case of placing character oevr an area with a character present 
    system("cls");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<"\033[33m"<<map[i][j]<<"  "<<"\033[0m";
        }
        cout<<endl;
    }
    Beep(10000,1000);
    system("cls");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<map[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void scp(int x, int y){//function to set cursor to the position entered
    x=1+3*x;
    y=1+y;
    cout << "\033[" << y << ";" << x << "H";//go to coordinates
}
bool emptyMid(string chars[]){
    if(chars[0]==chars[2]&&chars[1]=="X"&&chars[0]!="X"){
        return true;
    }
    return false;
}
class cursor{//class for cursor 
    int xPos=0;//members
    int yPos=0;
    int prevX=0;
    int prevY=0;
    public:
    void move(char mv,int n){//memeber functions for manipulation of cursor 
        if(mv==char(224)){
            prevX=xPos;
            prevY=yPos;
            mv=getch();
            if(mv=='K'){
                if(xPos==0)
                    xPos=n-1;
                else
                    xPos--;
            }
            else if(mv=='M'){
                if(xPos==n-1)
                    xPos=0;
                else 
                    xPos++;
            }
            else if(mv=='P'){
                if(yPos==n-1)
                    yPos=0;
                else 
                    yPos++;
            }
            else if(mv=='H'){
                if(yPos==0)
                    yPos=n-1;
                else 
                    yPos--;
            }
        }
    }
    void set(string map[][9],string turn[],int op){
        scp(prevX,prevY);
        cout<<map[prevY][prevX];
        scp(xPos,yPos);
        cout<<turn[op];
        scp(10,10);
    }
    void set(string map[][15],string turn[],int op){
        scp(prevX,prevY);
        cout<<map[prevY][prevX];
        scp(xPos,yPos);
        cout<<turn[op];
        scp(16,16);
    }
    void reset(string map[][9]){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(map[i][j]=="X"){
                    xPos=j;
                    prevX=j;
                    yPos=i;
                    prevY=i;
                    i=9;
                    j=9;
                }
            }
        }
    }
    void reset(string map[][15]){
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                if(map[i][j]=="X"){
                    xPos=j;
                    prevX=j;
                    yPos=i;
                    prevY=i;
                    i=15;
                    j=15;
                }
            }
        }
    }
    void placement(string map[][9],cursor &pointer,string turn[],int &op){//function to place character in desired place in backened and front end 
    if(map[pointer.yPos][pointer.xPos]=="X"){
        map[pointer.yPos][pointer.xPos]=turn[op];
        op=(op==0?1:0);
        pointer.reset(map);
    }
    else{
        overlapError(map);
        pointer.reset(map);
    }
}
void placement(string map[][15],cursor &pointer,string turn[],int &op){//function to place character in desired place in backened and front end 
    if(map[pointer.yPos][pointer.xPos]=="X"){
        map[pointer.yPos][pointer.xPos]=turn[op];
        op=(op==0?1:0);
        pointer.reset(map);
    }
    else{
        overlapError(map);
        pointer.reset(map);
    }
}
};
int menu(){//function to present menu to choose grid size
    string options[2]={"\033[32m->\033[0m 9 x 9\n15 x 15","9 x 9\n\033[32m->\033[0m 15 x 15"};
    char op;
    int i=0;
    do{
    system("cls");
    cout<<"\033[34m---Choose Board Size---\033[0m\n";
    cout<<options[i]<<endl;
    op=getch();
    if(op==char(224)){
        op=getch();
        if(op=='H'&&i!=0){
            i--;
        }
        else if(op=='P'&&i!=1){
            i++;
        }
    }
    }while(op!=char(13));
    return (i==0?9:15);
}
void initialiseAndPrint(string map[9][9]){//function to initialise map andprint it 
    system("cls");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            map[j][i]="X";
            cout<<map[j][i]<<"  ";
        }
        cout<<endl;
    }
}
void initialiseAndPrint(string map[15][15]){
    system("cls");
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            map[j][i]="X";
            cout<<map[j][i]<<"  ";
        }
        cout<<endl;
    }
}

bool checkSame(string chars[],int n=5){//checks to see if elements of an array are same 
    for(int i=0;i<n-1;i++){
        if(chars[i]!=chars[i+1]){
            return false;
        }
    }
    return true;
}
bool endGame(string map[][9],string turn[],int op,int print=1){//function that checks to see if game hase ended and prints output 
    string temp[5]; 
    for(int i=0;i<5;i++){//for vertical win case
        for(int j=0;j<9;j++){
            if(map[i][j]!="X"){
                for(int count=0;count<5;count++){
                    temp[count]=map[i+count][j];
                }
                if(checkSame(temp)==true){
                    scp(0,10);
                    if(print==1){
                        cout<<turn[!op]<<" \033[33mWon the Game !\033[0m";
                    }
                    return true;
                }
            }
        }
    }
    for(int i=0;i<9;i++){//for horizontal win case
        for(int j=0;j<5;j++){
            if(map[i][j]!="X"){
                for(int count=0;count<5;count++){
                    temp[count]=map[i][j+count];
                }
                if(checkSame(temp)==true){
                    scp(0,10);
                    if(print==1){
                        cout<<turn[!op]<<" \033[33mWon the Game !\033[0m";
                    }
                    return true;
                }
            }
        }
    }
    for(int i=0;i<5;i++){//check for primary diognal in case
        for(int j=0;j<5;j++){
            if(map[i][j]!="X"){
                for(int count=0;count<5;count++){
                    temp[count]=map[i+count][j+count];
                }
                if(checkSame(temp)==true){
                    scp(0,10);
                    if(print==1){
                        
                        cout<<turn[!op]<<" \033[33mWon the Game !\033[0m";
                    }
                    return true;
                }
            }
        }
    }
    for(int i=0;i<5;i++){   //check for secondary diognal win case
        for(int j=4;j<9;j++){
            if(map[i][j]!="X"){
                for(int count=0;count<5;count++){
                    temp[count]=map[i+count][j-count];
                }
                if(checkSame(temp)==true){
                    scp(0,10);
                    if(print==1){
                        cout<<turn[!op]<<" \033[33mWon the Game !\033[0m";
                    }
                    return true;
                }
            }
        }
    }
    
    //now check for draw
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(map[i][j]=="X"){
                return false;
            }
        }
    }
    scp(0,10);
    if(print==1){
        cout<<"\033[33mGame ended in Draw!\033[0m";
    }
    return true;
}
bool endGame(string map[][15],string turn[],int op,int print =1){//same function as above scaled for 15x15
    string temp[5]; 
    for(int i=0;i<11;i++){//for vertical
        for(int j=0;j<15;j++){
            if(map[i][j]!="X"){
                for(int count=0;count<5;count++){
                    temp[count]=map[i+count][j];
                }
                if(checkSame(temp)==true){
                    scp(0,16);
                    if(print==1){
                        cout<<turn[!op]<<" \033[33mWon the Game !\033[0m";
                    }
                
                    return true;
                }
            }
        }
    }
    for(int i=0;i<15;i++){//for horizontal
        for(int j=0;j<11;j++){
            if(map[i][j]!="X"){
                for(int count=0;count<5;count++){
                    temp[count]=map[i][j+count];
                }
                if(checkSame(temp)==true){
                    scp(0,16);
                    if(print==1){
                        cout<<turn[!op]<<" \033[33mWon the Game !\033[0m";
                    }
                    return true;
                }
            }
        }
    }
    for(int i=0;i<11;i++){//check for primary diognal
        for(int j=0;j<11;j++){
            if(map[i][j]!="X"){
                for(int count=0;count<5;count++){
                    temp[count]=map[i+count][j+count];
                }
                if(checkSame(temp)==true){
                    scp(0,16);
                    if(print==1){
                        cout<<turn[!op]<<" \033[33mWon the Game !\033[0m";
                    }
                    return true;
                }
            }
        }
    }
    //check for secondary diognal
    for(int i=0;i<11;i++){
        for(int j=4;j<15;j++){
            if(map[i][j]!="X"){
                for(int count=0;count<5;count++){
                    temp[count]=map[i+count][j-count];
                }
                if(checkSame(temp)==true){
                    scp(0,16);
                    if(print==1){
                        cout<<turn[!op]<<" \033[33mWon the Game !\033[0m";
                    }
                    return true;
                }
            }
        }
    }
    
    //now check for draw
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(map[i][j]=="X"){
                return false;
            }
        }
    }
    scp(0,16);
    if(print ==1){
        cout<<"\033[33mGame ended in Draw!\033[0m";
    }
    
    return true;
}
bool botMenu(){//menu that prompts user to choose to use Ai bopt or not uing arrow keys 
    string options[2]={"\033[32m->\033[0m Player vs Player\nPlayer vs Bot","Player vs Player\n\033[32m->\033[0m Player vs Bot"};
    char op;
    int i=0;
    do{
    system("cls");
    cout<<"\033[34m---Choose Game Mode---\033[0m\n";
    cout<<options[i]<<endl;
    op=getch();
    if(op==char(224)){
        op=getch();
        if(op=='H'&&i!=0){
            i--;
        }
        else if(op=='P'&&i!=1){
            i++;
        }
    }
    }while(op!=char(13));
    return (i==0?false:true);
}
void botMove(string map[][9],string turn[],int &op){//function to stimulate bot move 
    string temp[3]; 

    srand(time(NULL));
    //for game end move
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(map[i][j]=="X"){  
                map[i][j]=turn[1];
                if(endGame(map,turn,op,0)==true){
                    map[i][j]=turn[1];
                    scp(j,i);
                    cout<<map[i][j];
                    return;
                }
                else{
                    map[i][j]="X";
                }
            }
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(map[i][j]=="X"){  
                map[i][j]=turn[0];
                if(endGame(map,turn,op,0)==true){
                    map[i][j]=turn[1];
                    scp(j,i);
                    cout<<map[i][j];
                    return;
                }
                else{
                    map[i][j]="X";
                }
            }
        }
    }

    //for opponent wining or self wining situations situations 
    for(int i=0;i<7;i++){//for vertical bot win or prevention of player win 
        for(int j=0;j<9;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j];
                }
                if(checkSame(temp,3)==true){
                    if(map[i+3][j]=="X"&&i+3<9){
                        map[i+3][j]=turn[1];
                        scp(j,i+3);
                        cout<<map[i+3][j];
                        return;
                    }
                    else if(map[i-1][j]=="X"&&i-1>=0){
                        map[i-1][j]=turn[1];
                        scp(j,i-1);
                        cout<<map[i-1][j];
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<9;i++){//for horixontal bot win or prevention of player win 
        for(int j=0;j<7;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i][j+count];
                }
                if(checkSame(temp,3)==true){
                    if(map[i][j+3]=="X"&&j+3<9){
                        map[i][j+3]=turn[1];
                        scp(j+3,i);
                        cout<<map[i][j+3];
                        return;
                    }
                    else if(map[i][j-1]=="X"&&j-1>=0){
                        map[i][j-1]=turn[1];
                        scp(j-1,i);
                        cout<<map[i][j-1];
                        return ;
                    }
                }
            }
        }
    }
    for(int i=0;i<7;i++){//for primary diognal  bot win or prevention of player win 
        for(int j=0;j<7;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j+count];
                }
                if(checkSame(temp,3)==true){
                    if(map[i+3][j+3]=="X"&&i+3<9&&j+3<9){
                        map[i+3][j+3]=turn[1];
                        scp(j+3,i+3);
                        cout<<map[i+3][j+3];
                        return;
                    }
                    else if(map[i-1][j-1]=="X"&&i-1>=0&&j-1>=0){
                        map[i-1][j-1]=turn[1];
                        scp(j-1,i-1);
                        cout<<map[i-1][j-1];
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<7;i++){//for secondary diognal  bot win or prevention of player win 
        for(int j=3;j<9;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j-count];
                }
                if(checkSame(temp,3)==true&&i+3<9&&j-3>=0){
                    if(map[i+3][j-3]=="X"){
                        map[i+3][j-3]=turn[1];
                        scp(j-3,i+3);
                        cout<<map[i+3][j-3];
                        return;
                    }
                    else if(map[i-1][j+1]=="X"&&i-1>=0&&j+1<9){
                        map[i-1][j+1]=turn[1];
                        scp(j+1,i-1);
                        cout<<map[i-1][j+1];
                        return;
                    }
                }
            }
        }
    }
    //for 2 chars spearated by epty spot situation 
    for(int i=0;i<7;i++){//for vertical empty mid
        for(int j=0;j<9;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j];
                }
                if(emptyMid(temp)==true){
                    if(map[i+1][j]=="X"&&i+3<9){
                        map[i+1][j]=turn[1];
                        scp(j,i+1);
                        cout<<map[i+1][j];
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<9;i++){//for horixontal empty mid 
        for(int j=0;j<7;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i][j+count];
                }
                if(emptyMid(temp)==true){
                    if(map[i][j+1]=="X"&&j+3<9){
                        map[i][j+1]=turn[1];
                        scp(j+1,i);
                        cout<<map[i][j+1];
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<7;i++){//for primary diognal  empty mid
        for(int j=0;j<7;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j+count];
                }
                if(emptyMid(temp)==true){
                    if(map[i+1][j+1]=="X"&&i+3<9&&j+3<9){
                        map[i+1][j+1]=turn[1];
                        scp(j+1,i+1);
                        cout<<map[i+1][j+1];
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<7;i++){//for secondary diognal  empty mid  
        for(int j=3;j<9;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j-count];
                }
                if(emptyMid(temp)==true&&i+3<9&&j-3>=0){
                    if(map[i+1][j-1]=="X"){
                        map[i+1][j-1]=turn[1];
                        scp(j-1,i+1);
                        cout<<map[i+1][j-1];
                        return;
                    }
                }
            }
        }
    }
    //for no win situations but need to place character case
    int e=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(map[i][j]==turn[1]||(map[i][j]==turn[0]&&rand()%5==0)){
                int a,b,c,d;
                while(true&&e<50){
                    a=rand()%2;
                    b=rand()%2;
                    c=rand()%2;
                    d= rand()%2;
                    if(map[(c==0?i+a:i-a)][(d==0?j+a:j-a)]=="X"&&(c==0?i+a:i-a)<9&&(c==0?i+a:i-a)>=0&&(d==0?j+a:j-a)<9&&(d==0?j+a:j-a)>=0){
                        map[(c==0?i+a:i-a)][(d==0?j+a:j-a)]=turn[1];
                        scp((d==0?j+a:j-a),(c==0?i+a:i-a));
                        cout<<map[(c==0?i+a:i-a)][(d==0?j+a:j-a)];
                        return;
                    }
                    e++;
                }
            }
        }
    }
    //for initial pointer.placement case or no spaces around previous character case
    do{
        int a,b;
        do{
            a=rand()%9;
            b=rand()%9;
        }while(map[a][b]!="X");
        map[a][b]=turn[1];
        scp(b,a);
        cout<<turn[1];
        return;
    }while(true);
}
void botMove(string map[][15],string turn[],int &op){//same function catering for 15x15 grid 
    string temp[3]; 
    srand(time(NULL));
    //for game end move
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(map[i][j]=="X"){
                map[i][j]=turn[0];
                if(endGame(map,turn,op,0)==true){
                    map[i][j]=turn[1];
                    scp(j,i);
                    cout<<map[i][j];
                    return;
                }
                else{
                    map[i][j]="X";
                }
                map[i][j]=turn[1];
                if(endGame(map,turn,op,0)==true){
                    map[i][j]=turn[1];
                    scp(j,i);
                    cout<<map[i][j];
                    return;
                }
                else{
                    map[i][j]="X";
                }
            }
        }
    }
    //for opponent win or self win situations situations 
    for(int i=0;i<13;i++){//for vertical
        for(int j=0;j<15;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j];
                }
                if(checkSame(temp,3)==true){
                    if(map[i+3][j]=="X"&&i+3<15){
                        map[i+3][j]=turn[1];
                        scp(j,i+3);
                        cout<<map[i+3][j];
                        return;
                    }
                    else if(map[i-1][j]=="X"&&i-1>=0){
                        map[i-1][j]=turn[1];
                        scp(j,i-1);
                        cout<<map[i-1][j];
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<15;i++){//for horizontal
        for(int j=0;j<13;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i][j+count];
                }
                if(checkSame(temp,3)==true){
                    if(map[i][j+3]=="X"&&j+3<15){
                        map[i][j+3]=turn[1];
                        scp(j+3,i);
                        cout<<map[i][j+3];
                        return;
                    }
                    else if(map[i][j-1]=="X"&&j-1>=0){
                        map[i][j-1]=turn[1];
                        scp(j-1,i);
                        cout<<map[i][j-1];
                        return ;
                    }
                }
            }
        }
    }
    for(int i=0;i<13;i++){//check for primary diognal
        for(int j=0;j<13;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j+count];
                }
                if(checkSame(temp,3)==true){
                    if(map[i+3][j+3]=="X"&&i+3<15&&j+3<15){
                        map[i+3][j+3]=turn[1];
                        scp(j+3,i+3);
                        cout<<map[i+3][j+3];
                        return;
                    }
                    else if(map[i-1][j-1]=="X"&&i-1>=0&&j-1>=0){
                        map[i-1][j-1]=turn[1];
                        scp(j-1,i-1);
                        cout<<map[i-1][j-1];
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<13;i++){//check for secondary diognal
        for(int j=3;j<15;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j-count];
                }
                if(checkSame(temp,3)==true&&i+3<15&&j-3>=0){
                    if(map[i+3][j-3]=="X"){
                        map[i+3][j-3]=turn[1];
                        scp(j-3,i+3);
                        cout<<map[i+3][j-3];
                        return;
                    }
                    else if(map[i-1][j+1]=="X"&&i-1>=0&&j+1<15){
                        map[i-1][j+1]=turn[1];
                        scp(j+1,i-1);
                        cout<<map[i-1][j+1];
                        return;
                    }
                }
            }
        }
    }
    //for 2 chars spearated by epty spot situation 
    for(int i=0;i<13;i++){//for vertical empty mid
        for(int j=0;j<15;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j];
                }
                if(emptyMid(temp)==true){
                    if(map[i+1][j]=="X"&&i+3<15){
                        map[i+1][j]=turn[1];
                        scp(j,i+1);
                        cout<<map[i+1][j];
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<15;i++){//for horixontal empty mid 
        for(int j=0;j<13;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i][j+count];
                }
                if(emptyMid(temp)==true){
                    if(map[i][j+1]=="X"&&j+3<15){
                        map[i][j+1]=turn[1];
                        scp(j+1,i);
                        cout<<map[i][j+1];
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<13;i++){//for primary diognal  empty mid
        for(int j=0;j<13;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j+count];
                }
                if(emptyMid(temp)==true){
                    if(map[i+1][j+1]=="X"&&i+3<15&&j+3<15){
                        map[i+1][j+1]=turn[1];
                        scp(j+1,i+1);
                        cout<<map[i+1][j+1];
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<13;i++){//for secondary diognal  empty mid  
        for(int j=3;j<15;j++){
            if(map[i][j]==turn[0]||map[i][j]==turn[1]){
                for(int count=0;count<3;count++){
                    temp[count]=map[i+count][j-count];
                }
                if(emptyMid(temp)==true&&i+3<15&&j-3>=0){
                    if(map[i+1][j-1]=="X"){
                        map[i+1][j-1]=turn[1];
                        scp(j-1,i+1);
                        cout<<map[i+1][j-1];
                        return;
                    }
                }
            }
        }
    }
    //for no win situations 
    int e=0;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(map[i][j]==turn[1]||(map[i][j]==turn[0]&&rand()%5==0)){
                int a,b,c,d;
                while(true&&e<50){
                    a=rand()%2;
                    b=rand()%2;
                    c=rand()%2;
                    d= rand()%2;
                    if(map[(c==0?i+a:i-a)][(d==0?j+a:j-a)]=="X"&&(c==0?i+a:i-a)<15&&(c==0?i+a:i-a)>=0&&(d==0?j+a:j-a)<15&&(d==0?j+a:j-a)>=0){
                        map[(c==0?i+a:i-a)][(d==0?j+a:j-a)]=turn[1];
                        scp((d==0?j+a:j-a),(c==0?i+a:i-a));
                        cout<<map[(c==0?i+a:i-a)][(d==0?j+a:j-a)];
                        return;
                    }
                    e++;
                }
            }
        }
    }
    //for initial pointer.placement solution;
    do{
        int a,b;
        do{
            a=rand()%15;
            b=rand()%15;
        }while(map[a][b]!="X");
        map[a][b]=turn[1];
        scp(b,a);
        cout<<turn[1];
        return;
    }while(true);
}
int main(){
    cursor pointer;//initialise cursor pointer 
    string turn[2] ={"\033[32mO\033[0m","\033[31mO\033[0m"};//turns / caracters
    int n=menu(),op=0;//prompt grid menu
    char mv;//moving character
    bool botting =botMenu();//prompt bot menu
    if(n==9){//for case of 9x9 grid 
        string map[9][9];// map
        initialiseAndPrint(map);//call iniitalise functiion 
        do{
            if(botting ==true){//for botting case
                if(op==0){
                    do{
                        pointer.set(map,turn,op);//pointer actions 
                        mv=getch(); 
                        if(mv==char(27)){
                            scp(0,10);
                            cout<<"\033[31mGame escaped\033[0m";
                            return 0;
                        }
                        pointer.move(mv,n);
                    }while(mv!=char(13));
                    pointer.placement(map,pointer,turn,op);//pointer.placement 
                }
                else if(op==1){
                    botMove(map,turn,op);//bot stimulation 
                    op=(op==0?1:0);//change of character/turn 
                    pointer.reset(map);
                }
            }
            else{//on bot case
                    do{
                        pointer.set(map,turn,op);
                        mv=getch();
                        if(mv==char(27)){
                            scp(0,10);
                            cout<<"\033[31mGame escaped\033[0m";
                            return 0;
                        } 
                        pointer.move(mv,n);
                    }while(mv!=char(13));
                    pointer.placement(map,pointer,turn,op);
            }
        }while(endGame(map,turn,op)==false);//check for win case 
    }
    else if(n==15){//same as before catering for 15x15
        string map[15][15];
        initialiseAndPrint(map);
        do{
            if(botting ==true){
                if(op==0){
                    do{
                        pointer.set(map,turn,op);
                        mv=getch(); 
                        if(mv==char(27)){
                            scp(0,16);
                            cout<<"\033[31mGame escaped\033[0m";
                            return 0;
                        }
                        pointer.move(mv,n);
                    }while(mv!=char(13));
                    pointer.placement(map,pointer,turn,op);
                }
                else if(op==1){
                    botMove(map,turn,op);
                    op=(op==0?1:0);
                    pointer.reset(map);
                }
            }
            else{
                    do{
                        pointer.set(map,turn,op);
                        mv=getch(); 
                        if(mv==char(27)){
                            scp(0,16);
                            cout<<"\033[31mGame escaped\033[0m";
                            return 0;
                        }
                        pointer.move(mv,n);
                    }while(mv!=char(13));
                    pointer.placement(map,pointer,turn,op);
            }
        }while(endGame(map,turn,op)==false);
    }
    getch();             
    return 0;
}