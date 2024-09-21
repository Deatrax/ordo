#include "mainwindow.h"
//#include "primary_window.h"
#include "first_run.h"
#include <QApplication>
//#include <stdio.h>
//#include <stdlib.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // FILE *ucfg=fopen("uconfig.spenc","wb");
    // if(ucfg==NULL){

    //     first_run frun;
    //     frun.show();
    // }
    // else{

    //     MainWindow w;
    //     w.show();

    // }

    MainWindow w;
    //w.show();

    // primary_window w2;
    // w2.show();
    char dir[260];
    getAppData_folder(dir);
    char file[260]="dummy.txt";
    make_appData_filePath(file);

    if (ensure_directory_and_open_file(dir, file, "w") == 0) {
        printf("File opened successfully.\n");
    } else {
        printf("Failed to open file.\n");
        return -1;
    }
    return a.exec();


}
