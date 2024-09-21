#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "everything.c"
// int test(char *usr,int num){

//     //system("CLEAR");
//     printf("i got the parameters: %s and %d from main.cpp",usr,num);
    
//     return 0;
//}

int main(){

    //============GET USER DIRECTORY========>>
    char udir[512];
    get_usr_env(udir);
    std::string def_dir(udir);
    //def_dir=udir;
    std::cout<<"got the directory: "<<def_dir<<std::endl;
    //QString qdef_dir = QString::fromStdString(def_dir);
    //ui->home_dir->setText(qdef_dir);
}

