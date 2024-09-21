#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include <stdint.h>
//#include <windows.h>

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

typedef struct elinks{

    char link_name[51];
    char mlink[256];
}elinks;

typedef struct courseContainer{
    char course_name[16];
    char coursePath[612];
}courseContainer;
 
static courseContainer* allocate1DcourseConainer(int n){
    courseContainer* arr=(courseContainer*)malloc(n*sizeof(courseContainer));
    if(arr==NULL){
        perror("Memory Allocation of course container failed");
        return NULL;
    }
    return arr;
}

static void free1DcourseContainer(courseContainer* array){
    free(array);
}
//function to dynamically allocate a 1D elink
static elinks* allocate1D_elink(int size){
    elinks* array=(elinks*)malloc(size * sizeof(elinks));
    if (array==NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return array;
} 

// Function to dynamically allocate a 1D Routine array
static routine* allocate1Droutine(int size) {
    routine* array = (routine*)malloc(size * sizeof(routine));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return array;
}

static void free1Droutine(routine* array) {
    free(array);
}

// Function to dynamically allocate a 1D char array
static char* allocate1DCharArray(int size) {
    char* array = (char*)malloc(size * sizeof(char));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return array;
}

// Function to free the allocated 1D char array
static void free1DCharArray(char* array) {
    if (array != NULL) {
        free(array);
    }
}


// Function to allocate a 3D array
static char*** allocate3DArray(int x, int y, int z) {
    char*** array = (char***)malloc(x * sizeof(char**));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < x; i++) {
        array[i] = (char**)malloc(y * sizeof(char*));
        if (array[i] == NULL) {
            printf("Memory allocation failed\n");
            // Free previously allocated memory in case of failure
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < y; k++) {
                    free(array[j][k]);
                }
                free(array[j]);
            }
            free(array);
            return NULL;
        }

        for (int j = 0; j < y; j++) {
            array[i][j] = (char*)malloc(z * sizeof(char));
            if (array[i][j] == NULL) {
                printf("Memory allocation failed\n");
                // Free previously allocated memory in case of failure
                for (int k = 0; k < j; k++) {
                    free(array[i][k]);
                }
                free(array[i]);
                for (int k = 0; k < i; k++) {
                    for (int l = 0; l < y; l++) {
                        free(array[k][l]);
                    }
                    free(array[k]);
                }
                free(array);
                return NULL;
            }
        }
    }

    return array;
}

