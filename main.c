#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Client_Dashboard/client.h"
#include "Administration_Dashboard/admin.h"
#define MAX_USERS 30

int attempts = 0;
char username[25];
char password[8];
int user_counter;
int main()
{
    int i;
    int attempts = 0;
    int choice;
    int user_choice;
    int res;
    printf("Welcome to our shipping company!\n");
    printf("DS-Ferries is now ready to satisfy your needs.\n");
    printf("Please press: (1)Login , (2)Exit \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1: // user has selected to log in, choice (1)

        printf("You have selected to login.\n");
        printf("Please enter your username:\n");
        scanf("%s", username);
        printf("Please enter your password:\n");
        scanf("%s", password);
        int res = check_login(username, password); // calls check_login func and passes it to res
        if (res == 0)                              // user has logged in as admin
        {
            int admin_choice;
            printf("Please enter your next move.\n");
            printf("Please press: (1)Register new client , (2)Change client's password.\n ");
            scanf("%d", &admin_choice);
            switch (admin_choice)
            {
            case 1:                                           // admin registers a new client
                create_new_client(arrayUsers, &user_counter); // calls create_new_client and registers new client
                break;
            case 2: // admin changes client's password
                change_client_password(arrayUsers, &user_counter, username);
            default:
                break;
            }
        }
        else if (res == -1)
        {               // wrong input by user
            attempts++; // unsuccesfull attempts
            printf("User's personal details are false!Either your username or password is wrong.\n");
        }
        else
        {
            client_login(*username, *password);
            printf("Please press: (1)View available routes, (2)Book your next trip, (3)Log out \n");
            scanf("%s", &user_choice);
            switch (user_choice)
            {
            case 1:
                view_routes(ports[], i);
                break;
            case 2:
                book_trip(booking, ports[13], ports_count);
                break;
            case 3:
                printf("You have selected to log out.\n");
                // calls log_out function
                break;
            default:
                printf("False entry!Please try again!\n");
                break;
            }
        }
        break;
    case 2: // user has selected to exit, choice (2)
        printf("You have selected to exit.\n");
        break;
    default:
        printf("Invalid entry!Please try again.\n"); // ο χρηστης παταει κατι διαφορετικο αντι για 1 συνδεση ή 2 εξιτ
        system("cls");
    }
}
