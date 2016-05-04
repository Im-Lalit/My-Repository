#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
#include <xml_read.h>
using namespace std;

//log file read file name here
char log_file[20]="log.txt";
char system_input[20];
char user_input[20];


//clear screen not found in code::block, use cls(); function
void cls(){
    system("cls");
};

void get_input(){
    int a;
    //a=getch();
    //user_input=a;
    /*string input();
    replace(input.begin(),input.end(),'_',' ');
    cout<<input;*/
}

//header function use for headings
codb
    cls();
    for(int i=0;i<24;i++){
        cout<<"=";
    }

    cout<<endl<<"\t"<<head<<endl;

    for(int i=0;i<24;i++){
        cout<<"=";
    }
    cout<<endl;
}

//add variable function
void write_input_file(){
    //heading
    header("Add New");

    //in_element use for read node from XML, in_inner_txt use for read node text in XML
    char in_element[200],in_inner_txt[200];

    //reading user input
    cout<<"Enter element..."<<endl;
    cin>>in_element;
    cout<<"Enter Text..."<<endl;
    cin>>in_inner_txt;

    //create file object by using ofstream
    ofstream IO_file;

    //open file by use of object.open()
    IO_file.open(log_file,std::ios_base::app);

    //transfer all user input in file
    IO_file<<"<"<<in_element<<">"<<endl;
    IO_file<<"\t"<<in_inner_txt<<endl;
    IO_file<<"</"<<in_element<<">"<<endl;

    //close file by use of
    IO_file.close();
    }

//read variable from file
void read_input_file(){
    //Heading
    header("Enter input");
    char file_input[30]; //*user_input use for getting input from user, *file_input use for getting input from file
    ifstream IO_file; //create object for opening file using by ifstream

    IO_file.open(log_file); //open file

    for(;;){
        IO_file>>file_input;

        if(strcmp(user_input,file_input)==0){ //filter if using char variable for input use *stcmp
            for(int i=0;i<1;i++)
            IO_file>>file_input;
            string tmp(file_input);
            replace(tmp.begin(),tmp.end(),'_','-');
            cout<<endl<<tmp;
        }
    }

    // close object file
    IO_file.close();
}

//start program
void start_program(){
   // system("start cmd")
}

//main function
int main(){

    xml_read lalit;
    lalit.file_read();

    //get_input();
    //getch();
    //string s("a b c");
    header("Shortcuts");
    //getting user input for processing

    //replace(s.begin(),s.end(),' ','_');
    //if(strcmp("add",user_input)==0){
    //cin>>user_input;
       // read_input_file();
    //};
//cout<<s;
    //write_input_file();
    getch();
}