// Function to free the allocated 3D array
static void free3DArray(char*** array, int x, int y) {
    if (array == NULL) return;
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

//funtion to allocate 2d array
static char** allocate2DArray(int rows, int cols) {
    char** array = (char**)malloc(rows * sizeof(char*));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        array[i] = (char*)malloc(cols * sizeof(char));
        if (array[i] == NULL) {
            printf("Memory allocation failed\n");
            // Free previously allocated rows in case of failure
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }

    return array;
}

// Function to free the allocated 2D array
static void free2DArray(char** array, int rows) {
    if (array == NULL) return;
    
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

#ifdef _WIN32

static void getAppData_folder(char* str){

    sprintf(str,"%s\\AppData\\Roaming\\saps-is-my-project", getenv("USERPROFILE"));
}
//driver function to test nsure_directory_and_open_file() funtion

static void make_appData_filePath(char*  filename){
    char str[257];
    sprintf(str,"%s\\AppData\\Roaming\\saps-is-my-project\\%s\0",getenv("USERPROFILE"),filename);
    strcpy(filename,str);
}
#elif defined(__APPLE__)

static void getAppData_folder(char* str) {
    sprintf(str, "%s/Library/Application Support/saps-is-my-project", getenv("HOME"));
}

static void make_appData_filePath(char* filename) {
    char str[257];
    sprintf(str, "%s/Library/Application Support/saps-is-my-project/%s", getenv("HOME"), filename);
    strcpy(filename, str);
}

#endif


static int get_number_of_lines(const char *file) {
  // Open the file in read mode
  FILE *fp = fopen(file, "r");

  if (fp == NULL) {
    // Error handling: couldn't open the file
    return -1; 
  }

  int line_count = 0;
  char buffer[1024];

  // Read lines using fgets until EOF or error
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    line_count++;
  }
  // Check for errors during read
  if (ferror(fp)) {
    line_count = -1;
  }

  if(fp!=NULL)
    fclose(fp);

  return line_count;
}


static int addLine(char filename[],int line,const char constNewline[]){

    char* newline=allocate1DCharArray(strlen(constNewline)+4);
    strncpy(newline, constNewline, strlen(constNewline));
    newline[strlen(constNewline)] = '\0';
    char fileTEMP[500]="tempFILE.txt";
    make_appData_filePath(fileTEMP);
    //for project only
        //make_appData_filePath(fileTEMP);
    
    //filename[strlen(filename) - 1] = '\0'; ========because filenmes passed in code are not gonna have the new line caharecter, the newline charecter only comes when we input it in the console input.
    printf("got the arguments: %s, %d, %s\n",filename,line,newline);
    strcat(newline,"\n"); //========in the project the newline was not console inputted so i had to enter the new line manually
    FILE *src=fopen(filename,"rb");
    FILE *dest=fopen(fileTEMP,"wb");
    
    int flag=0;
    int i = 1;
    char buff[INT_LINE_SIZE];
    int appendNLflag=1;
    if(line==-1){
        int n=get_number_of_lines(filename);
        if (n==0)
        {
            // fputs(newline,dest);
            appendNLflag=0;
            goto append;
        }
        else
        line=n+1;
    }

    //iterative copy of the file contents and also add then new line if line no matches
    if (src==NULL || dest==NULL)
    {
        perror("Failed to execute:");
        if (dest!=NULL)
        {
            remove(fileTEMP);
        }
        return -1;
    }

    for (; !feof(src); i++)
    {      
        fgets(buff,INT_LINE_SIZE,src);
        if (i==line)
        {
            fputs(newline,dest);
            flag++;
            fputs(buff,dest); //printing the old line after the target line no is reached and new line has been placed 
            continue;
        }
        fputs(buff,dest);
        
    }

    //append module
    /*LABEL*/ append:
    if(line==-1)line=i;  //if line = -1 at function call then it is an append attempt;
    printf("at the end of all iterations, i=%d\n",i);
    if(!flag && i==line){ //checking if the line has not been placed and if this was an append attempt
        if (ferror(dest) || ferror(src))
        {
            perror("\nFile stream error:\n");
            if(src!=NULL) fclose(src);
            if(dest!=NULL) fclose(dest);
            remove(fileTEMP);
            return -1;
        }
        
        printf("--Line append initiated\n");
        newline[strlen(newline) - 1] = '\0';
        if(appendNLflag)fputc('\n',dest);
        fputs(newline,dest);
        flag++;
    }
    else if(!flag && i<line){ //makeing sure that the target line number was beyond append and replace
        printf("\nError: target line is out of replacement and append scope\n");
    }
    
    //after successful writing close the files
    /*LABEL*/closing:
    fclose(src);
    fclose(dest);
    // Attempt to remove the original file
    if (remove(filename) != 0) {
        perror("Error deleting file");
    } else {
        printf("File successfully deleted\n");
    }

    // Attempt to rename the temporary file
    if (rename(fileTEMP, filename) != 0) {
        perror("Error renaming file");
    } else {
        printf("File successfully renamed\n");
    }
    free(newline);
    if (flag)
    {
        return 0;
    }
    else return -1;
}

static int removeLine(char filename[],int line){
    char fileTEMP[260]="tempFILE.txt";
    make_appData_filePath(fileTEMP);
    //filename[strlen(filename) - 1] = '\0'; ========because filenmes passed in code are not gonna have the new line caharecter, the newline charecter only comes when we input it in the console input.
    printf("got the arguments: %s, %d\n",filename,line);
    FILE *src=fopen(filename,"rb");
    FILE *dest=fopen(fileTEMP,"wb");
    if (src==NULL || dest==NULL)
    {
        perror("Failed to execute:");
        if (dest!=NULL)
        {
            remove(fileTEMP);
        }
        return -1;
    }

    int flag=0;
    int i = 1;
    char buff[INT_LINE_SIZE];
    char buff2[INT_LINE_SIZE];
    while (1)
    {
        fgets(buff,INT_LINE_SIZE,src);
        if (i==line)
        {
            flag++;
            i++;
            memset(buff, 0, INT_LINE_SIZE); //making sure the unnecessary line is got rid of 
            continue;
        }
        
        if ((i+1)==line && !flag)
        {   
            fgets(buff2,INT_LINE_SIZE,src);
            if (feof(src))
            {
                buff[strlen(buff)-1]='\0';
                fputs(buff,dest);
                memset(buff2,0,INT_LINE_SIZE);
                flag++;
                break;
            }
            memset(buff2, 0, INT_LINE_SIZE);
            fputs(buff,dest);
            i+=2;
            flag++;
            continue;
        }
        fputs(buff,dest);
        if (feof(src))
        {
            break;
        }
        i++;
    }
    
    //after successful writing close the files
    fclose(src);
    fclose(dest);
    
    if(flag && i<line){ //makeing sure that the target line number was beyond append and replace
        printf("\nError: target line is out of scope\n");
    }
    // Attempt to remove the original file
    if (remove(filename) != 0) {
        perror("Error deleting file");
    } else {
        printf("File successfully deleted\n");
    }

    // Attempt to rename the temporary file
    if (rename(fileTEMP, filename) != 0) {
        perror("Error renaming file");
    } else {
        printf("File successfully renamed\n");
    }
    if (flag)
    {
        return 0;
    }
    else return -1;
}

static int replaceLINE(char filename[],int line,char newline[]){

    char fileTEMP[500]="tempFILE.txt";
    make_appData_filePath(fileTEMP);
    //filename[strlen(filename) - 1] = '\0'; ========because filenmes passed in code are not gonna have the new line caharecter, the newline charecter only comes when we input it in the console input.
    printf("got the arguments: %s, %d, %s\n",filename,line,newline);
    strcat(newline,"\n"); //========in the project the newline was not console inputted so i had to enter the new line manually
    FILE *src=fopen(filename,"rb");
    FILE *dest=fopen(fileTEMP,"wb");
    if (src==NULL || dest==NULL)
    {
        perror("Failed to execute");
        return -1;

    }
    int flag=0;
    char buff[INT_LINE_SIZE];
    for (int i = 1; !feof(src); i++)
    {      
        fgets(buff,INT_LINE_SIZE,src);
        if (i==line)
        {   
            if(feof(src)) newline[strlen(newline)-1]='\0';
            fputs(newline,dest);
            flag++;
            memset(buff, 0, INT_LINE_SIZE); //making sure the unnecessary line is got rid of
            continue;
        }
        fputs(buff,dest);
        
    }

    fclose(src);
    fclose(dest);

    // Attempt to remove the original file
    if (remove(filename) != 0) {
        perror("Error deleting file");
    } else {
        printf("File successfully deleted\n");
    }

    // Attempt to rename the temporary file
    if (rename(fileTEMP, filename) != 0) {
        perror("Error renaming file");
    } else {
        printf("File successfully renamed\n");
    }

    if(!flag){
        printf("\ntarget line does not exist!!\n");
        return -1;
    }
    else return 0;
    
}


static int old_and_doesnt_work_removeLine(char filename[], int line){


    //filename[strlen(filename) - 1] = '\0';

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
    if(src!=NULL)
        fclose(src);
    if(dest!=NULL)
        fclose(dest);
    remove(filename);
    rename("tempFILE.txt",filename);
    
    return 0;
}


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

    char file[260]="ulist.spenc";
    make_appData_filePath(file);
    FILE *fp1=fopen(file,"wb");
    if (fp1==NULL)
    {
        perror("The file open failed");
        return 0;
    }
    char out[200];
    startAll(pass,usr,out);
    printf("\nwriting to file: %s",out);
    fprintf(fp1,"%s",out);

    if(fp1!=NULL)
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

/// @brief Pilot fountion for the hashing system
/// @param psword the password entered by the user in char array string
/// @param slt the user name to be turned into the aslt
/// @param output the output hash value
/// @return simplye return 0 which is useless
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

    char file0[260]="ulist.spenc";
    make_appData_filePath(file0);
    FILE *fp=fopen(file0,"rb");

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
    if(fp!=NULL)
        fclose(fp);
    printf("func.out:%s: got data: %s\n",__func__,dat);

    char out[200];
    startAll(pass,usr,out);
    if (!strncmp(dat,out,strlen(out)))
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

#ifdef _WIN32
static void get_usr_env(char *str){

    // str=(char*)malloc(sizeof(INI_SIZEs));
    sprintf(str,"%s\\Documents\\SIMS-Academic\\", getenv("USERPROFILE"));
}
#elif defined(__APPLE__)

static void get_usr_env(char *str) {
    sprintf(str, "%s/Documents/SIMS-Academic/", getenv("HOME"));
}
#endif

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

    if(fp!=NULL)
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
    
    
    char** data=allocate2DArray(a+1,1000);
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
    
    free2DArray(data,a+1);
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
    if(fp!=NULL)
        fclose(fp);
    if(fp2!=NULL)
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
    char** data=allocate2DArray(a+1,1000);
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
    
    free2DArray(data,a+1);
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
    if(fp!=NULL)
        fclose(fp);
    if(fp2!=NULL)
        fclose(fp2);


    }

    return 0;
}



