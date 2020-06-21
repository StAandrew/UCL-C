//
//  main.c
//  UCL_Matrices_with_poiners
//
//  Created by Andrej on 04/02/2020.
//  Copyright © 2020 Andrej. All rights reserved.
//

#include <stdio.h>
const int max_size = 5;

void input_matrix(int m[], int c, int r);
void display_matrix(int m[], int c, int r);
void add_matrices(int m1[], int m2[], int m3[], int k);

int main(int argc, const char * argv[]) {
    int m1[max_size][max_size], m2[max_size][max_size], m3[max_size][max_size];
    int rows, columns;
    printf("Enter number of columns\n");
    scanf("%d", &columns);
    printf("Enter number of rows\n");
    scanf("%d", &rows);
    printf("Matrix 1\n");
    input_matrix(m1, columns, rows);
    printf("Matrix 2\n");
    input_matrix(m2, columns, rows);
    add_matrices(m1, m2, m3, rows*columns);
    printf("Resultant matrix:\n");
    display_matrix(m3, columns, rows);
    return 0;
}
void input_matrix(int m[], int c, int r)
{
    for(int i=1, k=0; i<=r; i++)
    {
        for(int j=1; j<=c; j++, k++)
        {
            printf("Enter number on position %d,%d\n", i, j);
            scanf("%d", &m[k]);
        }
    }
}

void display_matrix(int m[], int c, int r)
{
    printf("Matrix:\n");
    for(int i=1, k=0; i<=r; i++)
    {
        for(int j=1; j<=c; j++, k++)
        {
            printf("%d ", m[k]);
        }
        printf("\n");
    }
    printf("\n");
}

void add_matrices(int m1[], int m2[], int m3[], int k)
{
    for(int i=0; i<k; i++)
    {
        m3[i] = m1[i] + m2[i];
    }
}
