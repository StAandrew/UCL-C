//
//  main.c
//  UCL_program1
//
//  Created by Andrey Staniukynas on 06/12/2019.
//  Copyright © 2019 Andrey Staniukynas. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void read_line (char*, unsigned long);
bool leap(int);
int days(int, int);
const unsigned long year_lenth = 10; //no limitation for year length specified, left 10 just in case
const int month_length = 2;

int main(int argc, const char * argv[]) {
    while(1)
    {
        char *year = (char*) malloc(year_lenth * sizeof(char));
        char *month = (char*) malloc(month_length * sizeof(char));
        printf("Enter year\n");
        read_line(year, year_lenth);
        printf("Enter month\n");
        read_line(month, month_length);
        int year_val = atoi(year);
        int month_val = atoi(month);
        printf("Year: %d Month: %d\n", year_val, month_val);
        printf("Number of days: %d\n", days(year_val, month_val));
        free(year);
        free(month);
    }
    return 0;
}

void read_line (char *value, unsigned long length)
{
    char *buffer;
    unsigned long buffer_size = length;
    unsigned long characters;
    buffer = (char*) malloc(buffer_size * sizeof(char));
    if (buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
    characters = getline(&buffer, &buffer_size, stdin);
    for (int i = 0; i<characters-1; i++)
    {
        if (!(buffer[i] >= 0x30 && buffer[i] <= 0x39))
        {
            perror("Please enter digits only");
            exit(1);
        }
    }
    if (characters-1 > length || *buffer == '\n')
    {
        perror("Wrong date format");
        exit(1);
    }
    for (int i = 0; i < characters-1; i++)
    {
        value[i] = buffer[i];
    }
    free(buffer);
}

int days (int year, int month)
{
    if (year <= 0){
        perror("Year must be more than 0");
        exit(1);
    }
    switch (month) {
        case 2:
            if(leap(year))
                return 29;
            else
                return 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        default:
            perror("Invalid month");
            exit(1);
            break;
    }
    return 0;
}

bool leap (int year)
{
    if (year%4 == 0 && year%100 != 0)
        return 1;
    else if (year%100 == 0)
        if (year%400 == 0)
            return 1;
        else
            return 0;
    else
        return 0;
}
