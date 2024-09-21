

//#include "decipher.c"
//#include "cipher.c"
#include<stdio.h>

int chk(char usr[],int pass){

    FILE *fp=fopen("ulist.spenc","rb");

    fseek(fp,0,SEEK_END);
    int flen=ftell(fp)+1;
    fseek(fp,0,SEEK_SET);

    char *dat=(char*)malloc(flen*sizeof(char));
    dat[0]='\0';
    //fgets(dat,sizeof(dat),fp);
    //fread(dat,sizeof(dat),3,fp);
    char fch;
    int i=0;
    while (fscanf(fp,"%c",&fch)==1)
    {
        dat[i]=fch;
        i++;
    }
    dat[i]='\0';
    fclose(fp);
    //printf("got data: %s",dat);

     //pass=1234;
     //usr="abdullah\0";

    int a=pass%100;
    int b=pass/10;
    int n2=a^b;
    n2=n2%10;

    char cpy[strlen(dat)];
    strcpy(cpy,dat);
    char num[5];
    char *tor=strtok(dat,".");
    char stor[100]="\0";
    strcpy(stor,tor);
    tor=strtok(NULL,".");
    strcpy(num,tor);
    num[4]='\0';
    //printf("\ngot number:%s\nthe number decipher is:%d",num,n2);

    // int i=0;
     i=0;
    while (num[i]!=NULL)
    {
        num[i]=decipher(num[i],n2);
        i++;
    }
    //printf("\nnow the number is: %s",num);

    int r1=atoi(num);
//    ((atoi(num[0])*1000)+(atoi(num[1])*100)+(atoi(num[2])*10)+(atoi(num[3])));
    int temp;
    //printf("\nthe rand (r1) in int is: %d\n",r1);

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

    free(dat);
    const int ini_size=10;
    int size=0;
    char *abcd=(char*)malloc(ini_size*sizeof(char));
    char cpy2[strlen(usr)+1];
    strcpy(cpy2,usr);
    i=0;
    while (cpy2[i]!=NULL)
    {   
        //printf("ciphering char: %c\n",cpy2[i]);
        cpy2[i]=cipher(cpy2[i],n4);
        i++;
    }
    //printf("the ciphered uname is: %s",cpy2);

    if (!strcmp(stor,cpy2))
    {
        //printf("====ALHAMDULLILAH THIS FINALLY WORKED====");
        return 2;
    }
    else{
        //printf("====Fucking die====\ninshaAllah it'll work...");
        return 0;
    }
    
}