#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>



int startAll(char* psword, char* slt, char* output);

int  umake( char *usr,  char* pass){

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
uint32_t H[4] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };

//circular Rotate right
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))

//logical functions
#define F(x, y, z) ((x & y) | (~x & z))
#define G(x, y, z) ((x & z) | (y & ~z))
#define H(x, y, z) (x ^ y ^ z)
#define I(x, y, z) (y ^ (x | ~z))

// Process block
void process_block(uint32_t *W, uint32_t *H) {
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
void simplified_sha(const uint8_t *psword, size_t length, uint32_t *hash) {
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
void print_hash(uint32_t *hash) {
    for (int i = 0; i < 4; ++i) {
        printf("%08x", hash[i]);
    }
    printf("\n");
}



#define HASH_SIZE 4  // Size of the hash value

// Function to convert a byte to a hexadecimal string
void byte_to_hex(uint8_t byte, char* hex) {
    const char* hex_digits = "0123456789abcdef";
    hex[0] = hex_digits[(byte >> 4) & 0x0F];
    hex[1] = hex_digits[byte & 0x0F];
}

void myHash(const char* input, char* output) {

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

void salt(char* salt) {
    char output[HASH_SIZE * 2 + 1];

    myHash(salt, output);
    for (int i = 0; i < 10; i++)
    {
        myHash(output,output);
    }
    sprintf(salt,"%s",output);
    
}


int startAll(char* psword, char* slt, char* output) {
    
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


// int main(){

//     //DECLEARATIONS
//     FILE *fp=fopen("ulist.spenc","rb");
//     char psword[100] = "eat my ass";
//     char slt[17]="user";
//     //
//     if (fp==NULL)
//     {
//         printf("\n\nNo existing user(s) found....creating new user....\n\nType Username(max 100 chars)\t    :");
//         fflush(stdin);
//         scanf("%s",slt);
//         inpass:
//         printf("Type password:");
//         scanf("%s",psword);
//         // int temp,cnt=0;
//         // temp=pass;
//         // while (temp)
//         // {
//         //     temp/=10;
//         //     cnt++;
//         // }
//         // if (cnt>4)
//         // {
//         //     printf("Password size too big,, retry\n");
//         //     goto inpass;
//         // }
        
        
//         if ( umake(slt,psword))
//         {
//             printf(".....User created successfully\n Procced to login?(y/n) ->");
//             decision:
//             fflush(stdin);
//             scanf("%c",&slt[0]);
//             switch (slt[0])
//             {
//             case 'y':
//                 goto login;
//                 break;
            
//             case 'n':
//                 printf("Exiting SPENC login system.....Exited");
//                 break;

//             default:
//                 printf("Invalid input\n try again ->");
//                 goto decision;
//                 break;
//             }
//         }
//         else{
            
//             printf("Failed to create username, Fatal error.....\n  PLEASE CONTECT DEV\n...exiting....exited");
//         }
       
//     }
//     else{
//         login:NULL;

//         printf("Welcome Back!! \n\nType Username\t    :");
//         fflush(stdin);
//         scanf("%s",slt);
//         printf("Type password\t    :");
//         scanf("%s",psword);


//         if (chk(slt,psword))
//         {
//             printf("login successful!!\n");
//         }
//         else{
//             printf("Incorrect username or password!\n");
            
            
//         }
        
//     }
// }
