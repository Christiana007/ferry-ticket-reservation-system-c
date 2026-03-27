#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "..//Administration_Dashboard/admin.h"

int check_login(char *username, char *password)
{
    int res; // result of function check login after checking the user if they are admin or client
    if (strcmp(username, "admin") == 0 && (strcmp(password, "admin123") == 0))
    {
        printf("Welcome!You have succesfully logged in as an admin. \n"); // admin logged in
        res = 0;
        return res; // returns 0 to main
    }
    else if (strcmp(username, "admin") != 0 || (strcmp(password, "admin123") != 0))
    {
        printf("Welcome!You have succesfully logged in as a user. \n"); // user logged in
        res = 1;
        return res; // returns 1 to main
    }
    else
    {
        res = -1;   // when user's username and password do not match his registered profile
        return res; // returns -1 to main
    }
}
