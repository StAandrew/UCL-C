//
//  main.c
//  UCL_least_common_multiple
//
//  Created by Andrej on 13/01/2020.
//  Copyright © 2020 Andrej. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b, suma, sumb;
    do
    {
        printf("Enter first number\n");
        scanf("%d", &a);
        printf("Enter second number\n");
        scanf("%d", &b);
        suma = a;
        sumb = b;
        while(suma != sumb)
        {
            //printf("a is %d, b is %d\n", suma, sumb);
            if (suma < sumb)
            {
                suma+=a;
            }
            else
            {
                sumb+=b;
            }
        }
        printf("Lowest common multiple is %d\n\n", suma);
    } while (a>0 && b>0);
    return 0;
}
