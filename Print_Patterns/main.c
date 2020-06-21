//
//  main.c
//  UCL_lab_sesion1
//
//  Created by Andrej on 13/01/2020.
//  Copyright © 2020 Andrej. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num;
    do
    {
        printf("Enter number\n");
        scanf("%d", &num);
        for (int i=0, j=num; i<num; i++, j--)
        {
            for (int space=0; space<j-1; space++)
            {
                printf(" ");
            }
            for (int star=0; star<2*i+1; star++)
            {
                printf("*");
            }
            for (int space=0; space<j-1; space++)
            {
                printf(" ");
            }
            printf("\n");
        }
        for (int i=1, j=num-2; i<num; i++, j--)
        {
            for (int space=0; space<i; space++)
            {
                printf(" ");
            }
            for (int star=0; star<2*j+1; star++)
            {
                printf("*");
            }
            for (int space=0; space<i; space++)
            {
                printf(" ");
            }
            printf("\n");
        }
    } while (num > 0);
    return 0;
}
