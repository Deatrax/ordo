#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Routine
{
    char name[50];
    int dura;
    char teacher[50];
    char room[50];

}routine;

static int getRoutine(/*char (*str)[4][512]*/ routine *obj);

int main(){

    // char dat[30][4][512];
    routine thing[30];
    int ret=getRoutine(thing);

    for (int i = 0; i < 30; i++)
    {
        printf("class %d: %s duration:%d teacher:%s room:%s \n",i+1,thing[i].name,thing[i].dura,thing[i].teacher,thing[i].room);
    }
    

}

static int getRoutine(/*char (*str)[4][512]*/ routine *obj){

    FILE *fp=fopen("routine.md","rb");
    char read[1024];
    char dat[30][4][512];

    for (int i = 0; i < 30; i++)
    {
        fgets(read,1024,fp);
        read[strlen(read)-1]='\0';
        char *tok=strtok(read,"|");
        for (int j = 0; j < 4; j++)
        {
            char out[100];
            strcpy(out,tok);
            sprintf(dat[i][j],"\0");
            strcat(dat[i][j],tok);
            tok=strtok(NULL,"|");
        }
        strcpy(obj[i].name,dat[i][0]);
        obj[i].dura=atoi(dat[i][1]);
        strcpy(obj[i].teacher,dat[i][2]);
        strcpy(obj[i].room,dat[i][3]);        
    }

    fclose(fp);

    // for (int i = 0; i < 30; i++)
    // {   
    //     printf("New class: ");
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf(" %s",dat[i][j]);
    //     }
    //     printf("\n");
    // }

    return 1;
}