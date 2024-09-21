#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>


//DEFINITIONS--------->
// int  umake( char usr[],  int pass);
// char decipher(char str,int k);
// char cipher(char str,int k);
// int chk(char usr[],int pass);
//-------------------->
#define INI_SIZEs 512
#define INT_LINE_SIZE 1024


typedef struct Routine
{
    char name[50];
    int dura;
    char teacher[50];
    char room[50];

}routine;

static char decipher(char str,int k){

    char ch;

   

    ch = str;
    // Check for valid characters.
    if (isalnum(ch)) {

        //Lowercase characters.
        if (islower(ch)) {
            ch = (ch - 'a' - k) % 26 + 'a';
        }
        // Uppercase characters.
        if (isupper(ch)) {
            ch = (ch - 'A' - k) % 26 + 'A';
        }

        // Numbers.
        if (isdigit(ch)) {
            int ach = (ch - '0' - k);
            if (ach<0)
            {
                ach+=10;
            }
            ch=ach%10+'0';
            
        }
    }
    // Invalid character.
    else {
        ch=ch;
    }

    // Adding encoded answer.
    return ch;



    
}

static char cipher(char str,int k){

    char ch;

   

    ch = str;
    // Check for valid characters.
    if (isalnum(ch)) {

        //Lowercase characters.
        if (islower(ch)) {
            ch = (ch - 'a' + k) % 26 + 'a';
        }
        // Uppercase characters.
        if (isupper(ch)) {
            ch = (ch - 'A' + k) % 26 + 'A';
        }

        // Numbers.
        if (isdigit(ch)) {
            ch = (ch - '0' + k) % 10 + '0';
        }
    }
    // Invalid character.
    else {
        ch=ch;
    }

    // Adding encoded answer.
    return ch;



    
}

