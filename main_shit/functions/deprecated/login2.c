#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "umake.c"
#include "uchk.c"
#include "decipher.c"
#include "cipher.c"

int main(){
    char usrnam[200]="jessan"; int pass; char notes[200];
    
    pass=1234;
    printf("the login function is started");
    //DECLEARATIONS
    FILE *fp=fopen("ulist.spenc","rb");
    
    //
    if (fp==NULL){
        
        fclose(fp);
        if(umake(usrnam,pass)){
            printf(notes,"user created successfully");
        }
        else{
            printf(notes,"user make failed");
        }
    }
    else{
        fclose(fp);
        if(chk(usrnam,pass)){
            return 1;
            printf(notes,"lol login successful");
        }
    }
}