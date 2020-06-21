//
//  main.c
//  UCL_Dynamic_Memory
//
//  Created by Andrej on 24/02/2020.
//  Copyright © 2020 Andrej. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELENGTH 255

struct my_user {
    char name[NAMELENGTH];
    int user_id;
    int * friends;
    int friends_num;
    struct my_user * next_user;
};

void linked_list_loop(void);
struct my_user * insert_user (struct my_user * one_user, struct my_user * head);
struct my_user * remove_user (int remove_id, struct my_user * head);
void add_relationship (int u1, int u2, struct my_user * head);
int user_search (int user_count, struct my_user * head);
char * user_lookup (int id, struct my_user * head);
void user_info (struct my_user * original_head, struct my_user * head, int user_id);
void all_user_info (struct my_user * head);
void write_to_file (struct my_user * head);
struct my_user * read_from_file (struct my_user * old_head);


struct tree_user {
    char name[NAMELENGTH];
    int user_id;
    int * friends;
    int friends_num;
    struct tree_user * left;
    struct tree_user * right;
};

void binary_tree_loop(void);
struct tree_user * binary_tree_insert(struct tree_user * head, struct tree_user * one_user);
void binary_tree_traverse(struct tree_user * head);


int main(int argc, const char * argv[])
{
    printf("--Welcome--\n");
    if (argc > 1) //Check if any arguments were passed on
    {
        for(int i=1 ; i < argc ; i++)
        {
            if (strstr(argv[i], "binary") != NULL || strstr(argv[i], "tree") != NULL)
            {
                binary_tree_loop();
                return 0;
            }
            else if (strstr(argv[i], "linked") != NULL || strstr(argv[i], "list") != NULL)
            {
                linked_list_loop();
                return 0;
            }
        }
    }
    printf("No arguments were specified. ");
    int option;
    while (1) {
        printf("\nPlease choose an option:\n1) Linked list\n2) Binary tree\n3) Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                linked_list_loop();
                break;
            case 2:
                binary_tree_loop();
                break;
            case 3:
                return 0;
            default:
                break;
        }
    }
}

void linked_list_loop(void)
{
    printf("Linked List structure is used\n");
    int option, user_count = 0, active_users = 0; //TODO: !! user count loading
    struct my_user * head = NULL;
    while(1)
    {
        printf("\nChoose option:\n1) Introduce user\n2) Introduce relationship/friendship\n3) Remove user\n4) Print user information\n5) Print report for all users\n6) Save to file\n7) Retrieve data from file\n8) Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
            {
                //create user
                struct my_user * one_user = (struct my_user *)malloc(sizeof(struct my_user));
                printf("Enter name:\n");
                scanf("%s", one_user -> name);
                one_user -> user_id = user_count;
                one_user -> friends_num = 0;
                user_count++;
                active_users++;
                if (head == NULL)
                {
                    one_user -> next_user = NULL;
                    head = one_user;
                }
                else
                    head = insert_user(one_user, head);
            }
                break;
            case 2:
            {
                //relationship/friendship
                printf("--First user--\n");
                int u1 = user_search(user_count, head);
                printf("--Second user--\n");
                int u2 = user_search(user_count, head);
                if (u1 != -1 && u2 != -1)
                {
                    add_relationship(u1, u2, head);
                    add_relationship(u2, u1, head);
                    printf("--Relationship added--\n");
                }
            }
                break;
            case 3:
            {
                //remove user
                int search_result = user_search(user_count, head);
                if (search_result != -1)
                {
                    head = remove_user(search_result, head);
                    printf("--User has been removed--\n");
                    active_users--;
                }
            }
                break;
            case 4:
            {
                //print user information
                int search_result = user_search(user_count, head);
                if (search_result != -1)
                    user_info(head, head, 0);
            }
                break;
            case 5:
            {
                //print info about all users
                printf("Active users: %d\n", active_users);
                all_user_info(head);
            }
                break;
            case 6:
            {
                //save to file
                write_to_file(head);
            }
                break;
            case 7:
            {
                //retrieve from file
                head = read_from_file(head);
            }
                break;
            case 8:
                //exit
                return;
            default:
                break;
        }
    }
}

struct my_user * insert_user (struct my_user * one_user, struct my_user * head)
{
    if (strcmp(one_user -> name, head -> name) < 0)
    {
        //insert before
        one_user -> next_user = head;
        return one_user;
    }
    else if (head -> next_user == NULL)
    {
        //insert after
        one_user -> next_user = NULL;
        head -> next_user = one_user;
        return head;
    }
    else
    {
        head -> next_user = insert_user(one_user, head -> next_user);
        return head;
    }
}

void add_relationship (int user1, int user2, struct my_user * head)
{
    while (head != NULL)
    {
        if (head -> user_id == user1)
        {
            if (head -> friends_num == 0)
            {
                head -> friends = (int *)malloc(sizeof(int));
            }
            else
            {
                 head -> friends = (int *)realloc(head -> friends, sizeof(head -> friends) + sizeof(int));
            }
            head -> friends[head -> friends_num] = user2;
            head -> friends_num++;
            return;
        }
        head = head -> next_user;
    }
}

struct my_user * remove_user (int remove_id, struct my_user * head) //removes the user
{
    if (head == NULL)
    {
        printf("[ERROR] --Failed to remove user--\n");
        return NULL;
    }
    if (remove_id == head -> user_id)
    {
        return head -> next_user;
    }
    else
    {
        head -> next_user = remove_user(remove_id, head -> next_user);
        return head;
    }
}