static void read_courseOLD(courseContainer* corsCont,int nums,char coursedatPath[]){

    /*OLD READ_COURSE CODE BREFORE APPDATA INTEGRATION

        int n=get_number_of_lines("coursedat.spenc");
        char coursePath[260]="coursedat.spenc";
        make_appData_filePath(coursePath);
        FILE *fp=fopen(coursePath,"r");

        for (int i = 1; i<nums; i++)
        {      
            fgets(dest[i],255,fp);
            printf("GOT THE COURSE: %s",dest[i]);
        }
        if(fp!=NULL)
        fclose(fp);
    */

    // char datpath[516]="coursedat.spenc";
    // make_appData_filePath(datpath);
    // int n=get_number_of_lines(coursedatPath);
    // char coursePath[260]="coursedat.spenc";
    // make_appData_filePath(coursePath);
    char buff[620];
    int i=0;
    FILE* fp=fopen(coursedatPath,"r");
    for (; /*!feof(fp)*/ i<nums; i++)
    {      
        fgets(buff,INT_LINE_SIZE,fp);
        char* tok=strtok(buff,",");
        strncpy(corsCont[i].course_name,tok,strlen(tok));
        corsCont[i].course_name[strlen(tok)]='\0';
        printf("the course name got was=%s\n",corsCont[i].course_name);
        tok=strtok(NULL,",");
        strncpy(corsCont[i].coursePath,tok,strlen(tok));
        corsCont[i].coursePath[strlen(tok)]='\0';
        printf("got the course path\n=%s",corsCont[i].coursePath);
        
    }
    if(fp!=NULL)
        fclose(fp);
}

