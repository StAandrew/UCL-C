//
//  main.c
//  UCL_Calculator
//
//  Created by Andrej on 20/01/2020.
//  Copyright © 2020 Andrej. All rights reserved.
//

#include <stdio.h>

double average(double, double, double);
double pi(long);
long square_root(long);

int main(int argc, const char * argv[]) {
    int option;
    double one, two, three;
    long precision, sqrt_input, sqrt_result;
    while (1)
    {
        printf("Options:\n1. Average\n2. Calculate pi\n3. Square square root\n4. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Calculates average of 3 numbers\nEnter 1st number:\n");
                scanf("%lf", &one);
                printf("Enter 2nd number:\n");
                scanf("%lf", &two);
                printf("Enter 3rd number:\n");
                scanf("%lf", &three);
                printf("Average is %.2lf\n\n", average(one, two, three));
                break;
            case 2:
                printf("Input precision\n");
                do
                {
                    scanf("%ld", &precision);
                    if (precision <= 0)
                        printf("Please enter a positive integer\n");
                } while (precision <= 0);
                
                printf("Pi to precision %ld is %1.15lf\n\n", precision, pi(precision));
                break;
            case 3:
                printf("Enter input\n");
                do
                {
                    scanf("%ld", &sqrt_input);
                    if (sqrt_input <= 0)
                        printf("Please enter a positive integer\n");
                } while (sqrt_input <= 0);
                
                sqrt_result = square_root(sqrt_input);
                if (sqrt_result != -1)
                    printf("Square root of %ld is %ld\n\n", sqrt_input, sqrt_result);
                else
                    printf("Square root is not an integer\n\n");
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Please choose an option\n");
                break;
        }
    }
}

double average(double one, double two, double three)
{
    return (one+two+three)/3.0;
}

double pi(long input)
{
    double denominator = 1.0, component, result = 0.0;
    for(int i = 1; i <= input; i++)
    {
        component = 4/denominator;
        if(i%2 != 0)
        {
            result = result + component;
        }
        else
        {
            result = result - component;
        }
        denominator += 2;
    }
    return result;
}

long square_root(long input)
{
    long square_i = 0;
    for (long i=1; square_i <= input; i++)
    {
        square_i = i*i;
        if(square_i == input)
        {
            return i;
        }
    }
    return -1;
}
