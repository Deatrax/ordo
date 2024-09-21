#include<stdio.h>

int test2(){

    FILE *fp1=fopen("bal1.txt","wb");
    FILE *fp2=fopen("bal2.txt","wb");
    FILE *fp3=fopen("bal3.txt","wb");
    FILE *fp4=fopen("bal3.txt","wb");
    FILE *fp5=fopen("bal4.txt","wb");
    FILE *fp6=fopen("bal5.txt","wb");

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);

    
}