static void read_course(courseContainer* corsCont, int nums, char coursedatPath[]) {
    char buff[620];
    FILE* fp = fopen(coursedatPath, "r");

    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < nums; i++) {
        if (fgets(buff, sizeof(buff), fp) == NULL) {
            printf("Error reading line or reached EOF unexpectedly.\n");
            break;
        }

        // Remove newline character if it exists
        size_t len = strlen(buff);
        if (len > 0 && buff[len - 1] == '\n') {
            buff[len - 1] = '\0';
        }

        char* tok = strtok(buff, ",");
        if (tok != NULL) {
            strncpy(corsCont[i].course_name, tok, sizeof(corsCont[i].course_name) - 1);
            corsCont[i].course_name[sizeof(corsCont[i].course_name) - 1] = '\0'; // Ensure null termination
        }

        tok = strtok(NULL, ",");
        if (tok != NULL) {
            strncpy(corsCont[i].coursePath, tok, sizeof(corsCont[i].coursePath) - 1);
            corsCont[i].coursePath[sizeof(corsCont[i].coursePath) - 1] = '\0'; // Ensure null termination
        }
        
        printf("The course name got was: %s\n", corsCont[i].course_name);
        printf("Got the course path: %s\n", corsCont[i].coursePath);
    }

    fclose(fp);
}


static void read_links(char** dest,int nums){

    //int n=get_number_of_lines("coursedat.spenc");
    FILE *fp=fopen("linkdat.spenc","r");
    char buff[256]="\0";
    fgets(buff,255,fp);
    printf("first line in the link file:'%s'\n",buff);
    if (!strcmp(buff,"checksum"))
    {
        printf("link file is valid\n");
    }
    else{
        printf("link file is not valid\n");
    }
    
    for (int i = 1; i<nums; i++) //links start form line 2 in file, array indx is 1
    {      
        fgets(dest[i],255,fp);
        printf("GOT THE LINK: %s",dest[i]);
    }

    if(fp!=NULL)
        fclose(fp);
}

