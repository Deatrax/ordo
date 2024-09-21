#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INT_LINE_SIZE 1024

int main(){


    char filename[INT_LINE_SIZE];
    printf("Give the file name: ");
    fgets(filename,INT_LINE_SIZE,stdin);
    filename[strlen(filename) - 1] = '\0';

    int line=0;
    printf("line to replace: ");
    scanf("%d",&line);

    // char newline[INT_LINE_SIZE];
    // printf("Give the new line: ");
    // fflush(stdin);
    // fgets(newline,INT_LINE_SIZE,stdin);


    FILE *src=fopen(filename,"rb");
    FILE *dest=fopen("tempFILE.txt","wb");
    if (src==NULL || dest==NULL)
    {
        perror("Failed to execute");
        return -1;

    }
    
    char buff[INT_LINE_SIZE];
    for (int i = 1; !feof(src); i++)
    {      
        fgets(buff,INT_LINE_SIZE,src);
        if (i==line)
        {
            //fputs(newline,dest);
            continue;
        }
        fputs(buff,dest);
        
    }

    fclose(src);
    fclose(dest);
    remove(filename);
    rename("tempFILE.txt",filename);
    
    return 0;
}