#include<stdio.h>
#include "everything.c"

int main(){

    // char dat[30][4][512];
    routine thing[30];
    int ret=getRoutine(thing);

    for (int i = 0; i < 30; i++)
    {
        printf("class %d: %s duration:%d teacher:%s room:%s \n",i+1,thing[i].name,thing[i].dura,thing[i].teacher,thing[i].room);
    }
    

}