static int chk(char usr[],int pass){

    if (pass==1000 || pass==0)
    {
        return 0;
    }
    
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
    printf("func.out:%s: got data: %s",__func__,dat);

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
    printf("\ngot number:%s\nthe number decipher is:%d",num,n2);

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
    printf("the ciphered uname is: %s",cpy2);

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

static int  umake( char usr[],  int pass){

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

static void get_usr_env(char *str){

    // str=(char*)malloc(sizeof(INI_SIZEs));
    sprintf(str,"%s\\Documents\\SIMS-Academic\\", getenv("USERPROFILE"));
}

static int write_uconfig(int tmplFlag, char *tmplPath, char *homeDIR, char *dname){

    FILE *fp=fopen("uconfig.spenc","wb");
    if (fp==NULL)
    {
        return 0;
    }
    
    fprintf(fp,"%s\n%s\n",dname,homeDIR);
    //fputs(homeDIR,fp);
    if (tmplFlag)
    {
        fputs(tmplPath,fp);
    }
    fclose(fp);
    return 1;
}

static int chk_path(const char str[]){

    int cnt=0;
    
    //printf("\nstage 1\n");
    for (int i = 0; str[i]!=NULL; i++)
    {
        if (str[i]=='/')
        {
            cnt++;
        }
        
    }

    return cnt;

}

static int fcipher(char str[],char str3[], int k){

    char ch;

    for (int i = 0; str[i] != '\0'; ++i) {

    ch = str[i];
    // Check for valid characters.
    if (isalnum(ch)) {

        //Lowercase characters.
        if (islower(ch)) {
            ch = (ch - 'a' + k) % 26 + 'a';
        }
        // Uppercase characters.
        if (isupper(ch)) {
            ch = (ch - 'A' + k) % 26 + 'A';
        }

        // Numbers.
        if (isdigit(ch)) {
            ch = (ch - '0' + k) % 10 + '0';
        }
    }
    // Invalid character.
    else {
        ch=ch;
    }

    // Adding encoded answer.
    str3[i] = ch;



    }
}

static int path_pros(char str2[],const char str[],int a,int b){

    printf("\nfile processor started\n");
    printf("passed variables:\nstr2=%s\nstr=%s\nint a=%d\nintb b=%d\n",str2,str,a,b);
    char data[a+1][1000];
    char str3[1000];
    char str1[2000];
    strcpy(str1,str);
    printf("\nsafety string copy complete. contents:%s\n",str1);
    char *tok=strtok(str1,"/");
    for (int i = 1; i <=a; i++)
    {
        sprintf(data[i],"\0");
        strcat(data[i],tok);
        tok=strtok(NULL,"/");
        printf("strtok pass  data[%d]=%s\n",i,data[i]);
        
    }

    printf("\nciphering file name\n");
    fcipher(data[a],str3,b);
    // str2=NULL;

    printf("\nmaking file name\n");
    char sli={'/'};
    const char *er=&sli;
    strcpy(str2,data[0]);
    for (int i = 1; i <a; i++)
    {
        strcat(str2,"/");
        strcat(str2,data[i]);
    }
    strcat(str2,er);
    strcat(str2,str3);
    strcat(str2,"\0");
    printf("\nfile name made successfully,, file:=%s\n",str2);
    
    return 1;
}
       
static int lock(){

    char targ[1000];
    char dest[1000];

    printf("Give file name: ");
    //scanf("%s",targ);
    fflush(stdin);
    //fgets(targ,1000,stdin);
    scanf("%s",targ);

    int pass;
    printf("Enter pass (max 4 n digits)= ");
    scanf("%d",&pass);
    
    printf("Confirm lock on \"%s\" file =",targ);
    char in;
    fflush(stdin);
    scanf("%c",&in);

    if (in=='y')
    {
        goto start;
    }
    else{

        printf("////OPERATION ABORTED\\\\\\\\");
        return 0;
    }

    start:
    char fl_nam[1000]={"\0"};
    int a=chk_path(targ);
    int b=pass%10;
    if(a){
        printf("\nstarting file processor\n");
        //strcpy(targ,path_pros(targ));
        path_pros(fl_nam,targ,a,b);
        printf("PATH parse complete,, locking  \"%s\"  as \"%s\"",targ,fl_nam);

    }
    else{
        
        fcipher(targ,fl_nam,b);
        //strcpy(fl_nam,targ);
    }
    
    
    
    FILE *fp=fopen(targ,"rb");
    if (fp==NULL)
    {
        perror("Failed to open source file");
        return 0;
    }
    
    
    fseek(fp,0,SEEK_END);
    int siz=ftell(fp)+1;
    fseek(fp,0,SEEK_SET);

    char *file_dat;
    file_dat=(char*)malloc(siz*sizeof(char));

    fread(file_dat,sizeof(char),siz,fp);

   
    pass=pass^6969;

    for (int i = 0; i < siz; i++)
    {
        file_dat[i]^=pass;
    }


    strcpy(dest,fl_nam);
    strcat(dest,".mfl");
    printf("\ninally opening file: \"%s\"",dest);
    FILE *fp2=fopen(dest,"wb");
    if (fp2==NULL)
    {
        perror("Failed to open target file");
        return 0;
    }
    fwrite(file_dat,sizeof(char),siz,fp2);
    
    printf("\n===OPERATION COMPLETED SUCCESSFULLY=== \n");
    remove(targ);
    fclose(fp);
    fclose(fp2);

    return 0;
}

static int aecipher(char str[],char str3[], int k){

    char ch;

    for (int i = 0; str[i] != '\0'; ++i) {

        if ((str[i]>122 || str[i]<65))
        {   
            str3[i]=str[i];
            continue;
        }
        else if (str[i]=='\0')
        {
            str3[i]=str[i];
            return 1;
        }
        
        
        ch = str[i];
        // Check for valid characters.
        if (isalnum(ch)) {

            //Lowercase characters.
            if (islower(ch)) {
                ch = (ch - 'a' - k) % 26 + 'a';
            }
            // Uppercase characters.
            if (isupper(ch)) {
                ch = (ch - 'A' - k) % 26 + 'A';
            }

            // Numbers.
            if (isdigit(ch)) {
                ch = (ch - '0' - k) % 10 + '0';
            }
        }
        // Invalid character.
        else {
            ch=ch;
        }

        // Adding encoded answer.
        str3[i] = ch;



    }
}

static int fdecipher(char str[],int k){

    char ch;

    for (int i = 0; str[i] != '\0'; ++i) {

    ch = str[i];
    // Check for valid characters.
    if (isalnum(ch)) {

        //Lowercase characters.
        if (islower(ch)) {
            ch = (ch - 'a' - k) % 26 + 'a';
        }
        // Uppercase characters.
        if (isupper(ch)) {
            ch = (ch - 'A' - k) % 26 + 'A';
        }

        // Numbers.
        if (isdigit(ch)) {
            ch = (ch - '0' - k) % 10 + '0';
        }
    }
    // Invalid character.
    else {
        
        ch=ch;
    }

    // Adding encoded answer.
    str[i] = ch;



    }
    
}

static int path_pros2(char str2[],const char str[],int a,int b){

    printf("\nfile processor started\n");
    printf("passed variables:\nstr2=%s\nstr=%s\nint a=%d\nint b=%d\n",str2,str,a,b);
    char data[a+1][1000];
    char str3[1000];
    char str1[2000];
    strcpy(str1,str);
    printf("\nsafety string copy complete. contents:%s\n",str1);
    char *tok=strtok(str1,"/");
    for (int i = 1; i <=a; i++)
    {
        sprintf(data[i],"\0");
        strcat(data[i],tok);
        tok=strtok(NULL,"/");
        printf("strtok pass  data[%d]=%s\n",i,data[i]);
        
    }

    printf("\ndeciphering file name\n");
    //decipher(data[a],str3,b);
    fdecipher(data[a],b);
    // str2=NULL;

    printf("\nmaking file name\n");
    memset(str2,0,strlen(str2));
    char sli={'/'};
    const char *er=&sli;
    strcpy(str2,data[0]);
    for (int i = 1; i <a; i++)
    {
        strcat(str2,"/");
        strcat(str2,data[i]);
    }
    strcat(str2,er);
    strcat(str2,data[a]);
    strcat(str2,"\0");
    printf("\nfile name made successfully,, file:=%s\n",str2);
    
    return 1;
}

static int ulock(){

    char targ[1000]={"\0"};
    char dest[1000]={"\0"};

    printf("Enter folder name= ");
    scanf("%s",targ);
    char stor[1000]={"\0"};
    strcpy(stor,targ);

    int pass;
    printf("Enter pass (max 4 digits)= ");
    scanf("%d",&pass);
    
    char *tok=strtok(stor,".");
    strcat(dest,tok);
    while(1)
    {   
        tok=strtok(NULL,".");
        if (strcmp(tok,"mfl")!=0)
        {   
            strcat(dest,".");
            strcat(dest,tok);
        }
        else{
            strcat(dest,"\0");
            break;
        }
       
    }
    printf("custom extension removed=%s\n",dest);


    char fl_nam[1000];
    int a=chk_path(dest);
    int b=pass%10;
    if(a){
        printf("\nstarting file processor\n");
        //strcpy(targ,path_pros2(targ));
        path_pros2(fl_nam,dest,a,b);
        printf("PATH parse complete,, unlocking  \"%s\"  as \"%s\"",targ,fl_nam);
        strcpy(dest,fl_nam);
    }
    else{
        
        //decipher(dest,fl_nam,b);
        fdecipher(dest,b);
        //strcpy(fl_nam,stor);
    }

    
    pass=pass^6969;
    
    //strcpy(dest,fl_nam);
    printf("\nsource:%s     destination:%s  ",targ,dest);
    
    FILE *fp=fopen(targ,"rb");
    FILE *fp2=fopen(dest,"wb");

    if (fp==NULL )
    {
        perror("Error opening source file");
        
    }else if (fp2==NULL)
    {
        perror("Error opening destiation file");
    }
    else{

        
        fseek(fp,0,SEEK_END);
        int siz=ftell(fp)+1;
        fseek(fp,0,SEEK_SET);

        char *file_dat;
        file_dat=(char*)malloc(siz*sizeof(char));

        fread(file_dat,sizeof(char),siz,fp);

        for (int i = 0; i < siz; i++)
        {
            file_dat[i]^=pass;
        }

        
        fwrite(file_dat,sizeof(char),siz,fp2);

        remove(targ);
        fclose(fp);
        fclose(fp2);

    }

    return 0;
}


static int get_number_of_lines(const char *filename) {
  // Open the file in read mode
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    // Error handling: couldn't open the file
    return -1; // Or handle the error differently (e.g., print message)
  }

  int line_count = 0;
  char buffer[1024]; // Adjust buffer size as needed

  // Read lines using fgets until EOF or error
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    line_count++;
  }

  // Check for errors during read
  if (ferror(fp)) {
    // Handle error (e.g., print message)
    line_count = -1;
  }

  // Close the file
  fclose(fp);

  // Return the line count
  return line_count;
}
static int read_course(char (*dest)[256],int nums){

    //int n=get_number_of_lines("coursedat.spenc");
    FILE *fp=fopen("coursedat.spenc","r");

    for (int i = 1; i<nums; i++)
    {      
        fgets(dest[i],255,fp);
        printf("GOT THE COURSE: %s",dest[i]);
    }


    
}


// static int getRoutine(char (*str)[4][512]){

//     FILE *fp=fopen("routine.md","rb");
//     char read[1024];
//     char buf[4][512];

//     for (int i = 0; i < 30; i++)
//     {
//         fgets(read,1024,fp);
//         read[strlen(read)-1]='\0';
//         char *tok=strtok(read,"|");
//         for (int j = 0; j < 4; j++)
//         {
//             char out[100];
//             strcpy(out,tok);
//             sprintf(str[i][j],"\0");
//             strcat(str[i][j],tok);
//             tok=strtok(NULL,"|");
//         }
        
//     }

//     // for (int i = 0; i < 30; i++)
//     // {   
//     //     printf("New class: ");
//     //     for (int j = 0; j < 4; j++)
//     //     {
//     //         printf(" %s",str[i][j]);
//     //     }
//     //     printf("\n");
//     // }
//     fclose(fp);

//     return 1;
// }


static int getRoutine( routine *obj){

    FILE *fp=fopen("routine.md","rb");
    if (fp==NULL)
    {
        return -1;
    }
    
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
