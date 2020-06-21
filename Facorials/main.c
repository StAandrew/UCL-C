//
//  main.c
//  UCL_Factorial
//
//  Created by Andrej on 20/01/2020.
//  Copyright © 2020 Andrej. All rights reserved.
//

#include <stdio.h>
unsigned long factorial (int);

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);
    printf("Factorial of %d is %lu\n", n, factorial(n));
    return 0;
}

unsigned long factorial (int input)
{
    int result = 1;
    for (int i=1; i<=input; i++)
    {
        result *= i;
    }
    return result;
}
