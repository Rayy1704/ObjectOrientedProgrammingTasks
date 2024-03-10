#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

void scp(int x, int y){//function to set cursor to the position entered
    x+=2;//increment x and y co-ordinates for racing track
    y+=2;
    cout << "\033[" << y << ";" << x << "H";//go to coordinates
}
struct car{//user defined struct car
    int prevX=0;//previous value
    int prevY=0;
    int xPos=0;//current value
    int yPos=0;
    int points=0;
    bool win = false;//win status
    struct track{//user defined struct track
        int length=100;
    }racingTrack;//racing track variable
}car1,car2;//its variables

void makeTrack(string area[][4]){//function that forms the track
    cout<<"+";//objects to make racing track
    for(int a=0;a<car1.racingTrack.length;a++){
        cout<<"-";
    }
    cout<<"+\n";
    for(int i=0;i<4;i++){
        cout<<"|";
        for(int j=0;j<car1.racingTrack.length;j++){//gives random values to area e.g red bar,green bar,points or space 
            area[j][i]=((j==rand()%99||j==rand()%99||j==rand()%99)?"\033[33m^\033[0m":((j==rand()%99||j==rand()%198)&&j<car1.racingTrack.length-20&&j>5?"\033[31m|\033[0m":((j==rand()%99||j==rand()%5000)&&j<car1.racingTrack.length-20&&j>5?"\033[32m|\033[0m":" ")));
            cout<<area[j][i];//output the area of track
        }
        cout<<"|\n";
    }
    cout<<"+";
    for(int a=0;a<car1.racingTrack.length;a++){
        cout<<"-";
    }
    cout<<"+\n";
    scp(car1.xPos,car1.yPos);//put cars on track
    cout<<"1";
    scp(car2.xPos,car2.yPos);
    cout<<"2";
}
void movement(car &car1,car &car2,char &c,string area[][4]){//function to control movement 
    car1.xPos++;//move forward
    car2.xPos++;
    if(c==char(224)){//if alpha is read
        c=getch();//get second character (that comes along with alpha on input of arrow keys )
        if(c=='M'&&car1.xPos!=car1.racingTrack.length-1){//appropriate handlng
        }
        else if(c=='K'&&car1.xPos!=0){
            car1.xPos--;
        }
        else if(c=='H'&& car1.yPos!=0){
            car1.yPos--;
        }
        else if(c=='P'&& car1.yPos!=3){
            car1.yPos++;
        }
    }
    if(car1.xPos==car2.xPos&&car1.yPos==car2.yPos||area[car1.xPos][car1.yPos]=="\033[31m|\033[0m"){//in case of collission wit car or red bar sdont let it move 
        car1.xPos=car1.prevX;
        car1.yPos=car1.prevY;
        
    }
    if(area[car1.xPos][car1.yPos]=="\033[32m|\033[0m"){//incase of collision with green bar :give boost and points
        car1.points+=5;
        while(true){
            int inc=rand()%10+6;
            if(area[car1.xPos+inc][car1.yPos]!="\033[31m|\033[0m"){
                car1.xPos+=inc;
                break;
            }
        }
    }
    if(area[car1.xPos][car1.yPos]=="\033[33m^\033[0m"){//collecting points gives points!
        area[car1.xPos][car1.yPos]=" ";
       car1.points+=3;
    }
    
    if(c!=char(224)){//movement struicture for car 2
        if(c=='d'&&car2.xPos!=car1.racingTrack.length-1){//appropriate handling 
        }
        else if(c=='a'&&car2.xPos!=0){
            car2.xPos--;
        }
        else if(c=='w'&& car2.yPos!=0){
            car2.yPos--;
        }
        else if(c=='s'&& car2.yPos!=3){
            car2.yPos++;
        }
    }
    if(car1.xPos==car2.xPos&&car1.yPos==car2.yPos||area[car2.xPos][car2.yPos]=="\033[31m|\033[0m"){//repeating collision process
        car2.xPos=car2.prevX;
        car2.yPos=car2.prevY;
    }
    if(area[car2.xPos][car2.yPos]=="\033[32m|\033[0m"){
        car2.points+=5;
        while(true){
            int inc=rand()%10+6;
            if(area[car2.xPos+inc][car2.yPos]!="\033[31m|\033[0m"){
                car2.xPos+=inc;
                break;
            }
        }
    }
    if(area[car2.xPos][car2.yPos]=="\033[33m^\033[0m"){
        area[car2.xPos][car2.yPos]=" ";
        car2.points+=3;
    }
    scp(car1.prevX,car1.prevY);//print both cars
    cout<<" ";
    scp(car1.xPos,car1.yPos);
    cout<<"1";
    scp(car2.prevX,car2.prevY);
    cout<<" ";
    scp(car2.xPos,car2.yPos);
    cout<<"2";
    scp(car1.racingTrack.length+1,4);
    c='d';//set c to garbage value to void repitition of movement 
}
void setCords(car &car1,car &car2){//sets ncurrent cords to old cords for appropriate handling 
    car1.prevX=car1.xPos;
    car1.prevY=car1.yPos;
    car2.prevX=car2.xPos;
    car2.prevY=car2.yPos;
}
void scoreBoard(car &car1,car &car2){//score board display on site of race track
    scp(car1.racingTrack.length+1,0);//go to pont 
    cout<<"Points for Car 1 : "<<car1.points;//print points  
    scp(car1.racingTrack.length+1,3);
    cout<<"Points for Car 2 : "<<car2.points;
}
bool getGameStatus(car &car1,car &car2){//checks if anyone has one the race
    if(car1.xPos<car1.racingTrack.length-1&&car2.xPos<car1.racingTrack.length-1){//incase if game hasnt finished 
        return true;//continue
    }
    else{//in other case check who finished the game first and award points 
        if(car1.xPos==car1.racingTrack.length-1){// for car 1
            car1.points+=2;//increment points 
        }
        else if(car2.xPos==car1.racingTrack.length-1){// for car 2
            car2.points+=2;
        }
        return false;//false:: game has ended 
    }
}
void endGameOutput(car &car1,car &car2,bool gameStatus){//output forend of game
    scoreBoard(car1,car2);//update score bpoard 
    if(car1.points>car2.points){//award win depending on points 
        car1.win=true;
    }
    else{
        car2.win=true;
    }
    scp(-1,6);//go to point 
    if(!gameStatus){//print in case of win or escape presses 
        cout<<"\033[32mCongrats On winning "<<(car1.win==true?"Car 1":"Car 2")<<" !!\033[0m\n\n";
    }
    else{
        cout<<"\033[31mGame Escaped\033[0m\n\n";
        Sleep(2000);
    }
    
}
int menu(){
    string menu[4]={"\n\033[32m->\033[0mStart New 2 Player game :: The adventure awaits!\nStart New Game With Bot\nHelp\nQuit","\nStart New Game 2 Player game\n\033[32m->\033[0mStart New Game With Bot :: Try not to loose!\nHelp\nQuit","\nStart New Game 2 Player game\nStart New Game With Bot\n\033[32m->\033[0mHelp :: Check out the instructions first!\nQuit","\nStart New Game 2 Player game\nStart New Game With Bot\nHelp\n\033[32m->\033[0mQuit :: Why do you wanna leave?"};
    int i=0;
    char m;
    do{cout<<"-----Choose Your Option-----          (Use Arrow keys To Browse::Press Enter To Select)";
        cout<<menu[i];
        m=getch();
        if(m==char(224)){
            m=getch();
            if(m=='H'&&i!=0){
                i--;
            }
            else if (m=='P'&&i!=3){
                i++;
            }
        }
        system("cls");
    }while(m!=char(13));
    return i;
}
void displayHelp(){//function to print help/tip when it is seleected i menn
    cout<<"Green Bar(\033[32m|\033[0m) : Award 5 Points and give You a random boost on collision\n";
    cout<<"Red Bar(\033[31m|\033[0m)   : Make you stick to them on collision , slowing you down !!\n";
    cout<<"Points (\033[33m^\033[0m)   : Award 3 points on collection\n\n";
    cout<<"Control car '2' with WASD keys\n";
    cout<<"Control car '1' with Arrow keys\n";
    cout<<"Press esc mid-game to end it\n";
    cout<<"Make sure console is re-sized to contain the track and the score board without errors\n";
    cout<<"Game automatically makes the car drive forward,GoodLuck!!\n\n";
    system("pause");
}
void initialiseCars(car &car1,car &car2){//function to initialise everything to default values 
    car1.win=false;
    car2.win=false;
    car1.points=0;
    car2.points=0;//ik i could have made one function and ran i twice but idk why i did this 
    car1.prevX=0;
    car1.prevY=0;
    car1.yPos=0;
    car1.xPos=0;
    car2.prevX=0;
    car2.prevY=3;
    car2.xPos=0;
    car2.yPos=3;
}
void botAndMovement(car &car1,car &car2,char &c,string area[][4]){//function to control movement 
    car1.xPos++;//move forward
    car2.xPos++;
    
    if(c==char(224)){//if alpha is read
        c=getch();//get second character (that comes along with alpha on input of arrow keys )
        if(c=='M'&&car1.xPos!=car1.racingTrack.length-1){//appropriate handlng
        }
        else if(c=='K'&&car1.xPos!=0){
            car1.xPos--;
        }
        else if(c=='H'&& car1.yPos!=0){
            car1.yPos--;
        }
        else if(c=='P'&& car1.yPos!=3){
            car1.yPos++;
        }
    }
    if(car1.xPos==car2.xPos&&car1.yPos==car2.yPos||area[car1.xPos][car1.yPos]=="\033[31m|\033[0m"){//in case of collission wit car or red bar sdont let it move 
        car1.xPos=car1.prevX;
        car1.yPos=car1.prevY;
        
    }
    if(area[car1.xPos][car1.yPos]=="\033[32m|\033[0m"){//incase of collision with green bar :give boost and points
        car1.points+=5;
        while(true){
            int inc=rand()%10+6;
            if(area[car1.xPos+inc][car1.yPos]!="\033[31m|\033[0m"){
                car1.xPos+=inc;
                break;
            }
        }
    }
    if(area[car1.xPos][car1.yPos]=="\033[33m^\033[0m"){//collecting points gives points!
       car1.points+=3;
       area[car1.xPos][car1.yPos]=" ";
    }
    int minJp=car1.racingTrack.length-1,minIp=3;//distance btw point and and car 2
    for(int i=0;i<4;i++){
        for(int j=car2.xPos;j<car1.racingTrack.length;j++){
            if(area[j][i]=="\033[33m^\033[0m"){
                if(j<minJp){
                    minJp=j;//find min distance
                    minIp=i;
                }
            }
        }
    }
    int minJGB=car1.racingTrack.length-1,minIGB=3;//distance btw point and green bar
    for(int i=0;i<4;i++){
        for(int j=car2.xPos;j<car1.racingTrack.length;j++){
            if(area[j][i]=="\033[32m|\033[0m"){
                if(j<minJGB){
                    minJGB=j;//find minimum distance
                    minIGB=i;
                }
            }
        }
    }
    if(minJGB<minJp && rand()%10==0){//reduce chnaces of going after bar
        if(car2.yPos>minIGB){//code to go after bar
            car2.yPos--;
        }
        else if(car2.yPos<minIGB){
            car2.yPos++;
        }
    }
    else if(minJGB>=minJp&& rand()%4==0){//chances of going after pointn
        if(car2.yPos>minIp){//code to go after point
            car2.yPos--;
        }
        else if(car2.yPos<minIp){
            car2.yPos++;
        }
    }
    if(area[car2.xPos][car2.yPos]=="\033[31m|\033[0m"){//condition to avoid red bar 
        if((area[car2.xPos][car2.yPos+1]=="\033[33m^\033[0m"||area[car2.xPos][car2.yPos+1]=="\033[32m|\033[0m"||area[car2.xPos][car2.yPos+1]==" ")&&car2.yPos<3){//if the spots below are clear
            car2.yPos++;//avoid red bar
        }
        else if((area[car2.xPos][car2.yPos-1]=="\033[33m^\033[0m"||area[car2.xPos][car2.yPos-1]=="\033[32m|\033[0m"||area[car2.xPos][car2.yPos-1]==" ")&&car2.yPos>0){//if the spots above are clear
            car2.yPos--;
        }
    }

    if(area[car2.xPos][car2.yPos]=="\033[32m|\033[0m"){//green bar collision with car 2
        car2.points+=5;
        while(true){
            int inc=rand()%10+6;
            if(area[car2.xPos+inc][car2.yPos]!="\033[31m|\033[0m"){
                car2.xPos+=inc;
                break;
            }
        }
    }
    if(area[car2.xPos][car2.yPos]=="\033[33m^\033[0m"){//collision with point 
        area[car2.xPos][car2.yPos]=" ";
        car2.points+=3;
    }
    scp(car1.prevX,car1.prevY);//print both cars
    cout<<" ";
    scp(car1.xPos,car1.yPos);
    cout<<"1";
    scp(car2.prevX,car2.prevY);
    cout<<" ";
    scp(car2.xPos,car2.yPos);
    cout<<"2";
    scp(car1.racingTrack.length+1,4);
    c='d';//set c to garbage value to void repitition of movement 
}
int main(){
    srand(time(NULL));//set rand function to seed
    string area[car1.racingTrack.length][4];//array for area 
    while(true){
        system("cls");//clear screen
        int i=menu();
        restart:
        switch(i){
            case 0://start new game 
            case 1:
                system("cls");
                bool escape;
                escape=false;
                initialiseCars(car1,car2);
                char c;//char for movement button 
                bool gameStatus;//variale to store game status 
                makeTrack(area);//output track 
                do{//do while loop to keep game running until esc is pressed
                    scoreBoard(car1,car2);//update score board 
                    setCords(car1,car2);//call set cord function 
                    if(kbhit()){//take input only if keyboard is hit 
                        c= getch();//getch is used to avoid pressing enter 
                        escape=(c==char(27)?true:false);
                    }
                    if(i==0)
                        movement(car1,car2,c,area);//call movement function 
                    else if(i==1)
                        botAndMovement(car1,car2,c,area);
                    Sleep(70);//give delay for appropriate speed
                    gameStatus=getGameStatus(car1,car2);//get game status 
                }while(!escape&&gameStatus);//exit game in certain conditions 
                endGameOutput(car1,car2,gameStatus);//show end game output;
                if(!escape){
                    cout<<"\nRestarting in :  ";
                    for(int i=3;i>0;i--){
                        cout<<"\b";
                        cout<<i;
                        Sleep(1000);
                    }
                        goto restart;
                }
                break;
            case 2:
                displayHelp();//display help
                break;
            case 3:
                cout<<"\033[32mCreated by 2023601 : Rayyan Hassan Salman\033[0m";
                Sleep(3000);
                return 0;//end program
                break;
        }
    }
    return 0;
}