static void New_readLinks(elinks* links,int nums){

    char file[260]="linkdat.spenc";
    make_appData_filePath(file);
    FILE *fp=fopen(file,"r");
    char buff[256]="\0";
    fgets(buff,255,fp);
    printf("first line in the link file:'%s'\n",buff);
    if (!strcmp(buff,"checksum\n"))
    {
        printf("link file is valid\n");
    }
    else{
        printf("link file is not valid\n");
    }
    
    for (int i = 0; i<nums-1; i++) //links start form line 2 in file, array indx is 1
    {      
        fgets(buff,255,fp);
        if(buff[strlen(buff)-1]=='\n') buff[strlen(buff)-1]='\0';
        char* tok=strtok(buff,",");
        sprintf(links[i].link_name,"\0");
        strcat(links[i].link_name,tok);
        tok=strtok(NULL,",");
        sprintf(links[i].mlink,"\0");
        strcat(links[i].mlink,tok);
        printf("GOT THE LINK: linkname='%s' mlink='%s'\n",links[i].link_name,links[i].mlink);
    }

    if(fp!=NULL)
        fclose(fp);
}

static int getRoutine( routine *obj, int nums){

    FILE *fp=fopen("routine.md","rb");
    if (fp==NULL)
    {
        return -1;
    }
    
    char read[1024];
    char*** dat = allocate3DArray(nums, 4, 512);

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
    if(fp!=NULL)
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
    free3DArray(dat,nums,4);
    return 1;
}


typedef struct upcoming
{
    char name[50];
    char type[50];
    int date;
    int month;
    int year;
    int time;
    int lineNum;

}upcoming;

static int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

static int daysInMonth(int month, int year) {
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

static int remainingTime(upcoming *obj, int day, int month, int year, int nums, int *neu) {
    int k = 0;

    for (int i = 0; i < nums; i++) {
        obj[i].time = 0;
        int eventDay = obj[i].date;
        int eventMonth = obj[i].month;
        int eventYear = obj[i].year;

        printf("i is now:%d nums is now:%d working with data: obj day: %d, obj month: %d, obj year: %d, current day: %d, month: %d, year: %d\n",
               i, nums, eventDay, eventMonth, eventYear, day, month, year);

        if (eventYear > year || (eventYear == year && (eventMonth > month || (eventMonth == month && eventDay > day)))) {
            printf("....pass\n");

            // Future event in the same year
            if (eventYear == year) {
                if (eventMonth == month) {
                    obj[i].time = eventDay - day;
                } else {
                    int daysRemaining = daysInMonth(month, year) - day;
                    for (int m = month + 1; m < eventMonth; m++) {
                        daysRemaining += daysInMonth(m, year);
                    }
                    daysRemaining += eventDay;
                    obj[i].time = daysRemaining;
                }
            } else {
                // Future event in a different year
                int daysRemaining = daysInMonth(month, year) - day;

                // Add the days remaining in the current year
                for (int m = month + 1; m <= 12; m++) {
                    daysRemaining += daysInMonth(m, year);
                }

                // Add days for full years in between
                for (int y = year + 1; y < eventYear; y++) {
                    daysRemaining += isLeapYear(y) ? 366 : 365;
                }

                // Add days from the start of the event's year
                for (int m = 1; m < eventMonth; m++) {
                    daysRemaining += daysInMonth(m, eventYear);
                }
                daysRemaining += eventDay;

                obj[i].time = daysRemaining;
            }
        } else if (eventDay == day && eventMonth == month && eventYear == year) {
            // Event is happening today, no need to update time
            NULL;
        } else {
            printf("....fail\n");
            k++;
        }
    }

    printf("nums is currently: %d\n", nums);
    *neu = k;
    return 0;
}



static void bsort(upcoming *obj,int n){
    int swaps =0;
    for (int i = 0; i < n-1; i++)
    {   
        swaps=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (obj[j].time>obj[j+1].time)
            {
                upcoming temp=obj[j];
                obj[j]=obj[j+1];
                obj[j+1]=temp;
                swaps++;
            }
        }
        if (!swaps)
        {
            break;
        }
    }
}


static upcoming* allocate1Dupcoming(int size) {
    upcoming* array = (upcoming*)malloc(size * sizeof(upcoming));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return array;
}

static void free1Dupcoming(upcoming* array) {
    free(array);
}

