#include <iostream>
#include <conio.h>
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <cstdlib>
#include <string>
#include <algorithm>
#include <xml_l.h>
#include <fstream>

using namespace std;
xml_l xml;
char file[10]="log.txt";

char write_elemen[200];

void decrypt(){string tmp(write_elemen);
replace(tmp.begin(),tmp.end(),'l','%');
cout<<tmp;}

/*int main(){
            ofstream W_file_ob; W_file_ob.open("log.txt",std::ios_base::app);

            string inner_text;
            cin>>inner_text;

            replace(inner_text.begin(),inner_text.end(),'`',' ');
            W_file_ob<<inner_text;

            ifstream r_file; r_file.open("log.txt");
            r_file>>inner_text;

            cout<<inner_text;
            W_file_ob.close();
            getch();

                cin>>write_elemen;
    decrypt();

    //for(int i)
    *xml.open(file);
    xml.read(in);
    //xml.write(in);
      //  xml.write.element();
  //  void lklk(){}
}*/


int main(){


    getch();
}
