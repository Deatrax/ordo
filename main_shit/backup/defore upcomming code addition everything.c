#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include <stdint.h>

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


//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================

static int startAll(char* psword, char* slt, char* output);

static int  umake( char *usr,  char* pass){

    FILE *fp1=fopen("ulist.spenc","wb");
    if (fp1==NULL)
    {
        perror("The file open failed");
        return 0;
    }
    char out[200];
    startAll(pass,usr,out);
    printf("\nwriting to file: %s",out);
    fprintf(fp1,"%s",out);
    fclose(fp1);
    return 1;

}



// Initial hash values 
uint32_t static H[4] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };

//circular Rotate right
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))

//logical functions
#define F(x, y, z) ((x & y) | (~x & z))
#define G(x, y, z) ((x & z) | (y & ~z))
#define H(x, y, z) (x ^ y ^ z)
#define I(x, y, z) (y ^ (x | ~z))

// Process block
static void process_block(uint32_t *W, uint32_t *H) {
    uint32_t a = H[0], b = H[1], c = H[2], d = H[3];
    uint32_t temp;

    // Simple 4 round function
    for (int i = 0; i < 16; ++i) {
        temp = a + F(b, c, d) + W[i];
        a = d;
        d = c;
        c = b;
        b = temp;
    }
    for (int i = 16; i < 32; ++i) {
        temp = a + G(b, c, d) + ROTR(W[i % 16], i % 32);
        a = d;
        d = c;
        c = b;
        b = temp;
    }
    for (int i = 32; i < 48; ++i) {
        temp = a + H(b, c, d) + ROTR(W[i % 16], i % 32);
        a = d;
        d = c;
        c = b;
        b = temp;
    }
    for (int i = 48; i < 64; ++i) {
        temp = a + I(b, c, d) + ROTR(W[i % 16], i % 32);
        a = d;
        d = c;
        c = b;
        b = temp;
    }

    H[0] += a;
    H[1] += b;
    H[2] += c;
    H[3] += d;
}

// Padding and processing function
static void simplified_sha(const uint8_t *psword, size_t length, uint32_t *hash) {
    // Copy initial hash values
    memcpy(hash, H, 4 * sizeof(uint32_t));

    // Calculate new length with padding
    size_t new_length = ((length + 8) / 64 + 1) * 64;
    uint8_t *padded = (uint8_t *)calloc(new_length, 1);

    // Copy psword to padded psword
    memcpy(padded, psword, length);
    padded[length] = 0x80; // Append '1' bit

    // Append original length in bits
    uint64_t bit_length = length * 8;
    memcpy(padded + new_length - 8, &bit_length, sizeof(uint64_t));

    // Process each 64-byte block
    for (int k = 0; k < 3; k++)
    {
        for (size_t i = 0; i < new_length; i += 64) {
            uint32_t W[16];
            memcpy(W, padded + i, 64);
            process_block(W, hash);
        }
    }
    

    free(padded);
}

// Print hash as hex
static void print_hash(uint32_t *hash) {
    for (int i = 0; i < 4; ++i) {
        printf("%08x", hash[i]);
    }
    printf("\n");
}



#define HASH_SIZE 4  // Size of the hash value

// Function to convert a byte to a hexadecimal string
static void byte_to_hex(uint8_t byte, char* hex) {
    const char* hex_digits = "0123456789abcdef";
    hex[0] = hex_digits[(byte >> 4) & 0x0F];
    hex[1] = hex_digits[byte & 0x0F];
}

static void myHash(const char* input, char* output) {

    // Initialize hash array
    uint8_t hash[HASH_SIZE] = {0}; 

    // Iterate over each character of the input string
    for (size_t i = 0; i < strlen(input); i++) {
        hash[i % HASH_SIZE] ^= input[i];
        hash[i % HASH_SIZE] = (hash[i % HASH_SIZE] << 1) | (hash[i % HASH_SIZE] >> 7);
    }

    // Converting hash bytes to a HASH_SIZE x2 -character hexadecimal string
    for (int i = 0; i < HASH_SIZE; i++) {
        byte_to_hex(hash[i], &output[i * 2]);
    }

    output[HASH_SIZE * 2] = '\0';
}

static void salt(char* salt) {
    char output[HASH_SIZE * 2 + 1];

    myHash(salt, output);
    for (int i = 0; i < 10; i++)
    {
        myHash(output,output);
    }
    sprintf(salt,"%s",output);
    
}


static int startAll(char* psword, char* slt, char* output) {
    
    salt(slt);
    strcat(psword, slt);
    uint32_t hash[4];

    simplified_sha((const uint8_t *)psword, strlen(psword), hash);
    print_hash(hash);
    //sprintf(output,"%s",hash);
    sprintf(output,"%08x%08x%08x%08x", hash[0], hash[1], hash[2], hash[3]);
    return 0;
}


static int chk( char *usr,  char* pass){

    
    FILE *fp=fopen("ulist.spenc","rb");

    fseek(fp,0,SEEK_END);
    int flen=ftell(fp);
    fseek(fp,0,SEEK_SET);

    char *dat=(char*)malloc(flen*sizeof(char));
    dat[0]='\0';
    //fgets(dat,sizeof(dat),fp);
    //fread(dat,sizeof(dat),3,fp);
    // char fch;
    // int i=0;
    // while (fscanf(fp,"%c",&fch)==1)
    // {
    //     dat[i]=fch;
    //     i++;
    // }
    //dat[i]='\0';
    fscanf(fp,"%s",dat);
    fclose(fp);
    printf("func.out:%s: got data: %s\n",__func__,dat);

    char out[200];
    startAll(pass,usr,out);
    if (!strcmp(dat,out))
    {
        printf("====ALHAMDULLILAH THIS FINALLY WORKED====");
        return 2;
    }
    else{
        printf("====Fucking die====\ninshaAllah it'll work...");
        return 0;
    }
    
}


//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================


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


static int read_course(char dest[][256],int nums){

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


static int getRoutine( routine *obj, int nums){

    FILE *fp=fopen("routine.md","rb");
    if (fp==NULL)
    {
        return -1;
    }
    
    char read[1024];
    char dat[nums][4][512];

    for (int i = 0; i < nums; i++)
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