/// @brief function for getting the upcomming tasks for the assignments tab
/// @param obj is a struct for holding the tasks with their data
/// @param num2 
/// @return nothing actually
static int gettasks( upcoming *obj,int *num2){

    char file[260]="upcoming.md";
    make_appData_filePath(file);
    int num= get_number_of_lines(file);
    FILE *fp=fopen(file,"rb");
    char read[1024];
    char*** dat=allocate3DArray(num,5,512);

    for (int i = 0; i < num; i++)
    {
        fgets(read,1024,fp);
        printf("read data: %s",read);
        read[strlen(read)-1]='\0';
        char *tok=strtok(read,"|");
        for (int j = 0; j < 5; j++)
        {
            char out[100];
            strcpy(out,tok);
            sprintf(dat[i][j],"\0");
            strcat(dat[i][j],tok);
            tok=strtok(NULL,"|");
        }
        strcpy(obj[i].name,dat[i][0]);
        strcpy(obj[i].type,dat[i][1]);
        obj[i].date=atoi(dat[i][2]);
        obj[i].month=atoi(dat[i][3]);
        obj[i].year=atoi(dat[i][4]);
        obj[i].lineNum=i+1;
    }
    if(fp!=NULL)
        fclose(fp);

    time_t current_time;
    struct tm *time_info;

    // Get current time
    current_time = time(NULL);

    // Convert time to a human-readable format
    time_info = localtime(&current_time);
    if (time_info == NULL) {
        perror("localtime");
        return 1;
    }

   
    int day = time_info->tm_mday;
    // Extract month (0-indexed) and add 1 to get 1-based month
    int month = time_info->tm_mon + 1;
    int year = time_info->tm_year + 1900;
    printf("Current day: %d\n", day);
    printf("Current month: %d\n", month);

    int skip=0;
    remainingTime(obj,day,month,year,num,&skip);
    printf("after remaining time calculation, num is:%d\n",num);
    *num2=skip;
    bsort(obj,num);

    free3DArray(dat,num,5);
}

#include <stdio.h>
#include <errno.h>

#ifdef _WIN32
#include <direct.h>   // For _mkdir() on Windows
#define mkdir _mkdir  // Use _mkdir on Windows
#else
#include <sys/stat.h>  // For mkdir() on macOS/Linux
#endif

static int ensure_directory_and_open_file(const char *dir_path, const char *file_path, const char *mode) {
    
    //skip if null passed
    if (dir_path == NULL || strlen(dir_path) == 0) {
        goto fileCheck;
    }
    
    // Try to create the directory
#ifdef _WIN32
    if (mkdir(dir_path) == -1) {
#else
    if (mkdir(dir_path, 0777) == -1) {
#endif
        if (errno != EEXIST) {
            perror("mkdir failed");
            return -1;  // Directory creation failed and it doesn't already exist
        }
        // If errno is EEXIST, we know the directory already exists
    }

    fileCheck:
    //check if null was passed for the filepath and it is to be skipped
    if (file_path == NULL || strlen(file_path) == 0) {
        return 0;
    }
    // Now that the directory exists, open the file
    FILE *file = fopen(file_path, mode);
    if (file == NULL) {
        perror("fopen failed");
        return -1;  // File opening failed
    }

    // Use the file...
    // Don't forget to close the file when done
    fclose(file);

    
    return 0;  // Success
}

#ifdef _WIN32

    #include <stdio.h>
    #include <windows.h>
    #include <string.h>

    #define MAX_FILES 100
    #define MAX_NAME_LEN 256
    #define MAX_PATH_LEN 1024

    static void read_directory(const char *dir_path, char files[MAX_FILES][MAX_NAME_LEN], char folders[MAX_FILES][MAX_NAME_LEN],
                        char file_paths[MAX_FILES][MAX_PATH_LEN], char folder_paths[MAX_FILES][MAX_PATH_LEN]) {
        WIN32_FIND_DATAW find_file_data;
        HANDLE h_find = INVALID_HANDLE_VALUE;
        wchar_t w_search_path[MAX_PATH_LEN];
        int file_count = 0;
        int folder_count = 0;

        // Convert the directory path to a wide-character string
        wchar_t w_dir_path[MAX_PATH_LEN];
        MultiByteToWideChar(CP_UTF8, 0, dir_path, -1, w_dir_path, MAX_PATH_LEN);

        // Create the search path with wildcard "*.*"
        swprintf(w_search_path, MAX_PATH_LEN, L"%s\\*.*", w_dir_path);

        // Use the wide-character version of FindFirstFile
        h_find = FindFirstFileW(w_search_path, &find_file_data);

        if (h_find == INVALID_HANDLE_VALUE) {
            wprintf(L"Invalid file handle. Error is %u\n", GetLastError());
            return;
        }

        do {
            if (find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                if (wcscmp(find_file_data.cFileName, L".") != 0 && wcscmp(find_file_data.cFileName, L"..") != 0) {
                    // Convert wide-character folder name back to a narrow string
                    wcstombs(folders[folder_count], find_file_data.cFileName, MAX_NAME_LEN);
                    snprintf(folder_paths[folder_count], MAX_PATH_LEN, "%s\\%s", dir_path, folders[folder_count]);
                    folder_count++;
                }
            } else {
                // Convert wide-character file name back to a narrow string
                wcstombs(files[file_count], find_file_data.cFileName, MAX_NAME_LEN);
                snprintf(file_paths[file_count], MAX_PATH_LEN, "%s\\%s", dir_path, files[file_count]);
                file_count++;
            }
        } while (FindNextFileW(h_find, &find_file_data) != 0);

        FindClose(h_find);
    }

#elif defined(__APPLE__)

    #include <stdio.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>

    #define MAX_FILES 100
    #define MAX_NAME_LEN 256
    #define MAX_PATH_LEN 1024

    static void read_directory(const char *dir_path, char files[MAX_FILES][MAX_NAME_LEN], char folders[MAX_FILES][MAX_NAME_LEN],
                        char file_paths[MAX_FILES][MAX_PATH_LEN], char folder_paths[MAX_FILES][MAX_PATH_LEN]) {
        DIR *dir;
        struct dirent *entry;
        char full_path[MAX_PATH_LEN];
        int file_count = 0;
        int folder_count = 0;

        dir = opendir(dir_path);
        if (dir == NULL) {
            perror("opendir");
            return;
        }

        while ((entry = readdir(dir)) != NULL) {
            snprintf(full_path, MAX_PATH_LEN, "%s/%s", dir_path, entry->d_name);
            if (entry->d_type == DT_DIR) {
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    snprintf(folders[folder_count], MAX_NAME_LEN, "%s", entry->d_name);
                    snprintf(folder_paths[folder_count], MAX_PATH_LEN, "%s", full_path);
                    folder_count++;
                }
            } else {
                snprintf(files[file_count], MAX_NAME_LEN, "%s", entry->d_name);
                snprintf(file_paths[file_count], MAX_PATH_LEN, "%s", full_path);
                file_count++;
            }
        }
        closedir(dir);
    }

