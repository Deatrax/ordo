#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define INT_LINE_SIZE 2048

static int removeLine(char filename[], int line){


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

    fclose(src);
    fclose(dest);
    remove(filename);
    rename("tempFILE.txt",filename);
    
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

static int remainingTime(upcoming *obj, int day, int month, int year, int nums,int *neu) {

    int k=0;
    for (int i = 0; i < nums; i++) {
        obj[i].time=0;
        int eventDay = obj[i].date;
        int eventMonth = obj[i].month;
        printf("i is now:%d nums is now:%d working with data: obj day: %d, obj month: %d,,,current day:%d, month:%d",i,nums,eventDay,eventMonth,day,month);
        if (eventMonth > month || (eventMonth == month && eventDay > day)) {
            printf("....pass\n");
            // Future event in the same year
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
        }else if (eventDay==day && eventMonth== month)
        {
            NULL;
        }
         else {
            printf("....fail\n");
            k++;
            // // Future event in the next year
            // int daysRemaining = daysInMonth(month, year) - day;
            // for (int m = month + 1; m <= 12; m++) {
            //     daysRemaining += daysInMonth(m, year);
            // }
            // for (int m = 1; m < eventMonth; m++) {
            //     daysRemaining += daysInMonth(m, year + 1);
            // }
            // daysRemaining += eventDay;
            // obj[i].time = daysRemaining;

            removeLine("upcoming.md",obj[i].lineNum);
            // for (int j = i; j < nums-1; j++)
            // {   
            //     printf("removal loop running....");
            //     obj[j]=obj[j+1];
                
            // }
            // k--;
            // nums--;
            
        }
        
    }
    printf("nums is currently: %d\n",nums);
    *neu=k;
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




static int gettasks( upcoming *obj,int *num2){

    int num= get_number_of_lines("upcoming.md");
    FILE *fp=fopen("upcoming.md","rb");
    char read[1024];
    char dat[num][5][512];

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

    printf("Current day: %d\n", day);
    printf("Current month: %d\n", month);

    int skip=0;
    remainingTime(obj,day,month,obj->year,num,&skip);
    printf("after remaining time calculation, num is:%d\n",num);
    *num2=skip;
    bsort(obj,num);
}



int main(){

   

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




    int num=get_number_of_lines("upcoming.md");
    int skip=0;
    printf("got no of lines:%d\n",num);
    upcoming thing[num];
    int ret=gettasks(thing,&skip);

    printf("\n no of lines skiped:%d\n",skip);
    for (int i = 0; i < num; i++)
    {   
        if(month<thing[i].month || (day==thing[i].date && month==thing[i].month) || (day<thing[i].date && month==thing[i].month))
        printf("entry %d: \tname:%s\ttype:%s\tdate:%d-%d-%d\tremaining time:%d lineNum in file:%d\n",i+1,thing[i].name,thing[i].type,thing[i].date,thing[i].month,thing[i].year,thing[i].time,thing[i].lineNum);
    }
    removeLine("upcoming.md",thing[1].lineNum);
    return 0;
  
}



    
//========================================OLD REMAINING TIME FUNCTION===================================================================>
//======================================================================================================================================>
// int remainingTime(upcoming *obj, int day, int month){

//     int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//     for (int i = 0; i < 3; i++)
//     {
//         if (obj[i].date>day && obj[i].month>month)
//         {
//             obj[i].time=(obj[i].month-month)*days[obj[i].month]+(obj[i].date-day)+1;
//         }
//         else if (obj[i].date<day && obj[i].month>month)
//         {
//             obj[i].time=(obj[i].month-month)*days[obj[i].month]+days[month]+(obj[i].date-day)+1;
//         }
//         else if (obj[i].date>day){

//             obj[i].time=obj[i].date-day;
//         }
        
        
//     }
    
// }

