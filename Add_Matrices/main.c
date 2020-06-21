//
//  main.c
//  UCL_add_matrices
//
//  Created by Andrej on 27/01/2020.
//  Copyright © 2020 Andrej. All rights reserved.
//

#include <stdio.h>
const int str_len = 100;
const int max_matrix = 5;
void add_matrices(int m1[max_matrix][max_matrix], int m2[max_matrix][max_matrix], int destination_matrix[max_matrix][max_matrix], int n_rows, int n_columns);
int my_strcmp(char str1[str_len], char str2[str_len]);
void my_strcpy(char str1[str_len], char str2[str_len]);

int main(int argc, const char * argv[])
{
    char s1[str_len];
    char s2[str_len];
    int rows, columns, option, m1[max_matrix][max_matrix], m2[max_matrix][max_matrix], m3[max_matrix][max_matrix];
    while (1) {
        printf("1.Copy strings\n2.Compare strings\n3.Sum of 2 matrices\n4.Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter s1\n");
                scanf("%s", s1);
                printf("Enter s2\n");
                scanf("%s", s2);
                my_strcpy(s1, s2);
                printf("s1 is %s\n", s1);
                printf("s2 is %s\n\n", s2);
                
                break;
            case 2:
                printf("Enter s1\n");
                scanf("%s", s1);
                printf("Enter s2\n");
                scanf("%s", s2);
                int cmp_result = my_strcmp(s1, s2);
                if(!cmp_result)
                    printf("The strings are identical\n\n");
                else
                    printf("The strings are different by %d ASCII characters\n\n", cmp_result);
                break;
            case 3:
                printf("Enter number of columns\n");
                scanf("%d", &columns);
                printf("Enter number of rows\n");
                scanf("%d", &rows);
                printf("Matrix 1\n");
                for (int i = 0; i<columns; i++)
                {
                    for (int j = 0; j<rows; j++)
                    {
                        printf("Enter number on position %d,%d\n", i, j);
                        scanf("%d", &m1[i][j]);
                    }
                }
                printf("Matrix 2\n");
                for (int i = 0; i<columns; i++)
                {
                    for (int j = 0; j<rows; j++)
                    {
                        printf("Enter number on position %d,%d\n", i, j);
                        scanf("%d", &m2[i][j]);
                    }
                }
                add_matrices(m1, m2, m3, rows, columns);
                printf("\nFirst matrix is:\n");
                for (int i = 0; i<columns; i++)
                {
                    for (int j = 0; j<rows; j++)
                    {
                        printf("%d ", m1[i][j]);
                    }
                    printf("\n");
                }
                printf("\nSecond matrix is:\n");
                for (int i = 0; i<columns; i++)
                {
                    for (int j = 0; j<rows; j++)
                    {
                        printf("%d ", m2[i][j]);
                    }
                    printf("\n");
                }
                printf("\nResulting matrix is:\n");
                for (int i = 0; i<columns; i++)
                {
                    for (int j = 0; j<rows; j++)
                    {
                        printf("%d ", m3[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
                break;
            case 4:
                return 0;
                break;
            default:
                break;
        }
    }
}

void add_matrices(int m1[max_matrix][max_matrix], int m2[max_matrix][max_matrix], int destination_matrix[max_matrix][max_matrix], int n_rows, int n_columns)
{
    for (int i = 0; i<n_columns; i++)
    {
        for (int j = 0; j<n_rows; j++)
        {
            destination_matrix[i][j] = m1[i][j] + m2[i][j];
        }
    }
}


int my_strcmp(char str1[str_len], char str2[str_len])
{
    int i;
    for(i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i] && str1[i+1] == '\0' && str2[i+1] == '\0')
            return str2[i] - str1[i];
        else if (str1[i] != str2[i] && str1[i+1] == '\0')
            return -1;
        else if (str1[i] != str2[i] && str2[i+1] == '\0')
            return 1;
    }
    return 0;
}

void my_strcpy(char str1[str_len], char str2[str_len])
{
    int i;
    for(i=0; str1[i] != '\0'; i++)
    {
        str2[i] = str1[i];
    }
    for(; str2[i] != '\0'; i++)
    {
        str2[i] = '\0';
    }
}
