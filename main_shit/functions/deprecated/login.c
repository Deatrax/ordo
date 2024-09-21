#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "umake.c"
#include "uchk.c"
#include<time.h>


int main(){

    //DECLEARATIONS
    FILE *fp=fopen("ulist.spenc","rb");
    char usrnam[100];
    int pass;
    //
    if (fp==NULL)
    {
        printf("\n\nNo existing user(s) found....creating new user....\n\nType Username(max 100 chars)\t    :");
        fflush(stdin);
        scanf("%s",usrnam);
        inpass:
        printf("Type password(4 digits-num only)    :");
        scanf("%d",&pass);
        int temp,cnt=0;
        temp=pass;
        while (temp)
        {
            temp/=10;
            cnt++;
        }
        if (cnt>4)
        {
            printf("Password size too big,, retry\n");
            goto inpass;
        }
        
        
        if ( umake(usrnam,pass))
        {
            printf(".....User created successfully\n Procced to login?(y/n) ->");
            decision:
            fflush(stdin);
            scanf("%c",&usrnam[0]);
            switch (usrnam[0])
            {
            case 'y':
                goto login;
                break;
            
            case 'n':
                printf("Exiting SPENC login system.....Exited");
                break;

            default:
                printf("Invalid input\n try again ->");
                goto decision;
                break;
            }
        }
        else{
            
            printf("Failed to create username, Fatal error.....\n  PLEASE CONTECT DEV\n...exiting....exited");
        }
       
    }
    else{
        login:NULL;

        printf("Welcome Back!! \n\nType Username\t    :");
        fflush(stdin);
        scanf("%s",usrnam);
        printf("Type password\t    :");
        scanf("%d",&pass);


        if (chk(usrnam,pass))
        {
            printf("login successful!!\n");
        }
        else{
            printf("Incorrect username or password!\n");
            // for (int i = 3; i>=0; i--)
            // {
            //     if (chk(usrnam,pass))
            //     {
            //         printf("\nlogin successful!!\n");
            //         break;
            //     }else{

            //         printf("Incorrect username or password! %d attempts left\n",i);
            //     }
                
            // }
            
        }
        
    }
}