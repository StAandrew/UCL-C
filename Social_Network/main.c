//
//  main.c
//  UCL_social_network
//
//  Created by Andrej on 27/01/2020.
//  Copyright © 2020 Andrej. All rights reserved.
//

#include <stdio.h>
const int name_len = 40;
int my_strcmp(char s1[name_len], char s2[name_len]);
struct one_user
{
    char name[name_len];
    int user_number;
    int friends[200];
    int friend_number;
};

int main(int argc, const char * argv[]) {
    int option, user_count = 0, user1_id, user2_id;
    char user1[name_len], user2[name_len];
    struct one_user database[200];
    while (1) {
        printf("Choose action:\n1.Add user\n2.Add social relationship\n3.Print report of all users\n4.Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter name:\n");
                scanf("%s", database[user_count].name);
                database[user_count].friend_number = 0;
                database[user_count].user_number = user_count;
                user_count++;
                break;
            case 2:
                printf("Enter first name:\n");
                scanf("%s", user1);
                printf("Enter second name:\n");
                scanf("%s", user2);
                user1_id = -1;
                user2_id = -1;
                for (int i = 0; i < user_count; i++)
                {
                    if(my_strcmp(user1, database[i].name))
                    {
                        user1_id = i;
                    }
                    if(my_strcmp(user2, database[i].name))
                    {
                        user2_id = i;
                    }
                }
                if (user1_id != -1 && user2_id != -1)
                {
                    database[user1_id].friends[database[user1_id].friend_number] = user2_id;
                    database[user1_id].friend_number++;
                    database[user2_id].friends[database[user2_id].friend_number] = user1_id;
                    database[user2_id].friend_number++;
                    printf("Social relationship was added\n\n");
                }
                else
                    printf("No such users were found\n\n");
                break;
            case 3:
                for (int i = 0; i < user_count; i++)
                {
                    printf("Name: %s\n", database[i].name);
                    printf("User number: %d\n", database[i].user_number);
                    printf("Friends (%d): \n", database[i].friend_number);
                    if (database[i].friend_number == 0)
                        printf("None");
                    else
                        for (int j = 0; j < database[i].friend_number; j++)
                        {
                            printf("%s\n", database[database[i].friends[j]].name);
                        }
                    printf("\n");
                }
                break;
            case 4:
                return 0;
                break;
            default:
                break;
        }
    }
}

int my_strcmp(char s1[name_len], char s2[name_len])
{
    int i;
    for(i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] != s2[i])
            return 0;
    }
    for(; s2[i] != '\0'; i++)
    {
        if (s2[i] != '\0')
            return 0;
    }
    return 1;
}
