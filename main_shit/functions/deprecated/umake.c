#include "cipher.c"
#include<time.h>
#include<stdio.h>

int  umake( char usr[],  int pass){

    FILE *fp1=fopen("ulist.spenc","wb");
    if (fp1==NULL)
    {
        perror("The file open failed");
        return 0;
    }
    
    //usr="abdullah\0";
    //pass=1234;
    srand(time(NULL));
    int r1=rand();
    r1=r1%10;
    int temp;
    for (int i = 0; i < 3; i++)
    {
        temp=rand();
        temp=temp%10;
        r1=(r1*10)+temp;
    }
    //r1=6089;

    printf("the random number is: %d\n",r1);
    

    int n1=pass^r1;
    temp=n1;
    int n1_sum=0;
    while (temp)
    {
        n1_sum=temp%10;
        temp/=10;
    }
    int n3=n1_sum;
    int n4=n3%26;

   
    const int ini_size=10;
    int size=0;
    char *abcd=(char*)malloc(ini_size*sizeof(char));
    char cpy[strlen(usr)+1];
    strcpy(cpy,usr);
    int i=0;
    while (cpy[i]!=NULL)
    {   
        printf("ciphering char: %c\n",cpy[i]);
        cpy[i]=cipher(cpy[i],n4);
        i++;
    }

    int a=pass%100;
    int b=pass/10;
    int n2=a^b;
    n2=n2%10;

    printf("the ciphered uname is :%s\nthe rand cipher key is: %d\n",cpy,n2);
    char num[10];
    sprintf(num,"%d\0",r1);
    i=0;
    while (num[i]!=NULL)
    {
        num[i]=cipher(num[i],n2);
        i++;
    }
    
    char out[200]="\0";
    strcat(out,cpy);
    strcat(out,".");
    strcat(out,num);

    printf("the final thing is: %s",out);
    fprintf(fp1,"%s",out);
    free(abcd);
    fclose(fp1);
    return 1;

}