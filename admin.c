#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#define MAX_USERS 30

int user_counter = 0;

void create_new_client(User arrayUsers[MAX_USERS], int *user_counter)
{
    int uni_answer;
    char temp_user[25];
    if (*user_counter < MAX_USERS)
    {
        do
        {
            printf("Enter your age:(you must be older than 18.\n");
            scanf("%d", &arrayUsers[*user_counter].age);
            if (arrayUsers[*user_counter].age < 18)
            {
                printf("You must be at least 18 years old in order to be able to register. \n");
            }
        } while (arrayUsers[*user_counter].age < 18);

        printf("Enter your name:\n");
        scanf("%s", arrayUsers[*user_counter].name);
        printf("Enter your surname:\n");
        scanf("%s", arrayUsers[*user_counter].surname);
        printf("Enter your card number:\n");
        scanf("%s", arrayUsers[*user_counter].card_number);
        printf("Are you a university student? (1)Yes , (2)No \n"); // checking if the new client is a uni student
        scanf("%d", &uni_answer);
        switch (uni_answer)
        {
        case 1: // is a uni student
            printf("Great!You are indeed a university student.\n");
            arrayUsers[*user_counter].university_student = 1; // takes 1
            break;
        case 2: // isn't a uni student
            printf("You are not a university student.\n");
            arrayUsers[*user_counter].university_student = 0; // takes 0
            break;
        default:
            printf("Wrong input!Please try again.\n"); // user didn't choose either (1) or (2), different input
                                                       // prepei na to emfanizei pali kai na janavazei iput sto age
            break;
        }
        printf("Enter your username:\n");
        scanf("%s", temp_user);                                               // temp_user is the username that the new client requests for using
        int existion = username_exists(arrayUsers, *user_counter, temp_user); // checking if the new client's username
                                                                              //  is already used by another client-user
        if (existion != 1)                                                    // if temp_user differs from all the others(existing usernames)
        {
            printf("Enter your password:\n"); // then asks for user's password
            scanf("%s", arrayUsers[*user_counter].password);
        }
        (*user_counter)++;
        printf("Registration is now complete!Welcome officially to DS-Ferries!\n");
    }
    else
    {
        printf("The maximum number (30) of registered clients has been reached.\n");
        printf("Unfortunatelly you are not able to be registered anymore. \n");
    }
}

void change_client_password(User arrayUsers[MAX_USERS], int *user_counter, char username[25])
{
    char new_password[8];
    if (arrayUsers[*user_counter].username == username) // if username is valid
    {
        printf("Please enter the new password that you desire. \n"); // enters the new password
        scanf("%s", new_password);
        strcpy(arrayUsers[*user_counter].password, new_password); // change it, the old one now corresponds to a new one
        (*user_counter)++;
    }
    else
    {
        printf("User does not exist!Please try again.\n"); // user hasn't been found to the system
        system("cls");                                     // prepei na janadvsei username valid!
    }
}

void client_login(char *username, char *password)
{
    if (strcmp(arrayUsers[user_counter].username, username))
    {
        if (strcmp(password, arrayUsers[user_counter].password))
        {
            printf("You have succesfully logged in as a client.\n");
        }
        else
        {
            printf("Wrong password, please try again.\n");

            system("cls");
        }
    }
}

int username_exists(User arrayUsers[MAX_USERS], int user_counter, char *temp_user)
{
    int existion;
    if (strcmp(arrayUsers[user_counter].username, temp_user) == 0) // requested username is already being used
    {
        existion = 1;
        printf("This username already exists and it is being used by another client.\n"); // prepei na janadinei
        return existion;
    }
    else
    {
        existion = 0;
        printf("Great choice for username!\n");
        return existion;
    }
}
