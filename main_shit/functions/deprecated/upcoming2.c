#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INT_LINE_SIZE 1024

typedef struct upcoming {
    char name[50];
    char type[50];
    int date;
    int month;
    int year;
    int time;
} upcoming;

int isLeapYear(int year) {
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

int daysInMonth(int month, int year) {
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

int getNumberOfLines(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return -1;
    }
    
    int line_count = 0;
    char buffer[INT_LINE_SIZE];
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        line_count++;
    }
    
    fclose(fp);
    return line_count;
}

int removeLine(const char *filename, int line) {
    FILE *src = fopen(filename, "r");
    FILE *dest = fopen("tempFILE.txt", "w");
    if (src == NULL || dest == NULL) {
        perror("Failed to open file");
        return -1;
    }
    
    char buffer[INT_LINE_SIZE];
    int current_line = 1;
    
    while (fgets(buffer, sizeof(buffer), src) != NULL) {
        if (current_line != line) {
            fputs(buffer, dest);
        }
        current_line++;
    }
    
    fclose(src);
    fclose(dest);
    
    remove(filename);
    rename("tempFILE.txt", filename);
    
    return 0;
}

void calculateRemainingTime(upcoming *obj, int day, int month, int year, int nums) {
    for (int i = 0; i < nums; i++) {
        int eventDay = obj[i].date;
        int eventMonth = obj[i].month;
        int eventYear = obj[i].year;
        
        if (eventYear > year || (eventYear == year && (eventMonth > month || (eventMonth == month && eventDay > day)))) {
            if (eventYear == year && eventMonth == month) {
                obj[i].time = eventDay - day;
            } else {
                int daysRemaining = 0;

                if (eventYear == year) {
                    daysRemaining = daysInMonth(month, year) - day;
                    for (int m = month + 1; m < eventMonth; m++) {
                        daysRemaining += daysInMonth(m, year);
                    }
                    daysRemaining += eventDay;
                } else {
                    daysRemaining = daysInMonth(month, year) - day;
                    for (int m = month + 1; m <= 12; m++) {
                        daysRemaining += daysInMonth(m, year);
                    }
                    for (int m = 1; m < eventMonth; m++) {
                        daysRemaining += daysInMonth(m, eventYear);
                    }
                    daysRemaining += eventDay;
                }
                obj[i].time = daysRemaining;
            }
        } else {
            removeLine("upcoming.md", i + 1);
            for (int j = i; j < nums - 1; j++) {
                obj[j] = obj[j + 1];
            }
            nums--;
            i--;
        }
    }
}

void bsort(upcoming *obj, int n) {
    int swaps;
    for (int i = 0; i < n - 1; i++) {
        swaps = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (obj[j].time > obj[j + 1].time) {
                upcoming temp = obj[j];
                obj[j] = obj[j + 1];
                obj[j + 1] = temp;
                swaps++;
            }
        }
        if (!swaps) {
            break;
        }
    }
}

int getTasks(upcoming *obj) {
    int num = getNumberOfLines("upcoming.md");
    if (num <= 0) {
        return num;
    }

    FILE *fp = fopen("upcoming.md", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return -1;
    }

    char read[INT_LINE_SIZE];
    char dat[num][5][50];

    for (int i = 0; i < num; i++) {
        fgets(read, sizeof(read), fp);
        read[strlen(read) - 1] = '\0';
        char *tok = strtok(read, "|");
        for (int j = 0; j < 5; j++) {
            strcpy(dat[i][j], tok);
            tok = strtok(NULL, "|");
        }
        strcpy(obj[i].name, dat[i][0]);
        strcpy(obj[i].type, dat[i][1]);
        obj[i].date = atoi(dat[i][2]);
        obj[i].month = atoi(dat[i][3]);
        obj[i].year = atoi(dat[i][4]);
    }
    fclose(fp);

    time_t current_time;
    struct tm *time_info;

    current_time = time(NULL);
    time_info = localtime(&current_time);
    if (time_info == NULL) {
        perror("localtime");
        return 1;
    }

    int day = time_info->tm_mday;
    int month = time_info->tm_mon + 1;
    int year = time_info->tm_year + 1900;

    calculateRemainingTime(obj, day, month, year, num);
    bsort(obj, num);

    return num;
}

int main() {
    int num = getNumberOfLines("upcoming.md");
    if (num <= 0) {
        printf("No events found.\n");
        return 0;
    }

    upcoming events[num];
    int ret = getTasks(events);

    if (ret <= 0) {
        printf("No valid tasks retrieved.\n");
        return 0;
    }

    for (int i = 0; i < ret; i++) {
        printf("Event %d: Name: %s, Type: %s, Date: %d-%d-%d, Remaining Time: %d days\n",
               i + 1, events[i].name, events[i].type, events[i].date, events[i].month, events[i].year, events[i].time);
    }

    return 0;
}