void all_user_info (struct my_user * head) //report on all users
{
    printf("--Report for all users--\n");
    struct my_user * original_head = head;
    while (head != NULL)
    {
        user_info(original_head, head, head -> user_id);
        head = head -> next_user;
    }
}

void user_info (struct my_user * original_head, struct my_user * head, int user_id) //report on one user
{
    while (head -> user_id != user_id)
    {
        if (head == NULL)
        {
            printf("[ERROR] --No user with such id-- \n");
            return;
        }
        head = head -> next_user;
    }
    printf("%d\t%s", head -> user_id, head -> name);
    if (head -> friends_num != 0)
    {
        printf(", friends:\n");
        for (int i = 0; i < head -> friends_num; i++)
        {
            printf("\t   %s\n", user_lookup(head -> friends[i], original_head));
        }
    }
    else
        printf("\n");
}

char * user_lookup (int id, struct my_user * head) //returns the name, takes in user's id
{
    while (head != NULL)
    {
        if (head -> user_id == id)
            return head -> name;
        head = head -> next_user;
    }
    return "[ERROR] User lookup failed";
}

int user_search (int user_count, struct my_user * head) //returns the id, takes in user's name
{
    char name_in[NAMELENGTH];
    int out, num_in;
    int * matches = (int *)malloc(user_count * sizeof(int));
    int matches_count = 0;
    struct my_user * temp_head = head;

    printf("Enter the name:\n");
    scanf("%s", name_in);
    while (temp_head != NULL) //searches for matching names and stores their ids in matches[]
    {
        if (!strcmp(temp_head -> name, name_in))
        {
            matches[matches_count] = temp_head -> user_id;
            matches_count++;
        }
        temp_head = temp_head -> next_user;
    }
    if (matches_count > 1) //multiple users with the same name
    {
        printf("Found %d matches for \"%s\" with user ids:\n", matches_count, name_in);
        for (int i = 0; i < matches_count; i++)
        {
            printf("%d\n", matches[i]);
        }
        printf("Choose user id:\n");
        scanf("%d", &num_in);
        for (int i = 0; i < matches_count; i++) //validation of input
        {
            if (matches[i] == num_in) //user exists
            {
                out = matches[i];
                free(matches);
                free(temp_head);
                return out;
            }
        }
        printf("[ERROR] --Wrong user id--\n"); //input invalid
        matches[0] = -1;
    }
    else if (matches_count == 0)
    {
        printf("--No users found--\n");
        matches[0] = -1;
    }
    out = matches[0];
    free(matches);
    free(temp_head);
    return out;
}

void write_to_file (struct my_user * head)
{
    FILE * file= fopen("output_ll", "wb");
    if (file != NULL)
    {
        while (head != NULL)
        {
            fwrite(head, sizeof(struct my_user), 1, file);
            head = head -> next_user;
        }
        fclose(file);
        printf("--Write successful--\n");
    }
    else
    {
        printf("[ERROR] --Failed to open file--\n");
    }
}

struct my_user * read_from_file (struct my_user * old_head)
{
    struct my_user * head = (struct my_user *)malloc(sizeof(struct my_user));
    struct my_user * original_head = (struct my_user *)malloc(sizeof(struct my_user));
    
    FILE * file= fopen("output_ll", "rb");
    if (file != NULL)
    {
        fread(original_head, sizeof(struct my_user), 1, file);
        original_head -> next_user = head;
        while (fread(head, sizeof(struct my_user), 1, file) == 1)
        {
            head = head -> next_user;
        }
        fclose(file);
        free(head);
        printf("--Read successful--\n");
        return original_head;
    }
    else
    {
        printf("[ERROR] --Failed to open file--\n");
        return old_head;
    }
}


void binary_tree_loop(void)
{
    printf("Binary Tree structure is being used\n");
    int option, active_users = 0;
    struct tree_user * head = NULL;
    while (1)
    {
        printf("\nChoose option:\n1) Introduce user\n2) Print all user information\n3) Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
            {
                //insert user
                struct tree_user * one_user = (struct tree_user *)malloc(sizeof(struct tree_user));
                one_user -> left = NULL;
                one_user -> right = NULL;
                one_user -> user_id = active_users;
                printf("Enter name:\n");
                scanf("%s", one_user -> name);
                active_users++;
                head = binary_tree_insert(head, one_user);
            }
                break;
            case 2:
                //traverse tree
                printf("Active users: %d\n", active_users);
                binary_tree_traverse(head);
                break;
            case 3:
                //exit
                return;
            default:
                break;
        }
    }
}

struct tree_user * binary_tree_insert(struct tree_user * head, struct tree_user * one_user)
{
    if (head == NULL)
    {
        head = one_user;
        return head;
    }
    else if (strcmp(one_user -> name, head -> name) < 0)
    {
        head -> left = binary_tree_insert(head -> left, one_user);
        return head;
    }
    else
    {
        head -> right = binary_tree_insert(head -> right, one_user);
        return head;
    }
}

void binary_tree_traverse(struct tree_user * head) //alphabetical order
{
    if (head == NULL)
        return;
    if (head -> left != NULL)
    {
        binary_tree_traverse(head -> left);
    }
    printf("%d\t%s\n", head -> user_id, head -> name);
    if (head -> right != NULL)
    {
        binary_tree_traverse(head -> right);
    }
}
