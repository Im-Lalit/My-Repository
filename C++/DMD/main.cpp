#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstddef>
using namespace std;

void cls(){
    system("cls");
}

int Key_code,bar,x=0,y=0;
char word[25]="##############";
int t;

void bacw_dot(){
    if(t>44){
    x--;y--;
    for(int i=0;i<1;i++)
    if(x>22){x=22;}
    if(y>77){y=77;}
    }

}

void mov_bar(){
    if(bar<0)bar=0;
    if(bar>13)bar=13;

    for(int i=0;i<bar;i++){cout<<"     ";}
    cout<<word;}

void dot(){
    for(int i=0;i<x;i++){cout<<endl;}
    for(int i=0;i<y;i++){cout<<" ";}
    cout<<"@@";
}

void forw_dot(){
    if(t<22){
    x++;y++;
    for(int i=0;i<1;i++)
    if(x>22){x=22;}
    if(y>77){y=77;}
    }
}

/*int main(){
    Key_code=getch();
    cout<<Key_code;
}*/

int main(){

    for(;;){
        if(kbhit()){Key_code=getch();}

        if(Key_code==75){
            bar--;
            Key_code=0;}

        if(Key_code==77){
            bar++;
            Key_code=0;}

        if(Key_code==27){break;}

        else{cls();mov_bar();forw_dot();bacw_dot();dot();}
    }
}
