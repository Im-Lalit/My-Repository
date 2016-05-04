#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#ifndef XML_L_H
#define XML_L_H

using namespace std;

char file_name[10];
char read_element[200];
char write_element[200];
char reading_output[200];

class xml_l
{
    public:
        xml_l(){};
        void open(char file[10]){strcpy(file_name,file);}
        void close(char file[10]){strcpy(file_name,file);}
        void read(char read_tmp[200]){strcpy(read_element,read_tmp); encrypt(); R_element R_ob;R_ob.element();}
        void write(char write_tmp[200]){strcpy(write_element,write_tmp);W_element W_ob;W_ob.element();}

    private:
        class R_element{public:void element(){ifstream R_file_ob; R_file_ob.open(file_name);
            char tmp_element[200];
            int a=0;
            for(;;){R_file_ob>>tmp_element;
                if(strcmp(read_element,tmp_element)==0){
                    for(int i=0;i<1;i++){
                        R_file_ob>>reading_output;a=1;}
                }
            if(a==1){break;}}
        }};

        class W_element{public:void element(){ofstream W_file_ob; W_file_ob.open(file_name,std::ios_base::app);
            char inner_text[200];
            cin>>inner_text;
            W_file_ob<<"<"<<write_element<<">"<<endl;
            W_file_ob<<"\t"<<inner_text<<endl;
            W_file_ob<<"</"<<write_element<<">"<<endl;
        }};

        //void encrypt(){}
        //void decrypt(){string tmp(write_element);replace(tmp.begin(),tmp.end(),' ','%');cout<<tmp;}

    protected:
};

#endif // XML_L_H
