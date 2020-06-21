//
//  main.c
//  UCL_Pointers
//
//  Created by Andrej on 03/02/2020.
//  Copyright © 2020 Andrej. All rights reserved.
//

#include <stdio.h>

#define NAME_LEN 40
#define USERS_LEN 200

struct one_user
{
    char name[NAME_LEN];
    int user_number;
    int friends[USERS_LEN];
    int friends_number;
};

int my_strcmp(char s1[NAME_LEN], char s2[NAME_LEN]);
int add_user(struct one_user *u, int *n);
int add_connection(struct one_user u[], int *n);
int print_report(struct one_user u[], int *n);
int add_numbers(int *a, int *b, int *c);
//void test(int a[])
//{
//    a[12] = 10;
//}

int main(int argc, const char * argv[])
{
    int option, a, b, c;
    struct one_user users[NAME_LEN];
    int active_users = 0;
//    int arr[10][10];
//    test(arr);
//    printf("%d\n", arr[1][1]);
    while(1)
    {
        printf("\nChoose action:\n1.Add user\n2.Add social relationship\n3.Print report of all users\n4.Add 2 numbers\n5.Exit\n");
        scanf("%d", &option);
        printf("\n");
        switch (option) {
            case 1:
                add_user(&users[active_users], &active_users);
                break;
            case 2:
                add_connection(users, &active_users);
                break;
            case 3:
                print_report(users, &active_users);
                break;
            case 4:
                printf("Enter first number\n");
                scanf("%d", &a);
                printf("Enter second number\n");
                scanf("%d", &b);
                add_numbers(&a, &b, &c);
                printf("Result is %d\n", c);
                break;
            case 5:
                return 0;
            default:
                printf("Please choose a correct option\n");
                break;
        }
    }
}

int add_user(struct one_user *u, int *n)
{
    printf("Enter name\n");
    scanf("%s", u->name);
    u->user_number = *n;
    u->friends_number = 0;
    *n += 1;
    return 0;
}

int add_connection(struct one_user u[], int *n)
{
    if (*n < 2)
    {
        printf("Please 2 or more users\n");
        return 1;
    }
    char user1_name[NAME_LEN], user2_name[NAME_LEN];
    printf("Enter first name:\n");
    scanf("%s", user1_name);
    printf("Enter second name:\n");
    scanf("%s", user2_name);
    if(!my_strcmp(user1_name, user2_name) && *n <= 1)
    {
        printf("Can't be the same user!\n");
        return 1;
    }
    int user1_ids[*n], u1 = 0, user2_ids[*n], u2 = 0;
    for (int i = 0; i < *n; i++)
    {
        if(!my_strcmp(user1_name, u[i].name))
        {
            user1_ids[u1] = i;
            u1++;
        }
        if(!my_strcmp(user2_name, u[i].name))
        {
            user2_ids[u2] = i;
            u2++;
        }
    }
    if(u1 == 0 || u2 == 0)
    {
        printf("No such users were found\n");
        return 1;
    }
    if(u1 > 1 || u2 > 1)
    {
        int option;
        printf("Dublicate names were found.\n");
        if(u1 > 1)
        {
            printf("Please specify the first user\n\nName:  User ID:\n");
            for (int i = 0; i < u1; i++)
            {
                printf("%d. %s -> %d\n", i+1, u[user1_ids[i]].name, u[user1_ids[i]].user_number);
            }
            scanf("%d", &option);
            if (option < 1 || option > u1)
            {
                printf("User %s with id %d was selected\n", u[user1_ids[0]].name, u[user1_ids[0]].user_number);
                option = 1;
            }
            else
            {
                printf("User %s with id %d was selected\n", u[user1_ids[option-1]].name, u[user1_ids[option-1]].user_number);
            }
            user1_ids[0] = user1_ids[option-1];
        }
        if (u2 > 1)
        {
            printf("Please specify the second user\n\nName:  User ID:\n");
            for (int i = 0; i < u2; i++)
            {
                printf("%d. %s -> %d\n", i+1, u[user2_ids[i]].name, u[user2_ids[i]].user_number);
            }
            scanf("%d", &option);
            if (option < 1 || option > u2 || user1_ids[0] == user2_ids[option-1])
            {
                for(int i = 1; i <= u2; i++)
                {
                    if (user1_ids[0] != user2_ids[i-1])
                    {
                        printf("User %s with id %d was selected\n", u[user2_ids[i-1]].name, u[user2_ids[i-1]].user_number);
                        option = i;
                        break;
                    }
                }
            }
            else
            {
                printf("User %s with id %d was selected\n", u[user2_ids[option-1]].name, u[user2_ids[option-1]].user_number);
            }
            user2_ids[0] = user2_ids[option-1];
        }
    }
    u[user1_ids[0]].friends[u[user1_ids[0]].friends_number] = user2_ids[0];
    u[user2_ids[0]].friends[u[user2_ids[0]].friends_number] = user1_ids[0];
    u[user1_ids[0]].friends_number += 1;
    u[user2_ids[0]].friends_number += 1;
    printf("Connection was added\n");
    return 0;
}

int print_report(struct one_user u[], int *n)
{
    if (*n < 1)
    {
        printf("Please add at least 1 user\n");
        return 1;
    }
    for (int i = 0; i < *n; i++)
    {
        printf("Name: %s\n", u[i].name);
        printf(" User number: %d\n", u[i].user_number);
        printf(" Friends (%d): \n", u[i].friends_number);
        if (u[i].friends_number == 0)
            printf(" None");
        else
            for (int j = 0; j < u[i].friends_number; j++)
            {
                printf(" %s\n", u[u[i].friends[j]].name);
            }
        printf("\n");
    }
    return 0;
}

int my_strcmp(char str1[NAME_LEN], char str2[NAME_LEN])
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

void my_strcpy(char str1[NAME_LEN], char str2[NAME_LEN])
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

int add_numbers(int *a, int *b, int *c)
{
    *c = *a + *b;
    return 0;
}