#endif

static int FileHandleDriver(
    char dir_path[MAX_PATH_LEN],
    char files[MAX_FILES][MAX_NAME_LEN],
    char folders[MAX_FILES][MAX_NAME_LEN],
    char file_paths[MAX_FILES][MAX_PATH_LEN],
    char folder_paths[MAX_FILES][MAX_PATH_LEN],
    int* fileCount,
    int* folderCount
    ) {
    
    // printf("Enter directory path: ");
    // fgets(dir_path, MAX_PATH_LEN, stdin);

    // Remove newline character if it exists
    size_t len = strlen(dir_path);
    if (len > 0 && dir_path[len - 1] == '\n') {
        dir_path[len - 1] = '\0';
    }

    read_directory(dir_path, files, folders, file_paths, folder_paths);

    printf("\n-----Folders:\n");
    for (int i = 0; i < MAX_FILES && folders[i][0] != '\0'; i++) {
        printf("%s\n", folders[i]);
    }

    printf("\n-----Folder Paths:\n");
    for (int i = 0; i < MAX_FILES && folder_paths[i][0] != '\0'; i++) {
        printf("%s\n", folder_paths[i]);
    }

    printf("\n-----Files:\n");
    for (int i = 0; i < MAX_FILES && files[i][0] != '\0'; i++) {
        printf("%s\n", files[i]);
        (*fileCount)++;
    }

    printf("\n-----File Paths:\n");
    for (int i = 0; i < MAX_FILES && file_paths[i][0] != '\0'; i++) {
        printf("%s\n", file_paths[i]);
        (*folderCount)++;
    }

    return 0;
}


static int alphaBsort(char str[MAX_FILES][MAX_NAME_LEN]) {
    int i, j, n = 0;
    char s[MAX_NAME_LEN];

    // Find the number of valid entries in the array
    for (i = 0; i < MAX_FILES && str[i][0] != '\0'; i++) {
        n++;
    }

    int swaps;
    // Bubble sort
    for (i = 0; i < n - 1; i++) {
        swaps = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(str[j], str[j + 1]) > 0) {
                // Swap the strings
                strcpy(s, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], s);
                swaps++;
            }
        }
        // If no swaps were made, the array is already sorted
        if (swaps == 0) {
            break;
        }
    }

    // Print the sorted order of names
    printf("The sorted order of names are:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0; // Return 0 to indicate success
}

