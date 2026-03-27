#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "..//Administration_Dashboard/admin.h"
int Year, Month, Day;
int i;
int university_student;
int pos = -1; // ayto shmainei oti to port_code hasn't been found,
              // opoiodhpote allo number antistoixei se ena apo ta ports,f.e pos=4, "Patmos"

void book_trip(Book booking, const Route ports[], int ports_count)
{
    int Year, Month, Day;
    int i;
    int initial_cost = 0;
    int return_cost = 0;
    int final_cost = 0;
    int total_cost = 0;
    int add_cost = 0;
    printf("\nPlease enter your departure date(Year Month Day):\n");
    printf("Year: \n");
    scanf("%d", &booking.start_date.yyyy); // date of departure(year)
    printf("Month: \n");
    scanf("%d", &booking.start_date.mm); // date of departure(month)
    printf("Day: \n");
    scanf("%d", &booking.start_date.dd); // date of departure(day)

    char port_code[4];
    printf("Please enter your destination due to the port code:\t");
    scanf("%s", port_code);                    // Route.port_code , &p
    if (strcmp(port_code, ports[i].port_code)) // checking if the client's port code corresponds to one of the 13 port codes
        pos = i;
    {
        int select;
        int decision;
        int offer;
        int select_car;
        printf("Please enter your seat type:\n"); // prints the available seat types in order to choose one of them
        printf("1)Deck\n2)Airplane\n3)Cabin\n");
        scanf("%d", &select);
        printf("Would you like to transfer a car as well?\n");
        printf("If so then please press 1, otherwise 0.\n");
        scanf("%d", &select_car); // client decides if they want to tranfer their car
        if (select_car == 1)      // they want to transer it
        {
            add_cost = 100; // additional fee for the car
            // in every scenario add_fee=100 euros except for Kastelorizo and Symi
            //  for which the add_fee is 20 euros more expensive

            if ((strcmp(port_code, "KST")) || (strcmp(port_code, "SYM"))) // if they have selected Kastelorizo or Symi
            {
                add_cost = 120; // they are charged 120 euros for their car tranfer
            }
            printf("Would you like to return also?\n");
            printf("(1)Yes , (2)No");
            scanf("%d", &decision); // clients decide if they want a one-way or a return trip
            switch (decision)
            {
            case 1: // requests a return-trip
                printf("Please enter your date of return(Year Month Day): \n");
                printf("Year: \n");
                scanf("%d", &booking.return_date.yyyy); // date of return(year)
                printf("Month: \n");
                scanf("%d", &booking.return_date.mm); // date of return(month)
                printf("Day: \n");
                scanf("%d", &booking.return_date.dd); // date of return(day)

                switch (select)
                {
                case 1:                                             // client has selected deck
                    initial_cost = ports[pos].deck_cost + add_cost; // initial cost trip for deck choice
                    return_cost = 0.75 * (initial_cost);
                    total_cost = initial_cost + return_cost;
                    break;
                case 2:                                                     // client has selected airplane seat
                    initial_cost = ports[pos].airplaneseat_cost + add_cost; // initial cost trip for airplane seat choice
                    return_cost = 0.75 * (initial_cost);
                    total_cost = initial_cost + return_cost;
                    break;
                case 3:                                              // client has selected the cabin
                    initial_cost = ports[pos].cabin_cost + add_cost; // initial cost trip for cabin choice
                    return_cost = 0.75 * (initial_cost);
                    total_cost = initial_cost + return_cost;
                    break;
                default: // client hasn't entered a valid seat type
                    printf("Please enter a valid seat type.\n");
                    break;
                }
            case 2: // requests a one-way trip

                switch (select)
                {
                case 1: // client has selected deck
                    return_cost = 0;
                    initial_cost = ports[pos].deck_cost + add_cost; // initial cost trip for deck choice
                    total_cost = initial_cost;                      // it's one-way, so the total cost=initial cost
                    break;
                case 2:
                    return_cost = 0;                                        // client has selected airplane seat
                    initial_cost = ports[pos].airplaneseat_cost + add_cost; // initial cost trip for airplane seat choice
                    total_cost = initial_cost;
                    break;
                case 3:
                    return_cost = 0;                                 // client has selected the cabin
                    initial_cost = ports[pos].cabin_cost + add_cost; // initial cost trip for cabin choice
                    total_cost = initial_cost;
                    break;
                default: // client hasn't entered a valid seat type
                    printf("Please enter a valid seat type.\n");
                    break;
                }
            default: // client hasn't choosen between a one-way or a return trip
                printf("Invalid answer, please try again.\n");
            }
        }
        else if (select_car == 0)
        { // client doesn't want to transfer a car
            switch (decision)
            {
            case 1: // wants to return
                switch (select)
                {
                case 1:
                    add_cost = 0;
                    initial_cost = ports[pos].deck_cost;
                    return_cost = (initial_cost) * 0, 75;
                    total_cost = initial_cost + return_cost;
                    break;
                case 2:
                    add_cost = 0;
                    initial_cost = ports[pos].airplaneseat_cost;
                    return_cost = (initial_cost) * 0, 75;
                    total_cost = initial_cost + return_cost;
                    break;
                case 3:
                    add_cost = 0;
                    initial_cost = ports[pos].cabin_cost;
                    return_cost = (initial_cost) * 0, 75;
                    total_cost = initial_cost + return_cost;
                    break;
                default:
                    printf("Please enter a valid seat type.\n");
                    break;
                }
            case 2: // doesn't want to return
                switch (select)
                {
                case 1:
                    add_cost = 0;
                    return_cost = 0;
                    initial_cost = ports[pos].deck_cost;
                    total_cost = initial_cost;
                    break;
                case 2:
                    add_cost = 0;
                    return_cost = 0;
                    initial_cost = ports[pos].airplaneseat_cost;
                    total_cost = initial_cost;
                    break;
                case 3:
                    add_cost = 0;
                    return_cost = 0;
                    initial_cost = ports[pos].cabin_cost;
                    total_cost = initial_cost;
                    break;
                default:
                    printf("Please enter a valid seat type.\n");
                    break;
                }
            default:
                printf("Invalid answer, please try again.\n");
                break;
            }
        }
    }

    if ((arrayUsers[i].university_student) == 1)
    {
        total_cost = (total_cost) / 2;
        printf("Your total cost of the whole trip ,as a university student, is %d .\n", total_cost);
    }
    else
    {
        printf("Your total cost of the whole trip is %d. \n", total_cost);
    }
}