//driver function for running test of appdata related activites
// int main() {
//     char dir[260];
//     getAppData_folder(dir);
//     char file[260] = "my_file.txt";
//     make_appData_filePath(file);

//     if (ensure_directory_and_open_file(dir, file, "w") == 0) {
//         printf("File opened successfully.\n");
//     } else {
//         printf("Failed to open file.\n");
//     }

//     return 0;
// }


// //=====================================
// struct Object {
//     char name[512];
//     int dura;
//     char teacher[512];
//     char room[512];
// };
// /// @brief tester function for testing 3d allocated array
// /// @return nothing
// int main() {
//     int nums = 5; // Example number of elements
//     char read[1024];
//     struct Object obj[nums];

//     // Dynamically allocate the 3D array
//     char*** dat = allocate3DArray(nums, 4, 512);
//     if (dat == NULL) {
//         return 1; // Exit if memory allocation failed
//     }

//     // Simulate file reading and processing (replace with actual file reading)
//     for (int i = 0; i < nums; i++) {
//         // Example input string (replace with fgets in your actual code)
//         strcpy(read, "John Doe|120|Mr. Smith|Room 101");
//         read[strlen(read) - 1] = '\0';
//         char *tok = strtok(read, "|");
//         for (int j = 0; j < 4; j++) {
//             sprintf(dat[i][j], "\0");
//             strcat(dat[i][j], tok);
//             tok = strtok(NULL, "|");
//         }
//         strcpy(obj[i].name, dat[i][0]);
//         obj[i].dura = atoi(dat[i][1]);
//         strcpy(obj[i].teacher, dat[i][2]);
//         strcpy(obj[i].room, dat[i][3]);        
//     }

//     // Free the allocated memory
//     free3DArray(dat, nums, 4);

//     return 0;
// }


// /// @brief Tester main function for the everything.c file
// /// @return a lot of things when used in the project
// int main() {     
//     int a = 3; // Example value for 'a'
//     char str[] = "this/is/a/test"; // Example input string

//     // Dynamically allocate the 2D array
//     char** data = allocate2DArray(a + 1, 1000);
//     if (data == NULL) {
//         return 1; // Exit if memory allocation failed
//     }

//     char str3[1000];
//     char str1[2000];
//     strcpy(str1, str);
//     printf("\nSafety string copy complete. Contents: %s\n", str1);
    
//     char *tok = strtok(str1, "/");
//     for (int i = 1; i <= a; i++) {
//         // Clear the data[i] string
//         sprintf(data[i], "\0");
//         strcat(data[i], tok);
//         tok = strtok(NULL, "/");
//         printf("strtok pass  data[%d]=%s\n", i, data[i]);
//     }

//     // Free the allocated memory
//     free2DArray(data, a + 1);

//     return 0;
// }
// // Function to count the number of folders in a directory
// static int getNumberOfFolders(const char path[]) {
//     WIN32_FIND_DATA findFileData;
//     HANDLE hFind;
//     int folderCount = 0;

//     char searchPath[MAX_PATH];
//     snprintf(searchPath, MAX_PATH, "%s\\*", path);

//     hFind = FindFirstFile(searchPath, &findFileData);
//     if (hFind == INVALID_HANDLE_VALUE) {
//         return 0;
//     }

//     do {
//         if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
//             if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
//                 folderCount++;
//             }
//         }
//     } while (FindNextFile(hFind, &findFileData) != 0);

//     FindClose(hFind);
//     return folderCount;
// }

// // Function to count the number of files in a directory
// static int getNumberOfFiles(const char path[]) {
//     WIN32_FIND_DATA findFileData;
//     HANDLE hFind;
//     int fileCount = 0;

//     char searchPath[MAX_PATH];
//     snprintf(searchPath, MAX_PATH, "%s\\*", path);

//     hFind = FindFirstFile(searchPath, &findFileData);
//     if (hFind == INVALID_HANDLE_VALUE) {
//         return 0;
//     }

//     do {
//         if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
//             fileCount++;
//         }
//     } while (FindNextFile(hFind, &findFileData) != 0);

//     FindClose(hFind);
//     return fileCount;
// }
